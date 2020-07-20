#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    //Включаем шим OC1A
	TCCR1A |= (1<<COM1A1);
	TCCR1A &= ~(1<<COM1A0);

	//Выставляем делитель частоты OC1A
	TCCR1B |= (1<<CS10);
	TCCR1B &= ~(1<<CS11);
	TCCR1B &= ~(1<<CS12);
	
	//Режим быстродействующей шим OC1A
	TCCR1A |= (1<<WGM10);
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM12);
	TCCR1B &= ~(1<<WGM13);

	//Выставляем делитель частоты OC1A
	TCCR1B |= (1<<CS10);
	TCCR1B &= ~(1<<CS11);
	TCCR1B &= ~(1<<CS12);

	//Включаем шим OC1B
	TCCR2 &= ~(1<<COM20);
	TCCR2 |= (1<<COM21);

	//Режим быстродействующей шим OC1B
	TCCR2 |= (1<<WGM21);
	TCCR2 |= (1<<WGM20);

	//Выставляем делитель частоты OC1B
	TCCR2 |= (1<<CS20);
	TCCR2 &= ~(1<<CS21);
	TCCR2 &= ~(1<<CS22);

	//Настраиваем пины на выход
	DDRB |= ((1<<1) | (1<<3));
	PORTB &= ~((1<<1) | (1<<3));

	//Регстр сравнения OC1A
	OCR1A = 1023;
	OCR2  = 128;
	
    while (1) 
    {
		
    }
}

