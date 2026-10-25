/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */

#define _GNU_SOURCE
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#include "main_global.h"
#include "quantAdc.h"

#define FORMULA_VOLTAGE_DIGIT_REV_A(v) (151/5)*(v)
#define FORMULA_VOLTAGE_DIGIT_REV_B(v) (1501/5)*(v)


struct init_transfer Init_Quant_Adc(struct init_transfer values){

/* this function would represent in embedded world e.g. the bit with of Adc Register */

if (values.adc_hw_rev == 'A'){

    values.quant_formula = 1;

}

if (values.adc_hw_rev == 'B'){

    values.quant_formula = 2;

}
return values;

};


struct transfer Run_Quant_Adc(struct transfer values){

if(values.quant_formula == 1) {


if(values.loop_counter_test < 12 && values.loop_counter_test !=0 ) {

values.adc_digit = (int)floor(FORMULA_VOLTAGE_DIGIT_REV_A(values.read_adc_voltage)); /* floor shoud be replaced later with round */
 /* safe all 11 digits */
printf("%i Digits\n",values.adc_digit);

}
}

if(values.quant_formula == 2) {


if(values.loop_counter_test < 12 && values.loop_counter_test !=0 ) {

values.adc_digit = (int)floor(FORMULA_VOLTAGE_DIGIT_REV_B(values.read_adc_voltage)); /* floor should be replaced later with round */

 /* safe all 11 digits */

printf("%i Digits\n",values.adc_digit);

}
}
   return values;
};

