/* 
 * Project: Embedded Temperature Monitoring System
 * Client:  CZ-SMT
 * Date:    2026/10
 * Author:  Jochen Buck
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <main_global.h>
#include "receiveDoSig.h"


struct transfer Run_Receive_Do_Sig(struct transfer values){

values.set_Do_Sig = values.receive_Do_Sig;

return values;
};