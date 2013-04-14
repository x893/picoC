#include "../../interpreter.h"
#include "../../picoc.h"

#include "hardware.h"

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_usart.h"

void fputcEx(int ch)
{
#ifdef CONSOLE_PORT
	/* Enable interrupt on USART TX Buffer*/
	USART_IntEnable(CONSOLE_PORT, UART_IF_TXBL);
#endif
}

#ifdef CONSOLE_PORT
/*------------------------------------------------------------------------------
 * Serial interrupt handler routine
 *----------------------------------------------------------------------------*/
void CONSOLE_RxIRQHandler(void)
{
	/* Check for RX data valid interrupt */
	if (CONSOLE_PORT->STATUS & UART_STATUS_RXDATAV)
	{
		uint8_t ch = (uint8_t)USART_Rx(CONSOLE_PORT);
		if (ch != 0)
		{
			uint16_t next = (ConsoleRxBuffer.idx_in + 1) & (CONSOLE_BUFFER_SIZE - 1);
			if (next != ConsoleRxBuffer.idx_out)
			{
				ConsoleRxBuffer.data[ConsoleRxBuffer.idx_in] = ch;
				ConsoleRxBuffer.idx_in = next;
			}
			else
				ConsoleRxBuffer.overflow = true;
		}
		/* Clear RXDATAV interrupt */
		USART_IntClear(CONSOLE_PORT, UART_IF_RXDATAV);
	}
}

/**************************************************************************//**
 * @brief Console TX IRQ Handler
 *
 * Set up the interrupt prior to use
 *
 *****************************************************************************/
void CONSOLE_TxIRQHandler(void)
{
	/* Clear interrupt flags by reading them. */
	USART_IntGet(CONSOLE_PORT);

	/* Check TX buffer level status */
	if (CONSOLE_PORT->STATUS & UART_STATUS_TXBL)
	{
		if (ConsoleTxBuffer.idx_in != ConsoleTxBuffer.idx_out)
		{
			USART_Tx(CONSOLE_PORT, ConsoleTxBuffer.data[ConsoleTxBuffer.idx_out++]);
			ConsoleTxBuffer.idx_out &= (CONSOLE_BUFFER_SIZE - 1);
		}
		else
			USART_IntDisable(CONSOLE_PORT, UART_IF_TXBL);
	}
}

#endif

void PlatformInitEx(Picoc *pc)
{
#ifdef CONSOLE_PORT
	USART_InitAsync_TypeDef init = USART_INITASYNC_DEFAULT;
#endif

	/* Initialize chip */
	CHIP_Init();

	/* Start HFXO and wait until it is stable */
	CMU_OscillatorEnable( cmuOsc_HFXO, true, true);

	/* Select HFXO as clock source for HFCLK */
	CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO );

	/* Disable HFRCO */
	CMU_OscillatorEnable( cmuOsc_HFRCO, false, false );

	/* Enable clock for HF peripherals */
	CMU_ClockEnable(cmuClock_HFPER, true);

	/* Enable clock for GPIO module */
	CMU_ClockEnable(cmuClock_GPIO, true);

#ifdef CONSOLE_PORT

	/* Configure GPIO pins */
	GPIO_PinModeSet(CONSOLE_GPIO, CONSOLE_RxPin, gpioModeInput, 1);
	GPIO_PinModeSet(CONSOLE_GPIO, CONSOLE_TxPin, gpioModePushPull, 1);

	/* Enable clock for USART module */
	CMU_ClockEnable(CONSOLE_CLK, true);

	init.baudrate     = 115200;
	init.oversampling = usartOVS16;
	init.databits     = usartDatabits8;
	init.parity       = usartNoParity;
	init.stopbits     = usartStopbits1;
	init.mvdis        = 0;
	init.prsRxEnable  = 0;

	USART_InitAsync(CONSOLE_PORT, &init);
	
	/* Prepare UART Rx and Tx interrupts */
	USART_IntClear(CONSOLE_PORT, _UART_IF_MASK);
	USART_IntEnable(CONSOLE_PORT, UART_IF_RXDATAV);
	
	NVIC_ClearPendingIRQ(CONSOLE_RxIRQn);
	NVIC_ClearPendingIRQ(CONSOLE_TxIRQn);

	NVIC_EnableIRQ(CONSOLE_RxIRQn);
	NVIC_EnableIRQ(CONSOLE_TxIRQn);

	/* Module USART1 is configured to location 1 */
	CONSOLE_PORT->ROUTE = (CONSOLE_PORT->ROUTE & ~_USART_ROUTE_LOCATION_MASK) | USART_ROUTE_LOCATION_LOC1;
	/* Enable signals TX, RX */
	CONSOLE_PORT->ROUTE |= USART_ROUTE_TXPEN | USART_ROUTE_RXPEN;

#endif

	/* Setup SysTick Timer for 1 msec interrupts  */
	if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000))
	{
		// Error starting SysTick
	}
}

void PlatformCleanupEx(Picoc *pc)
{
	// Disable SysTick timer
	SysTick->CTRL = 0;

#ifdef CONSOLE_PORT
	while (ConsoleTxBuffer.idx_in != ConsoleTxBuffer.idx_out)
		__NOP();

	NVIC_DisableIRQ(CONSOLE_RxIRQn);
	NVIC_DisableIRQ(CONSOLE_TxIRQn);
	
	USART_IntDisable(CONSOLE_PORT, _UART_IF_MASK);

	CONSOLE_PORT->ROUTE &= ~(USART_ROUTE_TXPEN | USART_ROUTE_RXPEN);

#ifdef CONSOLE_CLK
	CMU_ClockEnable(CONSOLE_CLK, false);
#endif

	GPIO_PinModeSet(CONSOLE_GPIO, CONSOLE_RxPin, gpioModeDisabled, 1);
	GPIO_PinModeSet(CONSOLE_GPIO, CONSOLE_TxPin, gpioModeDisabled, 1);

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
