#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    //�������� ��� OC1A
	TCCR1A |= (1<<COM1A1);
	TCCR1A &= ~(1<<COM1A0);

	//���������� �������� ������� OC1A
	TCCR1B |= (1<<CS10);
	TCCR1B &= ~(1<<CS11);
	TCCR1B &= ~(1<<CS12);
	
	//����� ����������������� ��� OC1A
	TCCR1A |= (1<<WGM10);
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM12);
	TCCR1B &= ~(1<<WGM13);

	//���������� �������� ������� OC1A
	TCCR1B |= (1<<CS10);
	TCCR1B &= ~(1<<CS11);
	TCCR1B &= ~(1<<CS12);

	//�������� ��� OC1B
	TCCR2 &= ~(1<<COM20);
	TCCR2 |= (1<<COM21);

	//����� ����������������� ��� OC1B
	TCCR2 |= (1<<WGM21);
	TCCR2 |= (1<<WGM20);

	//���������� �������� ������� OC1B
	TCCR2 |= (1<<CS20);
	TCCR2 &= ~(1<<CS21);
	TCCR2 &= ~(1<<CS22);

	//����������� ���� �� �����
	DDRB |= ((1<<1) | (1<<3));
	PORTB &= ~((1<<1) | (1<<3));

	//������ ��������� OC1A
	OCR1A = 1023;
	OCR2  = 128;
	
    while (1) 
    {
		
    }
}

