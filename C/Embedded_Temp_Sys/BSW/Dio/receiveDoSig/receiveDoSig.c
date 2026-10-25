

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <main_global.h>
#include "receiveDoSig.h"


struct transfer Run_Receive_Do_Sig(struct transfer values){

values.set_Do_Sig = values.receive_Do_Sig;

return values;
};
