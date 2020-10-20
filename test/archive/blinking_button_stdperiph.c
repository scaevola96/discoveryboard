#include "stm32f4xx.h"
uint32_t i;
int main(void)
{
	
	GPIO_InitTypeDef GPIO_struct_LED;
	
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	
	
	
	GPIO_struct_LED.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_struct_LED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_struct_LED.GPIO_Speed = GPIO_Low_Speed;
	GPIO_struct_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_struct_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_struct_LED);
	
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	
	
	GPIO_InitTypeDef GPIO_struct_Button;
	
	GPIO_struct_Button.GPIO_Pin = GPIO_Pin_0;
	GPIO_struct_Button.GPIO_Mode = GPIO_Mode_IN;
	GPIO_struct_Button.GPIO_Speed = GPIO_Low_Speed;
	GPIO_struct_Button.GPIO_OType = GPIO_OType_PP;
	GPIO_struct_Button.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &GPIO_struct_Button);
	
	while(1)
	{
	
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)==1){
			GPIO_SetBits(GPIOD, GPIO_Pin_14 | GPIO_Pin_13);
			
		
		}
		else{
		
			GPIO_ResetBits(GPIOD, GPIO_Pin_14 | GPIO_Pin_13);
		
		}
		
		
		
		/*GPIO_SetBits(GPIOD, GPIO_Pin_14 | GPIO_Pin_13);
		for (i=0; i<1000000; i++){}
			
		GPIO_ResetBits(GPIOD, GPIO_Pin_14 | GPIO_Pin_13);	
		for (i=0; i<1000000; i++){}		
			
		GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_15);
		for (i=0; i<1000000; i++){}	
		
		GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_15);	
		for (i=0; i<1000000; i++){}		*/
		
	
	}

}
