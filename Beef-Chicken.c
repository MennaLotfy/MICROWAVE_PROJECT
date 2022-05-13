#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "LCD.h"
#include "KPD.h"
#include "GPIO_INIT.h"
#include "functions.h"

extern int s;
extern int m;
char N_K[3]={'0','0',0};
char * no_of_kilos=N_K;
char x='I'; //keypad input
char buffer[33];


void kilos_check_chicken (void)
	{
	  
		int int_no_of_kilos=0;
		float timer =0 ;
    no_of_kilos=itoa(0,buffer,10);
		m=0;
		s=0;
if ((x== '1')||(x== '2')||(x== '3')||(x== '4')||(x== '5')	||(x== '6')||(x== '7')||(x== '8')||(x== '9')) //integer from 1 to 9
		{
			lcd_cmd(lcd_Clear);
			lcd_gotoxy(6,1);
			lcd_write(x);
			lcd_gotoxy(7,1);
			lcd_write_string("kg");
			no_of_kilos[0]=x;
			int_no_of_kilos=atoi(no_of_kilos);
			timer=(int_no_of_kilos*12) ; //12 seconds 
			no_of_kilos=itoa(timer,buffer,10);
			Systick_n10ms(200);
			
       while (timer>=60)
			 { 
				 m=m+1;
				 timer=timer-60;
			 }
			 s=timer;
			counts_min_sec(m,s);
			 
	}
		
			else 
		{
			lcd_cmd(0x01);
			lcd_write_string("       Err");
			Systick_n10ms(200);
			lcd_cmd(lcd_Clear);
			lcd_write_string("Chicken weight:");
      x=Keypad_Getkey();
			kilos_check_chicken();
		}

	};