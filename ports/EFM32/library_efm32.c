#include "../../interpreter.h"
#include "../../picoc.h"

#include "hardware.h"

#include "em_cmu.h"
#include "em_gpio.h"
#include "em_emu.h"
#include "em_lcd.h"
#include "segmentlcd.h"

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

	VariableDefinePlatformVar(pc, NULL, "PD0", &pc->UnsignedShortType, (union AnyValue *)&PD0, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD1", &pc->UnsignedShortType, (union AnyValue *)&PD1, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD2", &pc->UnsignedShortType, (union AnyValue *)&PD2, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD3", &pc->UnsignedShortType, (union AnyValue *)&PD3, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD4", &pc->UnsignedShortType, (union AnyValue *)&PD4, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD5", &pc->UnsignedShortType, (union AnyValue *)&PD5, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD6", &pc->UnsignedShortType, (union AnyValue *)&PD6, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD7", &pc->UnsignedShortType, (union AnyValue *)&PD7, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD8", &pc->UnsignedShortType, (union AnyValue *)&PD8, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD9", &pc->UnsignedShortType, (union AnyValue *)&PD9, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD10",&pc->UnsignedShortType, (union AnyValue *)&PD10,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD11",&pc->UnsignedShortType, (union AnyValue *)&PD11,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD12",&pc->UnsignedShortType, (union AnyValue *)&PD12,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD13",&pc->UnsignedShortType, (union AnyValue *)&PD13,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD14",&pc->UnsignedShortType, (union AnyValue *)&PD14,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PD15",&pc->UnsignedShortType, (union AnyValue *)&PD15,FALSE);

	VariableDefinePlatformVar(pc, NULL, "PE0", &pc->UnsignedShortType, (union AnyValue *)&PE0, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE1", &pc->UnsignedShortType, (union AnyValue *)&PE1, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE2", &pc->UnsignedShortType, (union AnyValue *)&PE2, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE3", &pc->UnsignedShortType, (union AnyValue *)&PE3, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE4", &pc->UnsignedShortType, (union AnyValue *)&PE4, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE5", &pc->UnsignedShortType, (union AnyValue *)&PE5, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE6", &pc->UnsignedShortType, (union AnyValue *)&PE6, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE7", &pc->UnsignedShortType, (union AnyValue *)&PE7, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE8", &pc->UnsignedShortType, (union AnyValue *)&PE8, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE9", &pc->UnsignedShortType, (union AnyValue *)&PE9, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE10",&pc->UnsignedShortType, (union AnyValue *)&PE10,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE11",&pc->UnsignedShortType, (union AnyValue *)&PE11,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE12",&pc->UnsignedShortType, (union AnyValue *)&PE12,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE13",&pc->UnsignedShortType, (union AnyValue *)&PE13,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE14",&pc->UnsignedShortType, (union AnyValue *)&PE14,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PE15",&pc->UnsignedShortType, (union AnyValue *)&PE15,FALSE);
/*
	VariableDefinePlatformVar(pc, NULL, "PF0", &pc->UnsignedShortType, (union AnyValue *)&PF0, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF1", &pc->UnsignedShortType, (union AnyValue *)&PF1, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF2", &pc->UnsignedShortType, (union AnyValue *)&PF2, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF3", &pc->UnsignedShortType, (union AnyValue *)&PF3, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF4", &pc->UnsignedShortType, (union AnyValue *)&PF4, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF5", &pc->UnsignedShortType, (union AnyValue *)&PF5, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF6", &pc->UnsignedShortType, (union AnyValue *)&PF6, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF7", &pc->UnsignedShortType, (union AnyValue *)&PF7, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF8", &pc->UnsignedShortType, (union AnyValue *)&PF8, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF9", &pc->UnsignedShortType, (union AnyValue *)&PF9, FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF10",&pc->UnsignedShortType, (union AnyValue *)&PF10,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF11",&pc->UnsignedShortType, (union AnyValue *)&PF11,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF12",&pc->UnsignedShortType, (union AnyValue *)&PF12,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF13",&pc->UnsignedShortType, (union AnyValue *)&PF13,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF14",&pc->UnsignedShortType, (union AnyValue *)&PF14,FALSE);
	VariableDefinePlatformVar(pc, NULL, "PF15",&pc->UnsignedShortType, (union AnyValue *)&PF15,FALSE);
*/
}

void PlatformLibrarySetupEx(Picoc *pc)
{
}

void PlatformSleepEx(void)
{
	EMU_EnterEM1();
}

void CdelayEx(unsigned long delay)
{
	PlatformDelayMs = delay;
	while (PlatformDelayMs != 0)
	{
		PlatformSleepEx();
	}
}

const GPIO_Mode_TypeDef PinModes[] = {
	gpioModeDisabled,
	gpioModeInput,
	gpioModeInputPull,
	gpioModeInputPullFilter,
	gpioModePushPull,
	gpioModePushPullDrive,
	gpioModeWiredOr,
	gpioModeWiredOrPullDown,
	gpioModeWiredAnd,
	gpioModeWiredAndFilter,
	gpioModeWiredAndPullUp,
	gpioModeWiredAndPullUpFilter,
	gpioModeWiredAndDrive,
	gpioModeWiredAndDriveFilter,
	gpioModeWiredAndDrivePullUp,
	gpioModeWiredAndDrivePullUpFilter
};

GPIO_Port_TypeDef GPIO_GetPort(int pin)
{
	return (GPIO_Port_TypeDef)((pin >> 4) & 0x07);
}
int GPIO_GetPin(int pin)
{
	return (pin & 0x0F);
}

void CpinModeEx(int pin, int mode, int value)
{
	/*	pin:	PPPpppp
				PPP		port number (A = 0, B = 1, etc.)
				pppp	pin number 0-15
		mode:	0 = 
	*/
	GPIO_Mode_TypeDef modex = gpioModeDisabled;
	if (mode >= 0 && mode < (sizeof(PinModes) / sizeof(GPIO_Mode_TypeDef)))
		modex = PinModes[mode];

	GPIO_PinModeSet(GPIO_GetPort(pin), GPIO_GetPin(pin), modex, value);
}

void CpinOutEx(int pin, int value)
{
	if (value)
		GPIO_PinOutSet(GPIO_GetPort(pin), GPIO_GetPin(pin));
	else
		GPIO_PinOutClear(GPIO_GetPort(pin), GPIO_GetPin(pin));
}

void CpinToggleEx(int pin)
{
	GPIO_PinOutToggle(GPIO_GetPort(pin), GPIO_GetPin(pin));
}

/**************************************************************************//**
 * @brief  Sets up LCD animation
 *****************************************************************************/
void SetupAnimation(void)
{
	/* Configuration structure for LCD animation. */
	static const LCD_AnimInit_TypeDef animInit =
	{
		.enable      = true,                  /* Enable animation. */
		.AReg        = 0x00,                  /* Set up animation start data. */
		.AShift      = lcdAnimShiftLeft,      /* Register A Shift direction. */
		.BReg        = 0x01,                  /* Set up animation start data. */
		.BShift      = lcdAnimShiftRight,     /* Register B Shift direction. */
		.animLogic   = lcdAnimLogicOr,        /* Logic function. */

		/* Adapt animation segments to the different kits. */
		/* Leave at default for other kits: STK G8xx, STK3300, DK3550, DK G8xx */

		/* Note that STK3700 only has half the animation ring connected to animation */
		/* enabled segments. */    
// #if defined( STK3700 )
		.startSeg    = 8	/* STK3700 has animation circle on seg8-15. */
// #endif
	};

	/* Configuration structure for frame counter. */
	static const LCD_FrameCountInit_TypeDef fcInit =
	{
		.enable      = true,                  /* Enable frame counter. */
		.top         = 0x3,                   /* Frame counter period. */
		.prescale    = lcdFCPrescDiv1         /* Set frame counter prescaler. */
	}; 

	/* Initialize Animation */
	LCD_AnimInit(&animInit);

	/* Configure and start the framecounter which clocks the animation state machine. */
	LCD_FrameCountInit(&fcInit);
}

void ClcdInitEx(void)
{
	/* Initialize LCD controller without boost. */
	SegmentLCD_Init(false);

//	SegmentLCD_Write("EFM32");
//	SegmentLCD_Symbol(LCD_SYMBOL_GECKO, 1);

	/* Configure Animation. */
//	SetupAnimation();
	/* Enable segment blinking. */
	LCD_BlinkEnable(false);        /* Set to true to see blink feature. */ 

	/* Set contrast to suitable level for 3.3V. */
	LCD_ContrastSet(0x1A);

	/* LCD Controller Prescaler (divide LFACLK / 64) */
	/* LFACLK_LCDpre = 512 Hz */
	/* Set FDIV=0, means 512/1 = 512 Hz */
	/* With octaplex mode, 512/16 => 32 Hz Frame Rate */  
	CMU_ClockDivSet(cmuClock_LCDpre, cmuClkDiv_64);     /* divide LFACLK / 64 */
	CMU_LCDClkFDIVSet(cmuClkDiv_1);                     /* FDIV = 0 */

	/* Enable boost converter. To save energy, first try to adjust framerate */
	/* and contrast to maximum, in many cases this is enough to account for lower */
	/* supply voltage. */
	if(0)
	{
		/* Set Vboost level, for lowest current consumption, set as low as possible. */
		LCD_VBoostSet(lcdVBoostLevel3);   
		LCD_VLCDSelect(lcdVLCDSelVExtBoost);  /* Select External LCD supply. */

		/* Adjust boost converter frequency, can be adjusted to reduce current consumption. */
		CMU->LCDCTRL = (CMU->LCDCTRL & (~_CMU_LCDCTRL_VBFDIV_MASK)) | CMU_LCDCTRL_VBFDIV_DIV4;

		CMU->LCDCTRL |= CMU_LCDCTRL_VBOOSTEN; /* Enable boost converter. */
	}
}

void ClcdWriteEx(char *text)
{
	SegmentLCD_Write(text);
}
