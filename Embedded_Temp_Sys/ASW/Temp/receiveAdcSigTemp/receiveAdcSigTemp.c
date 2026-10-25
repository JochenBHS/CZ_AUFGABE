/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */
#include <stdio.h>
#include <main_global.h>
#include "receiveAdcSigTemp.h"

#define FORMULA_DIGIT_CELSIUS_REV_A(d) (d-25)
#define FORMULA_DIGIT_CELSIUS_REV_B(d) ((d/10)-25)

/* this function is an interface function from ASW   */
/* receiving adc digit values from BSW                */
/* in professional module should be done by a proper */
/* message concept                                   */
struct transfer Run_Receive_Adc_Sig_Temp(struct transfer values){

values.eval_temp_digits = values.receive_adc_digit_Temp;

return values;

 };


/* this function converts received digits to celsius */

struct transfer Run_Convert_Digits_Celsius(struct transfer values){

if(values.adc_hw_rev == 'A') {

if(values.loop_counter_test < 12 && values.loop_counter_test !=0) {

values.temp_celsius = FORMULA_DIGIT_CELSIUS_REV_A((float)values.eval_temp_digits); /* floor shoud be replaced later with round */
 /* safe all 11 digits */
printf("%f Deg Celsius\n",values.temp_celsius);

}
}

if(values.adc_hw_rev == 'B') {

if(values.loop_counter_test < 12 && values.loop_counter_test !=0) {

values.temp_celsius = (int)floor(FORMULA_DIGIT_CELSIUS_REV_B((float)values.eval_temp_digits)); /* floor should be replaced later with round */

 /* safe all 11 digits */
printf("%f Deg Celsius\n",values.temp_celsius);

}
}

   return values;

 };
