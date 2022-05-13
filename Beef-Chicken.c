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