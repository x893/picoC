#include "../interpreter.h"
#include "../picoc.h"

#include "hardware_common.h"

const uint8_t PNONE  = 0xFF;
const uint8_t PA0  = (PORTA + 0);
const uint8_t PA1  = (PORTA + 1);
const uint8_t PA2  = (PORTA + 2);
const uint8_t PA3  = (PORTA + 3);
const uint8_t PA4  = (PORTA + 4);
const uint8_t PA5  = (PORTA + 5);
const uint8_t PA6  = (PORTA + 6);
const uint8_t PA7  = (PORTA + 7);
const uint8_t PA8  = (PORTA + 8);
const uint8_t PA9  = (PORTA + 9);
const uint8_t PA10 = (PORTA + 10);
const uint8_t PA11 = (PORTA + 11);
const uint8_t PA12 = (PORTA + 12);
const uint8_t PA13 = (PORTA + 13);
const uint8_t PA14 = (PORTA + 14);
const uint8_t PA15 = (PORTA + 15);

const uint8_t PB0  = (PORTB + 0);
const uint8_t PB1  = (PORTB + 1);
const uint8_t PB2  = (PORTB + 2);
const uint8_t PB3  = (PORTB + 3);
const uint8_t PB4  = (PORTB + 4);
const uint8_t PB5  = (PORTB + 5);
const uint8_t PB6  = (PORTB + 6);
const uint8_t PB7  = (PORTB + 7);
const uint8_t PB8  = (PORTB + 8);
const uint8_t PB9  = (PORTB + 9);
const uint8_t PB10 = (PORTB + 10);
const uint8_t PB11 = (PORTB + 11);
const uint8_t PB12 = (PORTB + 12);
const uint8_t PB13 = (PORTB + 13);
const uint8_t PB14 = (PORTB + 14);
const uint8_t PB15 = (PORTB + 15);

const uint8_t PC0  = (PORTC + 0);
const uint8_t PC1  = (PORTC + 1);
const uint8_t PC2  = (PORTC + 2);
const uint8_t PC3  = (PORTC + 3);
const uint8_t PC4  = (PORTC + 4);
const uint8_t PC5  = (PORTC + 5);
const uint8_t PC6  = (PORTC + 6);
const uint8_t PC7  = (PORTC + 7);
const uint8_t PC8  = (PORTC + 8);
const uint8_t PC9  = (PORTC + 9);
const uint8_t PC10 = (PORTC + 10);
const uint8_t PC11 = (PORTC + 11);
const uint8_t PC12 = (PORTC + 12);
const uint8_t PC13 = (PORTC + 13);
const uint8_t PC14 = (PORTC + 14);
const uint8_t PC15 = (PORTC + 15);

const uint8_t PD0  = (PORTD + 0);
const uint8_t PD1  = (PORTD + 1);
const uint8_t PD2  = (PORTD + 2);
const uint8_t PD3  = (PORTD + 3);
const uint8_t PD4  = (PORTD + 4);
const uint8_t PD5  = (PORTD + 5);
const uint8_t PD6  = (PORTD + 6);
const uint8_t PD7  = (PORTD + 7);
const uint8_t PD8  = (PORTD + 8);
const uint8_t PD9  = (PORTD + 9);
const uint8_t PD10 = (PORTD + 10);
const uint8_t PD11 = (PORTD + 11);
const uint8_t PD12 = (PORTD + 12);
const uint8_t PD13 = (PORTD + 13);
const uint8_t PD14 = (PORTD + 14);
const uint8_t PD15 = (PORTD + 15);

const uint8_t PE0  = (PORTE + 0);
const uint8_t PE1  = (PORTE + 1);
const uint8_t PE2  = (PORTE + 2);
const uint8_t PE3  = (PORTE + 3);
const uint8_t PE4  = (PORTE + 4);
const uint8_t PE5  = (PORTE + 5);
const uint8_t PE6  = (PORTE + 6);
const uint8_t PE7  = (PORTE + 7);
const uint8_t PE8  = (PORTE + 8);
const uint8_t PE9  = (PORTE + 9);
const uint8_t PE10 = (PORTE + 10);
const uint8_t PE11 = (PORTE + 11);
const uint8_t PE12 = (PORTE + 12);
const uint8_t PE13 = (PORTE + 13);
const uint8_t PE14 = (PORTE + 14);
const uint8_t PE15 = (PORTE + 15);

void PlatformLibrarySetupEx(Picoc *pc);
void PlatformLibraryInitEx(Picoc *pc);

/* Platform depending functions */
void CpinModeEx(int pin, int mode, int value);
void CpinOutEx(int pin, int value);
void CpinToggleEx(int pin);
void CdelayEx(unsigned long delay);
void ClcdInitEx(void);
void ClcdWriteEx(char *text);


void CpinMode(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	CpinModeEx(Param[0]->Val->Integer, Param[1]->Val->Integer, Param[2]->Val->Integer);
}

void CpinOut(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	CpinOutEx(Param[0]->Val->Integer, Param[1]->Val->Integer);
}

void CpinToggle(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	CpinToggleEx(Param[0]->Val->Integer);
}

void Cdelay(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	CdelayEx(Param[0]->Val->UnsignedLongInteger);
}

void ClcdInit(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ClcdInitEx();
}

void ClcdWrite(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs)
{
	ClcdWriteEx(Param[0]->Val->Pointer);
}

/*
 *
 *
 */
struct LibraryFunction PlatformLibrary[] =
{
	{ CpinMode,		"void pinMode(int,int,int);"	},
	{ CpinOut,		"void pinOut(int,int);"			},
	{ CpinToggle,	"void pinToggle(int);"			},
	{ Cdelay,		"void delay_ms(unsigned long);"	},
	{ ClcdInit,		"void lcdInit();"				},
	{ ClcdWrite,	"void lcdWrite(char *);"		},
    { NULL,         NULL }
};

/*
 *
 *
 */
void PlatformLibrarySetup(Picoc *pc)
{
	PlatformLibrarySetupEx(pc);
}

/*
 *
 *
 */
void PlatformLibraryInit(Picoc *pc)
{
    IncludeRegister(pc, "stk.h", &PlatformLibrarySetup, &PlatformLibrary[0], NULL);
	PlatformLibraryInitEx(pc);
}
