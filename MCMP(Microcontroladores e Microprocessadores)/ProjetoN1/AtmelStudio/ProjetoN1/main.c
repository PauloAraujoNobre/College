/*
 * GccApplication1.cpp
 *
 * Created: 10/10/2019 12:33:35 PM
 * Author : Paulo Henrique
 */ 

#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>

#define BAUD 9600UL
#define F_CPU 8000000UL
#define MYUBRR ((unsigned long)((F_CPU/(16*BAUD))-1))

#include <util/delay.h>

/* ------------------------------------------- Inicial ----------------------------------------- */

void envia_comando(char comando){
	PORTB = comando;
	PORTC &= ~(0x01);
	PORTC &= ~(0x02);
	PORTC |= (0x04);
	_delay_ms(50);
	PORTC &= ~(0x04);
}

void envia_dado(char dado){
	PORTB = dado;
	PORTC |= (0x01);
	PORTC &= ~(0x02);
	PORTC |= (0x04);
	_delay_ms(50);
	PORTC &= ~(0x04);
	
}

/* -------------------------------------------- SERIAL ----------------------------------------- */

void USART_Init(unsigned int ubrr){ 
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);

	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit(unsigned char data){
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = data;
}

void USART_putstring(char* StringPtr){
	while(*StringPtr != 0){
		USART_Transmit(*StringPtr++);  
	}
}

/* ---------------------------------------- Interrupt ---------------------------------------- */

int num[28];
int i = 0, flag = 1, count = 0;

ISR(TIMER1_OVF_vect)                              //interrupção do TIMER1
{
	TCNT1 = 0xE17B;                                 // Renicia TIMER
	if (flag){
		if((PIND&(1<< 2))){
			USART_putstring("1");
			num[i] = 1;
			i++;
		}
		
		if((PIND&(1<< 2)) == 0){
			USART_putstring("0");
			num[i] = 0;
			i++;
		}
	}
	count++;
	
	if(count==28){
		USART_Transmit(0x0d);
		USART_putstring("Remote RC-05 descodificada:");
		USART_Transmit(0x0d);
		for (int j = 0; j < i-1; j = j+2){
			if (num[j] == 1){
				USART_putstring("0");
			}
			else if (num[j] == 0){
				USART_putstring("1");
			}
		}
		flag = 0;
	}
}

/* --------------------------------------------- LCD ------------------------------------------- */



int main(void){
	DDRD = 0xff;
	
	// Configuração do timer1
	TCCR1A = 0;                        //confira timer para operação normal pinos OC1A e OC1B desconectados
	TCCR1B = 0;                        //limpa registrador
	TCCR1B |= (1<<CS10)|(1 << CS12);   // configura prescaler para 1024: CS12 = 1 e CS10 = 1

	TCNT1 = 0xE17B;                    // incia timer com valor para que estouro ocorra em 1 segundo
	// 65536-(8MHz/1024)
	 
	TIMSK1 |= (1 << TOIE1);           // habilita a interrupção do TIMER1
	sei();
	
	USART_Init(MYUBRR);
    envia_comando(0x80);
	
	USART_putstring("Remote RC-05 codificado:");
	USART_Transmit(0x0d);
	
	while(1){

	}
}

