#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>


ViStatus status;


float Voltage(ViSession session, float volt)
{
	char commandString[128];

sprintf(commandString, "VOLT %f", volt);

viWrite(session, commandString, sizeof commandString, VI_NULL);

return 0;
	
}