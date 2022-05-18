#include "tm4c123gh6pm.h"
#include "LCD.h"
#include "stdlib.h"
#include "GPIO_INIT.h"
#include "timer_min_sec.h"
#include "functions.h"
#include "stdlib.h"
void switch_cases();
extern int s;
extern int m;
extern int SW1 ;
extern int SW2 ;
extern int SW3 ;
extern int temp_value_sec;
extern int temp_value_min;
char button;

//checking if any switches is pressed
void switches ()
{ 
	  while (1)
   	{		     	  
			SW3=SW3_input();
			if (SW3!=0)	
		  { 
				SW1=(Read_SW()&0x10);				
			  if (SW1==0) 
			  {
					button='1';
			switch(button)
			{
				case '1': 
				{
					pause ();
				 paused_time_leds();
				} break;
				
					case '2':
				{
				counts_min_sec(temp_value_min,temp_value_sec);
        runing_time_leds();					
				} break;
				
					case '3':
				{
					stop ();
					food_ready();
				} break;
			
			}
		}
	 else if (SW3==0)
		    {
					button='1';
					switch_cases();
					if(SW3_input()!=0)
					{
						  button='2';
							switch_cases();
							break;
					}
					break;
				}


				
			if (SW1 !=0)
			{
				break;
			}
	  }	
		
  }
		