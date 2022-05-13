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