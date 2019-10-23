/*
 * InterfaceSerial.c
 *
 * Created: 9/30/2019 11:42:52 PM
 * Author : Paulo H
 */ 

#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>

#define BAUD 9600UL
#define F_CPU 8000000UL
#define MYUBRR ((unsigned long)((F_CPU/(16*BAUD))-1))

#include <util/delay.h>

int count = 0;
int flag = 0;
int flag2 = 0;

/* -------------------------------------------- SERIAL ----------------------------------------- */

void USART_Init(unsigned int ubrr){
	/*Set baud rate */
	/* UBRR0H contains the 4 most significant bits of the
	baud rate. UBRR0L contains the 8 least significant
	bits.*/  
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)ubrr;
	

	/*Enable transmitter and receiver */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	
	/* Set frame format: 8data */
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}

void USART_Transmit(unsigned char data){
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) );
	
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

unsigned char USART_Receive(void){
	count++;
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void USART_putstring(char* StringPtr){
	while(*StringPtr != 0){
		USART_Transmit(*StringPtr++);  
	}
}

/* --------------------------------------------- LCD ------------------------------------------- */

void lcd_init(){
	lcd_comando(0x38);
	lcd_comando(0x0E);
	lcd_comando(0x06);
	lcd_comando(0x01);
}

void lcd_comando(char comando){
	PORTB = comando;
	PORTC &= ~(0x01);
	PORTC &= ~(0x02);
	PORTC |= (0x04);
	_delay_ms(50);
	PORTC &= ~(0x04);
}

void lcd_dado(char dado){
	PORTB = dado;
	PORTC |= (0x01);
	PORTC &= ~(0x02);
	PORTC |= (0x04);
	_delay_ms(50);
	PORTC &= ~(0x04);
	
}

int i;

void lcd_print (char *c){
		while (*c != 0)         
			lcd_dado(*c++);     
}

void lcd_clear(){
	lcd_comando(0x01);	//Limpa o LCD
	_delay_ms(2);		//Espera até limpar o LCD
	lcd_comando(0x80);	//Move o cursor pra posição 1
}

lcd_terminal_visual(){
	if(count == 16 && flag == 0){
		lcd_clear();
		lcd_comando(0x80);
		USART_Transmit(0x0d);
		flag = 1;
		count = 0;
	}
	
	else if (count == 16 && flag == 1){
		lcd_comando(0xc0);
		USART_Transmit(0x0d);
	}
	
	else if (count >= 32 && flag == 1){
		lcd_clear();
		lcd_comando(0x80);
		USART_Transmit(0x0d);
		count = 0;
	}
}

/* --------------------------------------------------------------------------------------------- */

char tx;

ISR(PCINT2_vect){
	if(!(PIND&(1<< 2))){
		tx = 'A';
		lcd_dado(tx);
		USART_Transmit(tx);
		count++;
	}
	
	if(!(PIND&(1<< 3))){
		tx = 'B';
		lcd_dado(tx);
		USART_Transmit(tx);	
		count++;
	}
	lcd_terminal_visual();
}

void ativa_interrupcao(){
	PCICR = 0x04;
	PCMSK2 = 0x0c;	
	sei();	
}

int main(void){
	DDRB = 0xff;
	DDRC = 0x07;
	lcd_init();
	USART_Init(MYUBRR);
    lcd_comando(0x80);
    lcd_print("Interface Serial");
	USART_putstring("USART para LCD");
	USART_Transmit(0x0d);
	lcd_comando(0xc0);
	ativa_interrupcao();
	
	while(1){
		lcd_terminal_visual();
		
		tx = USART_Receive();
		
		lcd_dado(tx);
		USART_Transmit(tx);
    }
}