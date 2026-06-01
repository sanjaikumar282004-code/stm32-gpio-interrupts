#include <exti.h>
#include "stm32f4xx.h"
#include "uart.h"
#include <stdio.h>

#define GPIOAEN (1U<<0)

int main(void)
{
    uart_init();
	exti_PC13_init();

	//ENABLE CLOCK FOR GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	//SET PA5 HAS OUTPUT
	GPIOA->MODER &= ~(1U<<11);
	GPIOA->MODER |= (1U<<10);

	while(1)
	{
		printf("Normal...\r\n");
		for(int i =0;i<1000000;i++);
	}

}

static void exti_pc13_called(void)
{
	GPIOA->ODR ^= (1U<<5);
	printf("Interrupt Occured...\r\n");
	for(int i =0;i<1000000;i++);
}


//INTERRUPT HANDLER
void EXTI15_10_IRQHandler(void)
{
	if((EXTI->PR & (1U<<13))!=0)
	{
		EXTI->PR |= (1U<<13);
		//IF INTERRUPTED THIS FUNCTION CALLED
		exti_pc13_called();
	}
}

