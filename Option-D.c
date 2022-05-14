#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "string.h"
#include "KPD.h"
#include "LCD.h"
#include "stdlib.h"
#include "GPIO_INIT.h"
#include "functions.h"

void Option_D()
{
	uint32_t take_cooking_time_return,SW;
	lcd_cmd(lcd_Clear);
	lcd_cmd(first_line1);
	Vaild:
	lcd_write_string("Cooking Time?");
	take_cooking_time_return=take_cooking_time();
	if(take_cooking_time_return==1)
	{
		while(1)
		{
			if((Read_SW()&0x10)==0x00)
			{
				GPIO_PORTF_DATA_R|=Red;
				lcd_cmd(lcd_Clear);
			}
			if((Read_SW()&0x01)==0x00)
			{
				GPIO_PORTF_DATA_R|=Blue;
				//start timer
				lcd_write_string("  Cooking Done  ");
				break;
			}
		}
	}
	
	else if(take_cooking_time_return==0)
	{
		lcd_cmd(lcd_Clear);
 	  lcd_write_string("Enter valid time");
		delay_ms(6000);
		lcd_cmd(lcd_Clear);
		goto Vaild;
	}
}