#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>
#include <voltage.h>
#include <frequency.h>
ViStatus status;
ViSession defaultRM;
ViSession viDG1022;
ViFindList fList;
ViUInt32 numInst;
ViChar desc[VI_FIND_BUFLEN];
ViChar resultBuffer[256];
ViUInt32 resultCount;

int initialization(void)
{
 status=viOpenDefaultRM(&defaultRM);
  
if(status != VI_SUCCESS) return EXIT_FAILURE;

status=viFindRsrc(defaultRM,"USB0::0x0400::0x09C4::DG1D182403417::INSTR", &fList,&numInst,desc);
sleep(2);

status=viOpen(defaultRM,desc,VI_NULL,VI_NULL,&viDG1022);
sleep(2);

status = viWrite(viDG1022,"*IDN?",10,VI_NULL);
sleep(2);

status = viRead(viDG1022, resultBuffer, 256, &resultCount);
//read response of Instrument

printf("Found instrument :%s \n",resultBuffer);

status = viWrite(viDG1022,"VOLT 2",6,VI_NULL);
sleep(2);

status = Voltage(viDG1022, 1);
sleep(2);

status = fsweep(viDG1022, 1000, 100000);
sleep(2);







  return 0;
}

int 
setup(void)
{

  return 0;
}

int
loop(void)
{

  return 0;
}

int
cleanup(void)
{
  return 0;
}

  
int  
main(void)  
{  

  int r = 0;
  r = initialization();
  if(!r) r = setup();
  if(!r) r = loop();
  r = cleanup();
  
  return(0);  
}  