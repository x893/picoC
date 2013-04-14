#include "../../interpreter.h"
#include "../../picoc.h"

#include "hardware.h"

/*
#ifdef __DBG_ITM
volatile int ITM_RxBuffer = ITM_RXBUFFER_EMPTY;
#endif

int fputc(int ch, FILE *f)
{
#ifdef __DBG_ITM
    ITM_SendChar(ch);
#endif
	return (ch);
}

char getch(void)
{
#ifdef __DBG_ITM
	while (ITM_CheckChar() != 1)
		__NOP();
	return (char)(ITM_ReceiveChar());
#else
	while(1);
#endif
}
*/

void fputcEx(int ch)
{
#ifdef CONSOLE_PORT
	USART_ITConfig(CONSOLE_PORT, USART_IT_TXE, ENABLE);
#endif
}

#ifdef CONSOLE_PORT
/*------------------------------------------------------------------------------
 * Serial interrupt handler routine
 *----------------------------------------------------------------------------*/
void CONSOLE_IRQHandler(void)
{
	uint8_t  ch;

	/* Transmit data register empty interrupt */
	if (USART_GetITStatus(CONSOLE_PORT, USART_IT_TXE) != RESET)
	{
		if (ConsoleTxBuffer.idx_in != ConsoleTxBuffer.idx_out)
		{
			USART_SendData(CONSOLE_PORT, ConsoleTxBuffer.data[ConsoleTxBuffer.idx_out++]);
			ConsoleTxBuffer.idx_out &= (CONSOLE_BUFFER_SIZE - 1);
		}
		else
			USART_ITConfig(CONSOLE_PORT, USART_IT_TXE, DISABLE);
	}

	/* Read data register not empty interrupt */
	if(USART_GetITStatus(CONSOLE_PORT, USART_IT_RXNE) != RESET)
	{
		uint16_t next = (ConsoleRxBuffer.idx_in + 1) & (CONSOLE_BUFFER_SIZE - 1);
		if (next != ConsoleRxBuffer.idx_out)
		{
			ch = (uint8_t)USART_ReceiveData(CONSOLE_PORT);
			if (ch != 0)
			{
				ConsoleRxBuffer.data[ConsoleRxBuffer.idx_in] = ch;
				ConsoleRxBuffer.idx_in = next;
			}
		}
	}
}
#endif

void PlatformInitEx(Picoc *pc)
{
#ifdef CONSOLE_PORT
	NVIC_InitTypeDef NVIC_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	#ifdef CONSOLE_GPIO_CLK2
		RCC_APB2PeriphClockCmd(CONSOLE_GPIO_CLK2, ENABLE);
	#endif
	#ifdef CONSOLE_CLK1
		RCC_APB1PeriphClockCmd(CONSOLE_CLK1, ENABLE);
	#endif
	#ifdef CONSOLE_CLK2
		RCC_APB2PeriphClockCmd(CONSOLE_CLK2, ENABLE);
	#endif

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	/* Enable the USARTy Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = CONSOLE_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Configure Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = CONSOLE_RxPin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(CONSOLE_GPIO, &GPIO_InitStructure);

	/* Configure Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = CONSOLE_TxPin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(CONSOLE_GPIO, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(CONSOLE_PORT, &USART_InitStructure);
	USART_ITConfig(CONSOLE_PORT, USART_IT_RXNE, ENABLE);
	USART_Cmd(CONSOLE_PORT, ENABLE);

	NVIC_EnableIRQ(CONSOLE_IRQn);
#endif

	if (SysTick_Config(SystemCoreClock / 1000))
	{
		// Error starting SysTick
	}
}

void PlatformCleanupEx(Picoc *pc)
{
#ifdef CONSOLE_PORT
	GPIO_InitTypeDef GPIO_InitStructure;
#endif

	// Disable SysTick timer
	SysTick->CTRL = 0;

#ifdef CONSOLE_PORT
	while (ConsoleTxBuffer.idx_in != ConsoleTxBuffer.idx_out)
		__NOP();

	NVIC_DisableIRQ(CONSOLE_IRQn);
	USART_ITConfig(CONSOLE_PORT, USART_IT_RXNE, DISABLE);
	USART_ITConfig(CONSOLE_PORT, USART_IT_TXE, DISABLE);
	USART_Cmd(CONSOLE_PORT, DISABLE);

#ifdef CONSOLE_CLK1
	RCC_APB1PeriphClockCmd(CONSOLE_CLK1, DISABLE);
#endif
#ifdef CONSOLE_CLK2
	RCC_APB2PeriphClockCmd(CONSOLE_CLK2, DISABLE);
#endif

	/* Configure Rx/Tx as analog in */
	GPIO_InitStructure.GPIO_Pin = (CONSOLE_RxPin | CONSOLE_TxPin);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(CONSOLE_GPIO, &GPIO_InitStructure);

#endif
}

/**************************************************************************//**
 * @brief SysTick_Handler
 * Interrupt Service Routine for system tick counter.
 *****************************************************************************/
volatile unsigned long PlatformDelayMs = 0;
volatile unsigned long PlatformMsTicks = 0;

void SysTick_Handler(void)
{
	/* Increment counter necessary in Delay()*/
	PlatformMsTicks++;

	if (PlatformDelayMs > 0)
		PlatformDelayMs--;
}
