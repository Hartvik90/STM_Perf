#include "system.h"

#include "system_init.h"
#include "com.h"
#include "thruster.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"



void run(void);


void sysStart(void)
{
	// initialize the system
	sysInit();

	// run the system
	run();
}

// handler for the systick interrupt, performing periodical operations
void SysTick_Handler(void)
{
	int val = getData(1);
	TIM4->CCR2 = 3000 + (val*16);

	GPIOC->ODR ^= GPIO_Pin_6;


}


void run(void)
{

    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);




	RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO  |  RCC_APB2Periph_GPIOA, ENABLE);



	while(1)
    {




        /* delay */
        int i = 0;
        for(i=0;i<0x100000;i++);


        GPIOC->ODR ^= GPIO_Pin_9;

        /* delay */
        //for(i=0;i<0x100000;i++);

    }
}


