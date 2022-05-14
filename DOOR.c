#include "tm4c123gh6pm.h"
#include "LCD.h"
#include "stdlib.h"
#include "GPIO_INIT.h"
#include "timer_min_sec.h"
#include "functions.h"
#include "stdlib.h"

extern int s;
extern int m;
extern int SW1 ;
extern int SW2 ;
extern int SW3 ;
extern int temp_value_sec;
extern int temp_value_min;


//checking if any switches is pressed
	void switches ()
		{ 
      char button;	  
			SW3=SW3_input();
			SW2=SW2_input();
			SW1=SW1_input();
			
		if (SW3==0)	
		{
			if (SW1==0)
			{
				button='1';
				
				if (SW2==0 && SW3==0)
				{
					button='2';
				}
				else if (SW1==0)
				{
					
					button='3';
				}
			}