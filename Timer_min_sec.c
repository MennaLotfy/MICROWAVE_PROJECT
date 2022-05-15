#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "string.h"
#include "KPD.h"
#include "LCD.h"
#include "stdlib.h"
#include "GPIO_INIT.h"
#include "functions.h"
#include "Beef-Chicken.h"



int temp_value_min;
char buffer2[33];
char M[3]={'0','0',0};
char* char_min=M;
extern int m;

//LCD display
void timer_display_minutes ()
{
	
	  lcd_gotoxy(9,2);
		lcd_write(':'); 
		lcd_gotoxy(8,2);
		lcd_write(char_min[1]);
		lcd_gotoxy(7,2);
		lcd_write(char_min[0]);
		
}


// Timer
void counts_min_sec(int min, int sec )
{ 
	
	 runing_time_leds();
	 s=sec;
			
	for (m = min ; m>=0 ; m--)
	{
		if (m>=10)
			{
		char_min=itoa(m, buffer2, 10);
			timer_display_minutes  ();
			}
	else if (m<10)
			{
	  	char_min=itoa(m, buffer2, 10);
			 char_min[1]=char_min[0];
			 char_min[0]='0';
		  timer_display_minutes ();
					}		
			
	
	// countinue seconds counting