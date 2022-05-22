#include "GPIO_INIT.h"
#include "tm4c123gh6pm.h"
#include <Math.h>
#define PI 3.14159265359
#include <string.h> // For strtok function
#include <stdlib.h> // For strtod function
#include "LCD.h"

/* IO Ports Initialization Functions Implementations*/




void PortB_Init ()
{ 
	SYSCTL_RCGCGPIO_R |= 0x00000002;
  while ((SYSCTL_PRGPIO_R&0x02) == 0){};
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= 0xFF;
	GPIO_PORTB_DIR_R = 0xFF;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTB_AMSEL_R = 0x00;
	GPIO_PORTB_AFSEL_R = 0x00; 
	GPIO_PORTB_PCTL_R = 0x00000000;
  GPIO_PORTB_PUR_R = 0x00;
  
}








void delay_ms(int t) // Milli seconds delay function
{
	int i;
	int j;
	for(i=0 ; i<t ; i++)
	{
		for(j=0; j<3180; j++)
		{
			
		}
	}
}