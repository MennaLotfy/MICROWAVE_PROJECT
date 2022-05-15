#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "string.h"
#include "STD_TYPES.h"
#include "KPD.h"
#include "LCD.h"
#include "stdlib.h"
#include "GPIO_INIT.h"
#include "timer_min_sec.h"

#define Delay_Value 160000
extern int s;
extern int m;
extern int SW1 ;
extern int SW2 ;
extern int SW3 ;
extern int temp_value_sec;
extern int temp_value_min;







// convertin integers to characters

// Function to swap two numbers
void swap(char *x, char *y) {
    char t = *x; *x = *y; *y = t;
}
 
// Function to reverse `buffer[i…j]`
char* reverse(char *buffer, int i, int j)
{
    while (i < j) {
        swap(&buffer[i++], &buffer[j--]);
    }
 
    return buffer;
}
 
// Iterative function to implement `itoa()` function in C
char* itoa(int value, char* buffer, int base)
{
	int n = abs(value);
 
    int i = 0;
    // invalid input
    if (base < 2 || base > 32) {
        return buffer;
    }
 
    // consider the absolute value of the number
    
    while (n)
    {
        int r = n % base;
 
        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        }
        else {
            buffer[i++] = 48 + r;
        }
 
        n = n / base;
    }
 
    // if the number is 0
    if (i == 0) {
        buffer[i++] = '0';
    }
 
    // If the base is 10 and the value is negative, the resulting string
    // is preceded with a minus sign (-)
    // With any other base, value is always considered unsigned
    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }
 
    buffer[i] = '\0'; // null terminate string
 
    // reverse the string and return it
    return reverse(buffer, 0, i - 1);
}





// return switch three
int SW3_input(void){
	
	return(GPIO_PORTD_DATA_R&0x2);	
}
 















//runing
void runing_time_leds(void)
{
	PortF_Init ();
	GPIO_PORTF_DATA_R |=0x0E; 
}

// paused
void paused_time_leds (void)
{
		PortF_Init ();
	 while (SW1==0 || SW2==0)
	 {
		
		GPIO_PORTF_DATA_R |=0x0E; 
	  Systick_n10ms(300);
		GPIO_PORTF_DATA_R &=~0x0E;
		Systick_n10ms(300);
	 }
	
}





