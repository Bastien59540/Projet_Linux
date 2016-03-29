#include"led.h"

const char *IO_VAL1="/sys/class/gpio/gpio60/value";
const char *IO_VAL2="/sys/class/gpio/gpio30/value";
const char *LEDBrightness0="/sys/class/leds/beaglebone:green:usr0/brightness";
const char *LEDBrightness1="/sys/class/leds/beaglebone:green:usr1/brightness";
const char *LEDBrightness2="/sys/class/leds/beaglebone:green:usr2/brightness";
const char *LEDBrightness3="/sys/class/leds/beaglebone:green:usr3/brightness";

FILE *IO_value1 = NULL;
FILE *IO_value2 = NULL;
FILE *LEDHandle =NULL;

void LED_BB
//Led Beaglebone
{
if((LEDHandle = fopen(LEDBrightness0, "r+")) != NULL) 
{
 fprintf(LEDHandle, "%d", i);
 fclose(LEDHandle);
} 
if((LEDHandle = fopen(LEDBrightness1, "r+")) != NULL) 
{
 fprintf(LEDHandle, "%d", i);
fclose(LEDHandle);
}

if((LEDHandle = fopen(LEDBrightness2, "r+")) != NULL)
{
 fprintf(LEDHandle, "%d", i);
 fclose(LEDHandle);
}

if((LEDHandle = fopen(LEDBrightness3, "r+")) != NULL)
{
 fprintf(LEDHandle, "%d", i);
 fclose(LEDHandle);
}
}

void LED_VERTE(int i)
//Led verte
{
if((IO_value1 = fopen(IO_VAL1, "r+")) != NULL)
{
        fprintf(IO_value1, "%d", i);
        fclose(IO_value1);
}
}

void LED_ROUGE(int i)
//Led Rouge
{
if((IO_value2 = fopen(IO_VAL2, "r+")) != NULL)
{
        fprintf(IO_value2, "%d", i);
        fclose(IO_value2);
}
}
