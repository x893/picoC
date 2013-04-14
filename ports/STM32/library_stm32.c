#include "../../interpreter.h"
#include "../../picoc.h"

#include "hardware.h"

extern volatile unsigned long PlatformDelayMs;
extern volatile unsigned long PlatformMsTicks;

void PlatformLibraryInitEx(Picoc *pc)
{
	/* Define pin constants */
	VariableDefinePlatformVar(pc, NULL, "PA0", &pc->UnsignedShortType, (union AnyValue *)&PA0, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA1", &pc->UnsignedShortType, (union AnyValue *)&PA1, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA2", &pc->UnsignedShortType, (union AnyValue *)&PA2, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA3", &pc->UnsignedShortType, (union AnyValue *)&PA3, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA4", &pc->UnsignedShortType, (union AnyValue *)&PA4, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA5", &pc->UnsignedShortType, (union AnyValue *)&PA5, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA6", &pc->UnsignedShortType, (union AnyValue *)&PA6, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA7", &pc->UnsignedShortType, (union AnyValue *)&PA7, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA8", &pc->UnsignedShortType, (union AnyValue *)&PA8, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA9", &pc->UnsignedShortType, (union AnyValue *)&PA9, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA10",&pc->UnsignedShortType, (union AnyValue *)&PA10,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA11",&pc->UnsignedShortType, (union AnyValue *)&PA11,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA12",&pc->UnsignedShortType, (union AnyValue *)&PA12,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA13",&pc->UnsignedShortType, (union AnyValue *)&PA13,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA14",&pc->UnsignedShortType, (union AnyValue *)&PA14,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PA15",&pc->UnsignedShortType, (union AnyValue *)&PA15,FALSE);

	VariableDefinePlatformVar(pc, NULL, "PB0", &pc->UnsignedShortType, (union AnyValue *)&PB0, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB1", &pc->UnsignedShortType, (union AnyValue *)&PB1, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB2", &pc->UnsignedShortType, (union AnyValue *)&PB2, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB3", &pc->UnsignedShortType, (union AnyValue *)&PB3, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB4", &pc->UnsignedShortType, (union AnyValue *)&PB4, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB5", &pc->UnsignedShortType, (union AnyValue *)&PB5, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB6", &pc->UnsignedShortType, (union AnyValue *)&PB6, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB7", &pc->UnsignedShortType, (union AnyValue *)&PB7, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB8", &pc->UnsignedShortType, (union AnyValue *)&PB8, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB9", &pc->UnsignedShortType, (union AnyValue *)&PB9, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB10",&pc->UnsignedShortType, (union AnyValue *)&PB10,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB11",&pc->UnsignedShortType, (union AnyValue *)&PB11,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB12",&pc->UnsignedShortType, (union AnyValue *)&PB12,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB13",&pc->UnsignedShortType, (union AnyValue *)&PB13,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB14",&pc->UnsignedShortType, (union AnyValue *)&PB14,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PB15",&pc->UnsignedShortType, (union AnyValue *)&PB15,FALSE);

	VariableDefinePlatformVar(pc, NULL, "PC0", &pc->UnsignedShortType, (union AnyValue *)&PC0, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC1", &pc->UnsignedShortType, (union AnyValue *)&PC1, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC2", &pc->UnsignedShortType, (union AnyValue *)&PC2, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC3", &pc->UnsignedShortType, (union AnyValue *)&PC3, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC4", &pc->UnsignedShortType, (union AnyValue *)&PC4, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC5", &pc->UnsignedShortType, (union AnyValue *)&PC5, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC6", &pc->UnsignedShortType, (union AnyValue *)&PC6, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC7", &pc->UnsignedShortType, (union AnyValue *)&PC7, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC8", &pc->UnsignedShortType, (union AnyValue *)&PC8, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC9", &pc->UnsignedShortType, (union AnyValue *)&PC9, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC10",&pc->UnsignedShortType, (union AnyValue *)&PC10,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC11",&pc->UnsignedShortType, (union AnyValue *)&PC11,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC12",&pc->UnsignedShortType, (union AnyValue *)&PC12,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC13",&pc->UnsignedShortType, (union AnyValue *)&PC13,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC14",&pc->UnsignedShortType, (union AnyValue *)&PC14,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PC15",&pc->UnsignedShortType, (union AnyValue *)&PC15,FALSE);
}

void PlatformLibrarySetupEx(Picoc *pc)
{
}

void PlatformSleepEx(void)
{
	__NOP();
}

void CdelayEx(unsigned long delay)
{
	PlatformDelayMs = delay;
	while (PlatformDelayMs != 0)
	{
		PlatformSleepEx();
	}
}

typedef struct {
	GPIOMode_TypeDef Mode;
	GPIOSpeed_TypeDef Speed;
} PinMode_t;

const PinMode_t PinMode0  = { GPIO_Mode_AIN,		(GPIOSpeed_TypeDef)0	};
const PinMode_t PinMode1  = { GPIO_Mode_IN_FLOATING,(GPIOSpeed_TypeDef)0	};
const PinMode_t PinMode2  = { GPIO_Mode_IPD,		(GPIOSpeed_TypeDef)0	};
const PinMode_t PinMode4  = { GPIO_Mode_Out_PP,		GPIO_Speed_50MHz		};
const PinMode_t PinMode5  = { GPIO_Mode_Out_OD,		GPIO_Speed_50MHz		};
const PinMode_t PinMode13 = { GPIO_Mode_AF_PP,		GPIO_Speed_50MHz		};
const PinMode_t PinMode14 = { GPIO_Mode_AF_OD,		GPIO_Speed_50MHz		};

const PinMode_t * PinModes[] = {
	&PinMode0,
	&PinMode1,
	&PinMode2,
	&PinMode2,
	&PinMode4,
	&PinMode4,
	&PinMode5,
	&PinMode5,
	&PinMode5,
	&PinMode5,
	&PinMode5,
	&PinMode5,
	&PinMode5,
	&PinMode13,
	&PinMode14
};

GPIO_TypeDef * GPIO_GetPort(int pin)
{
	const GPIO_TypeDef * ports[] = {
		GPIOA,
		GPIOB,
		GPIOC,
		GPIOD
	};
	return ((GPIO_TypeDef *)ports[(pin >> 4) & 0x03]);
}

uint16_t GPIO_GetPin(int pin)
{
	return (1 << (pin & 0x0F));
}

void CpinModeEx(int pin, int mode, int value)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/*	pin:	PPPpppp
				PPP		port number (A = 0, B = 1, etc.)
				pppp	pin number 0-15
		mode:	0 = 
	*/
	PinMode_t modex = PinMode0;
	if (mode >= 0 && mode < (sizeof(PinModes) / sizeof(PinMode_t *)))
	{
		modex.Mode = PinModes[mode]->Mode;
		modex.Speed = PinModes[mode]->Speed;
		if (modex.Mode == GPIO_Mode_IPD && value != 0)
			modex.Mode = GPIO_Mode_IPU;
	}
	
	GPIO_InitStruct.GPIO_Pin = GPIO_GetPin(pin);
	GPIO_InitStruct.GPIO_Mode = modex.Mode;
	GPIO_InitStruct.GPIO_Speed = modex.Speed;

	GPIO_Init(GPIO_GetPort(pin), &GPIO_InitStruct);
}

void CpinOutEx(int pin, int value)
{
	GPIO_WriteBit(GPIO_GetPort(pin), GPIO_GetPin(pin), (BitAction)value);
}

void CpinToggleEx(int pin)
{
	uint16_t pin_mask = GPIO_GetPin(pin);
	GPIO_TypeDef * port = GPIO_GetPort(pin);
	if (port->ODR & pin_mask)
		GPIO_ResetBits(port, pin_mask);
	else
		GPIO_SetBits(port, pin_mask);
}

void ClcdInitEx(void)
{
}

void ClcdWriteEx(char *text)
{
}
