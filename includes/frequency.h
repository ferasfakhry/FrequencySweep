#ifndef __FREQUENCY_H
#define __FREQUENCY_H


#include <stdio.h>
#include <stdlib.h>  
#include <visa.h>




float fsweep(ViSession session, float StartFreq, float EndFreq)
;

#endif