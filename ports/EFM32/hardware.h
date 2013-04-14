#ifndef __HARDWARE_H__
#define __HARDWARE_H__

#include "em_gpio.h"
#include "em_usart.h"

#define CONSOLE_PORT		USART1
#define CONSOLE_CLK			cmuClock_USART1
#define CONSOLE_GPIO		gpioPortD
#define CONSOLE_RxPin		1
#define CONSOLE_TxPin		0
#define CONSOLE_RxIRQn		USART1_RX_IRQn
#define CONSOLE_TxIRQn		USART1_TX_IRQn
#define CONSOLE_RxIRQHandler	USART1_RX_IRQHandler
#define CONSOLE_TxIRQHandler	USART1_TX_IRQHandler

#define CONSOLE_BUFFER_SIZE	128

#include "../hardware_common.h"

#endif
