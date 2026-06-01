#include "stm32f4xx.h"

#define GPIOAEN (1U<<0)
#define GPIOCEN (1U<<2)
#define LED     (1U<<5)

int main()
{
	//Enable clock for GPIOA AND GPIOC
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;

	//SET THE DIRECTION TO OUPUT IN PA5
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	//SET THE DIRECTION FOR THE INPUT IN PC13
	GPIOC->MODER &= ~(1U<<27);
	GPIOC->MODER &= ~(1U<<26);

	while(1)
	{
		if(GPIOC->IDR & (1U<<13))
		{
			GPIOA->ODR &= ~LED;
		}
		else
		{
			GPIOA->ODR |= LED;
		}



	}



}
