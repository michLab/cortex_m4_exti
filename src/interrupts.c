#include "interrupts.h"

void EXTI0_IRQHandler(void)
{
	if(EXTI->PR & EXTI_PR_PR0){
		EXTI->PR = EXTI_PR_PR0;
		GPIO_TOGGLE(GPIOD, PIN_LED_GREEN);
	}
}
