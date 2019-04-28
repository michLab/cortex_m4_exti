/*
 * author:	Michal Labowski
 * brief: 	This is a basic template for STM32F407VGT6
 */
#include "main.h"

int main(void)
{
	// Hardware configuration:
	prvSetupHardware();

	while(1)
	return 0;
}

static void prvSetupHardware(void)
{
	hGPIOInit();
	interruptInit();
}

void hGPIOInit(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; 	// Enable clock for GPIO PORT D
	__DSB();

	gpio_pin_cfg(GPIOD, PIN_LED_GREEN, gpio_mode_output_PP_FS); 	// GPIO config for LED GREEN
}

void interruptInit()
{
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; 	// Enable System Configuration Controler (needed for EXTI)
	__DSB();

	SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI0_PA; // Source of EXTI0 is GPIO port A
	EXTI->RTSR = EXTI_RTSR_TR0;		// EXTI0: rising trigger enabled
	EXTI->FTSR &= ~EXTI_RTSR_TR0;	// EXTI0: falling trigger disabled
	EXTI->IMR = EXTI_IMR_MR0; 	// Unmask EXTI0
	NVIC_EnableIRQ(EXTI0_IRQn); 	// Enable EXTI0 inetrrupt
}





