
/******************************************************************************/
/*                                 LYBRARY                                    */
/******************************************************************************/

#include "stm32f4xx.h"

/******************************************************************************/
/*                                 USE FUNCTION                               */
/******************************************************************************/

void InitGPIO (void);

/******************************************************************************/
/*                                    MAIN                                    */
/******************************************************************************/

int main (void){

uint32_t i;
	
InitGPIO ();
	
	while (1){
		
		GPIOD->BSRR |= GPIO_BSRR_BS15;
		for (i = 0; i < 2000000; i ++);
		GPIOD->BSRR |= GPIO_BSRR_BR15;

		GPIOD->BSRR |= GPIO_BSRR_BS13;
		for (i = 0; i < 2000000; i ++);
		GPIOD->BSRR |= GPIO_BSRR_BR13;
	}
}

/******************************************************************************/
/*                                  InitGPIO                                  */
/******************************************************************************/

void InitGPIO (void) {

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;                  			//Enable Clock for PORTD

	GPIOD->MODER |= GPIO_MODER_MODE15_0;                  			//Outpet Mode
	GPIOD->OTYPER &=~ GPIO_OTYPER_OT15;                  				//Push-Pull
	GPIOD->OSPEEDR |= GPIO_OSPEEDR_OSPEED15_0;           			  //Medium Speed
	
	GPIOD->MODER |= GPIO_MODER_MODE13_0;                 			  //Output Mode
	GPIOD->OTYPER &=~ GPIO_OTYPER_OT13;                  			  //Push-Pull
	GPIOD->OSPEEDR |= GPIO_OSPEEDR_OSPEED13_0;          		    //Medium Speed
}


