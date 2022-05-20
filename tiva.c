#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "STD_TYPES.h"
#include "LCD.h"
#include "GPIO_INIT.h"
#include "KPD.h"
#include "functions.h"
#include "Pop_Corn.h"
#include "Beef-Chicken.h"
#include "take_cooking_time.h"

int s;
int m ;
int SW1 ;
int SW2 ;
int SW3 ;

int main()
{
	enum Options {PopCorn='A', Beef='B', Chicken='C', CustomTime='D'};
	u8 Return_;
	PortE_Init();
	PortB_Init();
	buzzer_init();
	Keypad_Init();
	init_lcd();
	Intialize_Systick();
	lcd_cmd(first_line1); //first line
	lcd_write_string("CSE211s Project");
<<<<<<< Updated upstream
	lcd_cmd(first_line2);
	lcd_write_string("Cooking Option:");
	Systick_n10ms(300); //delay
	
	
	
	
	if (SW3==00 && SW2 !=0)     //checking close door
		{ lcd_cmd(first_line1); 
			lcd_write_string("Click SWitch 2");
=======
	Systick_n10ms(100); //delay
	while(1)
  {
		SW3=SW3_input();
		SW1=(Read_SW()&0x10);
		
		if (SW3!=0)
		{
			lcd_cmd(lcd_Clear);
			lcd_cmd(first_line1); //first line
			lcd_write_string("Cooking Option");
>>>>>>> Stashed changes
			lcd_cmd(first_line2);
	  	lcd_write_string("  to start ");
		}
		
	else if ((SW3==00 && SW2 !=0)) //checking start operation 
	{
			while(1)
	{
	  lcd_cmd(first_line1); //first line
	  lcd_write_string("Cooking Option");
	  lcd_cmd(first_line2);
		lcd_write_string(" Enter letter:");
		
		Return_=Keypad_Getkey(); //Return_ contain the option pressed
		
		switch(Return_)
		{
			case 'A':  //popcorn cooking
			{
<<<<<<< Updated upstream
				pop_corn();
			  food_ready();
			}
			break;
			
			case 'B':  //beef cooking
			{
				 lcd_cmd(lcd_Clear);
				 Beef();
				 food_ready();
			}
			break;
			
			case 'C':  //chicken cooking
			{
				 lcd_cmd(lcd_Clear); 
				 chicken();
				 food_ready();
			}
			break;
			
			case 'D':  //manual cooking time
			{
				take_cooking_time();
				food_ready();
			}
			break;
=======
				case PopCorn:  //popcorn cooking
				{
					pop_corn();
				}
				break;
			
				case Beef:  //beef cooking
				{
				  Beef();
				}
				break;
			
				case Chicken:  //chicken cooking
				{
					chicken();
		  	}
			  break;
			
				case CustomTime:  //manual cooking time
				{
					Option_D();
				}
				break;
>>>>>>> Stashed changes
			
			default:
			{
				
			}
			break;
		}
	}
	
	
	else if (SW3 !=0)  // open door alert
	{
		lcd_cmd(first_line1); 
	  lcd_write_string("  Please close  ");
	  lcd_cmd(first_line2);
		lcd_write_string("    the door    ");
	}
}
