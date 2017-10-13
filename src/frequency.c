#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>


ViStatus status;


float fsweep(ViSession session, float StartFreq, float EndFreq)
{	float x=0;
	char commandString[128];

sprintf(commandString, "FREQ %f", StartFreq);

viWrite(session, commandString, sizeof commandString, VI_NULL);

sleep(2);
sleep(2);
sleep(2);

//for(float x=StartFreq; x<=EndFreq; x*10.)
//{
while(x<EndFreq){
x+=100.+StartFreq;
if(x>EndFreq)
x=EndFreq;
sprintf(commandString, "FREQ %f", x);

viWrite(session, commandString, sizeof commandString, VI_NULL);

printf("Frequency= %f \n", x );
sleep(2);

}

sleep(2);
sleep(2);
//}

printf("Done\n");

return 0;
	
}