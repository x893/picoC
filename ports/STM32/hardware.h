#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include "stm32f10x.h"

#define CONSOLE_PORT		USART1
#define CONSOLE_CLK2		RCC_APB2Periph_USART1
#define CONSOLE_GPIO_CLK2	RCC_APB2Periph_GPIOA
#define CONSOLE_GPIO		GPIOA
#define CONSOLE_RxPin		GPIO_Pin_10
#define CONSOLE_TxPin		GPIO_Pin_9
#define CONSOLE_IRQn		USART1_IRQn
#define CONSOLE_IRQHandler	USART1_IRQHandler
#define CONSOLE_BUFFER_SIZE	128

#include "../hardware_common.h"

#endif
