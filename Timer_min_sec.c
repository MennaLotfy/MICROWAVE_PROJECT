#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "string.h"
#include "KPD.h"
#include "LCD.h"
#include "stdlib.h"
#include "GPIO_INIT.h"
#include "functions.h"
#include "Beef-Chicken.h"
#include "Door.h"

int temp_value_sec;	
int temp_value_min;
char buffer2[33];
char M[3]={'0','0',0};
char S[3]={'0','0',0};
char* char_min=M;
char*	char_sec=S;
extern int s;
extern int m;
extern int SW1 ;
extern int SW2 ;
extern int SW3 ;


//LCD display
void timer_display_seconds ()
{
		lcd_gotoxy(10,2);
		lcd_write(char_sec[0]);
		lcd_gotoxy(11,2);
		lcd_write(char_sec[1]);
		Systick_n10ms(50); //delay
}


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
			for (; s>=0 ;s--)
		{
			if (s>=10)
			{
				
		char_sec=itoa(s, buffer2, 10);	
			timer_display_seconds ();
				temp_value_sec=s;
				temp_value_min=m;
				switches();
			}
			else if (s<10)
			{
		char_sec=itoa(s, buffer2, 10);
				char_sec[1]=char_sec[0];
				char_sec[0]='0';
			timer_display_seconds ();
				temp_value_sec=s;
				temp_value_min=m;
				switches();
					}
		}
		if (m>=10)
			{
				s=59;
				temp_value_sec=s;
				temp_value_min=m;
		char_min=itoa(m, buffer2, 10);
			timer_display_minutes ();
				switches();
			}
		
						s=59;
						temp_value_sec=s;
				    temp_value_min=m;
	    	char_min=itoa(m, buffer2, 10);
				    char_min[1]=char_min[0];
				    char_min[0]='0';
			      timer_display_minutes ();
						switches();
					
			}
		}

	
	// countinue seconds counting