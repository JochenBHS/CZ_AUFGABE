/* 
 * Project: Embedded Temperature Monitoring System
 * Client:  CZ-SMT
 * Date:    2026/10
 * Author:  Jochen Buck
 */

#include <stdio.h>
#include <string.h>
#include "main_global.h"
#include "sendAdc.h"

/* 
 * This function is an interface function out of BSW.
 * Sending adc digit values to any asw module in a 
 * professional module should be done by a proper 
 * message concept.
 */
struct transfer Run_Send_Adc(struct transfer values)
{
    values.receive_adc_digit_Temp = values.adc_digit;

    return values;
};
