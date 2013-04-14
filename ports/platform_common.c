#include "../interpreter.h"
#include "../picoc.h"

#include <stdio.h>
#include "hardware.h"

#ifdef CONSOLE_PORT
	RingBuffer_t ConsoleTxBuffer;
	RingBuffer_t ConsoleRxBuffer;
#endif

void PlatformInitEx(Picoc *pc);
void PlatformCleanupEx(Picoc *pc);
void PlatformSleepEx(void);

void fputcEx(int ch);


void PlatformInit(Picoc *pc)
{
#ifdef CONSOLE_PORT
	memset(&ConsoleTxBuffer, '\0', sizeof(ConsoleTxBuffer));
	memset(&ConsoleRxBuffer, '\0', sizeof(ConsoleRxBuffer));
#endif
	PlatformInitEx(pc);
}


void PlatformCleanup(Picoc *pc)
{
	PlatformCleanupEx(pc);
}

void PlatformSleep(void)
{
	PlatformSleepEx();
}

int fputc(int ch, FILE *f)
{
#ifdef CONSOLE_PORT
	uint16_t next;

	if (ch == '\n')
		fputc('\r', f);

	next = (ConsoleTxBuffer.idx_in + 1) & (CONSOLE_BUFFER_SIZE - 1);
	while (next == ConsoleTxBuffer.idx_out)
	{
		__NOP();
	}

	ConsoleTxBuffer.data[ConsoleTxBuffer.idx_in] = ch;
	ConsoleTxBuffer.idx_in = next;

#endif
	fputcEx(ch);
	return (ch);
}


char getch(void)
{
#ifdef CONSOLE_PORT
	char ch;
	int next;
	while (ConsoleRxBuffer.idx_in == ConsoleRxBuffer.idx_out)
		PlatformSleep();
	ch = ConsoleRxBuffer.data[ConsoleRxBuffer.idx_out];
	next = (ConsoleRxBuffer.idx_out + 1) & (CONSOLE_BUFFER_SIZE - 1);
	ConsoleRxBuffer.idx_out = next;
	return ch;
#else
	#warning "Console not define"
	return 0;
#endif
}

/* get a line of interactive input */
char *PlatformGetLine(char *line, int length, const char *prompt)
{
    int ix = 0;
    char *cp = line;
	char ch;

    printf("\n%s", prompt);
	
	length -= 2;

    while (1)
	{
        ch = getch();
		if (ch == 0x08)
		{	// Backspace pressed
			if (ix > 0)
			{
				putchar(ch);
				putchar(' ');
				putchar(ch);
				--ix;
				--cp;
			}
			continue;
		}
        if (ch == 0x1B || ch == 0x03)
		{	// ESC character or Ctrl-C - exit
			printf("\nLeaving PicoC\n");
            break;
        }

		if (ix < length)
		{
			if (ch == '\r' || ch == '\n')
			{
				*cp++ = '\n';  // if newline, send newline character followed by null
				*cp = 0;
				putchar('\n');
				return line;
			}
			*cp++ = ch;
			ix++;
			putchar(ch);
		}
		else
		{
			printf("\n Line too long");
			printf("\n%s", prompt);
			ix = 0;
			cp = line;
		}
    }
    return NULL;
}

/* write a character to the console */
void PlatformPutc(unsigned char OutCh, union OutputStreamInfo *Stream)
{
    if (OutCh == '\n')
        putchar('\r');
    putchar(OutCh);
}

/* read a character */
int PlatformGetCharacter()
{
	return getch();
}

void PicocPlatformScanFile(Picoc *pc, const char *FileName)
{
	/*
	char *SourceStr = PlatformReadFile(pc, FileName);
    PicocParse(pc, FileName, SourceStr, strlen(SourceStr), TRUE, FALSE, TRUE, TRUE);
	*/
}

/* exit the program */
void PlatformExit(Picoc *pc, int RetVal)
{
    pc->PicocExitValue = RetVal;
	pc->PicocExitBuf[40] = 1;
    longjmp(pc->PicocExitBuf, 1);
}
