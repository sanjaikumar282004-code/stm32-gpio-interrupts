#include "stm32f4xx.h"

#define GPIOAEN (1U<<0)
#define LED     (1U<<5)

int main()
{
	//Enable clock for GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	//SET THE DIRECTION TO OUPUT IN PA5
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);


	while(1)
	{
		GPIOA->ODR |= LED;

		for(int i=0;i<1000000;i++);

		GPIOA->ODR &= ~LED;

		for(int i=0;i<1000000;i++);
	}



}
