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
	u8 Return_;
	PortE_Init();
	PortB_Init();
	buzzer_init();
	Keypad_Init();
	init_lcd();
	Intialize_Systick();
	lcd_cmd(first_line1); //first line
	lcd_write_string("CSE211s Project");
	lcd_cmd(first_line2);
	lcd_write_string("Cooking Option:");
	Systick_n10ms(300); //delay
	
}