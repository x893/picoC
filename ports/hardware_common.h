#ifndef __HARD_COMMON_H__
#define __HARD_COMMON_H__

#ifdef CONSOLE_PORT
	typedef struct RingBuffer_s {
					uint8_t  data[CONSOLE_BUFFER_SIZE];
		volatile	uint16_t idx_in;
		volatile	uint16_t idx_out;
					bool overflow;
	} RingBuffer_t;

	extern RingBuffer_t ConsoleTxBuffer;
	extern RingBuffer_t ConsoleRxBuffer;
#endif

#define PORTA	(0 * 16)
#define PORTB	(1 * 16)
#define PORTC	(2 * 16)
#define PORTD	(3 * 16)
#define PORTE	(4 * 16)

const extern uint8_t PNONE;
const extern uint8_t PA0;
const extern uint8_t PA1;
const extern uint8_t PA2;
const extern uint8_t PA3;
const extern uint8_t PA4;
const extern uint8_t PA5;
const extern uint8_t PA6;
const extern uint8_t PA7;
const extern uint8_t PA8;
const extern uint8_t PA9;
const extern uint8_t PA10;
const extern uint8_t PA11;
const extern uint8_t PA12;
const extern uint8_t PA13;
const extern uint8_t PA14;
const extern uint8_t PA15;

const extern uint8_t PB0;
const extern uint8_t PB1;
const extern uint8_t PB2;
const extern uint8_t PB3;
const extern uint8_t PB4;
const extern uint8_t PB5;
const extern uint8_t PB6;
const extern uint8_t PB7;
const extern uint8_t PB8;
const extern uint8_t PB9;
const extern uint8_t PB10;
const extern uint8_t PB11;
const extern uint8_t PB12;
const extern uint8_t PB13;
const extern uint8_t PB14;
const extern uint8_t PB15;

const extern uint8_t PC0;
const extern uint8_t PC1;
const extern uint8_t PC2;
const extern uint8_t PC3;
const extern uint8_t PC4;
const extern uint8_t PC5;
const extern uint8_t PC6;
const extern uint8_t PC7;
const extern uint8_t PC8;
const extern uint8_t PC9;
const extern uint8_t PC10;
const extern uint8_t PC11;
const extern uint8_t PC12;
const extern uint8_t PC13;
const extern uint8_t PC14;
const extern uint8_t PC15;

const extern uint8_t PD0;
const extern uint8_t PD1;
const extern uint8_t PD2;
const extern uint8_t PD3;
const extern uint8_t PD4;
const extern uint8_t PD5;
const extern uint8_t PD6;
const extern uint8_t PD7;
const extern uint8_t PD8;
const extern uint8_t PD9;
const extern uint8_t PD10;
const extern uint8_t PD11;
const extern uint8_t PD12;
const extern uint8_t PD13;
const extern uint8_t PD14;
const extern uint8_t PD15;

const extern uint8_t PE0;
const extern uint8_t PE1;
const extern uint8_t PE2;
const extern uint8_t PE3;
const extern uint8_t PE4;
const extern uint8_t PE5;
const extern uint8_t PE6;
const extern uint8_t PE7;
const extern uint8_t PE8;
const extern uint8_t PE9;
const extern uint8_t PE10;
const extern uint8_t PE11;
const extern uint8_t PE12;
const extern uint8_t PE13;
const extern uint8_t PE14;
const extern uint8_t PE15;


#endif
