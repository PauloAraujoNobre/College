#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

void send_instruction(char instruction){
	PORTB = instruction;
	PORTD &= ~(0x04);
	PORTD &= ~(0x02);
	PORTD |= (0x01);
	_delay_ms(10);
	PORTD &= ~(0x01);	
}

void send_data(char dado){
	PORTB = dado;
	PORTD |= (0x04);
	PORTD &= ~(0x02);
	PORTD |= (0x01);
	_delay_ms(10);
	PORTD &= ~(0x01);
	
}

void start_display(){
	send_instruction(0x38);
	_delay_ms(1);
	send_instruction(0x0E);
	_delay_ms(1);
	send_instruction(0x06);
	_delay_ms(1);
	send_instruction(0x01);
	_delay_ms(1);
}

int i;

void send_message(char message[], int start, int end){
	for (i=start; i<end; i++)
	{
		if (i > strlen(message)) {
			send_data(message[i-strlen(message)]);
		} else {
			send_data(message[i]);
		}
	}
}

char time[9] = {'0','0',':','0','0',':','0','0','\0'};
	
	
void restart_time() {
	time[0] = time[1] = time[3] = time[4] = time[6] = time[7] = '0';
}

void update_time(int index) {
	if (index < 0 || index > 7) return;
	if (index == 2 || index == 5) return update_time(index-1);
	time[index]++;
	if (time[0] == '2' && time[1] == '4') return restart_time();
	else if ((index == 1 || index == 4 || index == 7) && time[index] > '9') {
		time[index] = '0';
		update_time(index-1);
	}	
	else if ((index == 3 || index == 6) && time[index] > '5') {
		time[index] = '0';
		update_time(index-1);
	}
}


int main(void)
{
	DDRB = 0xff;
	DDRD = 0x07;
	start_display();
	int count1 = 0;
	int count2 = 0;
	int regula_delay = 2;
	int start = 0;
	int end = 16;
    while (1) 
    {
		send_instruction(0x81);
		char message[19] = " A BEL E O MEU AMOR";
		int tam_message = strlen(message);
		send_message(message, start, end);
		send_instruction(0xc4);
		send_message(time, 0, 8);
		if (start == tam_message) {
			start = 0;
			end = 16;
		}
		count1++;
		count2++;
		if (count2 == 2) {
			count2 = 0;
			start++;
			end++;
		}
		if (count1 > regula_delay) {
			count1 = 0;
			update_time(7);
		}
    }
}
