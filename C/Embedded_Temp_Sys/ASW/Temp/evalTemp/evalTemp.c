/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */
#include <stdio.h>
#include <main_global.h>
#include "evalTemp.h"
#include "../receiveAdcSigTemp/receiveAdcSigTemp.h"
#include "../sendTempStates/sendTempStates.h"

struct transfer Run_evaluate_temperature(struct transfer values){

/* float values.eval_temp_celsius[counter-1] = 0.0; */
/* int8_t temperature_state = 0; */
/* int8_t counter = 0; */

/* set temperature state bits according to temperature value */
/* bits corresponding to following order                     */
/* states warning normal critical                            */
/* bit pos.  2      1      0                                 */
/* check if temperature is in normal (green) state           */
values.eval_temp_celsius = values.temp_celsius;

/* reset temperature state */
values.temperature_state = 0;

if(values.loop_counter_test < 12 && values.loop_counter_test !=0){


    /* check if temp is within normal (green) range */
if ((values.eval_temp_celsius < 85.0F) && (values.eval_temp_celsius >=5.0F)){
    values.temperature_state = values.temperature_state | 0b00000010;
}
else{
    values.temperature_state = values.temperature_state | 0b00000000;
}


/* check if temperature is in warning (yellow) state */
if (values.eval_temp_celsius >= 85.0F){
    values.temperature_state = values.temperature_state | 0b00000100;
}
else{
    values.temperature_state = values.temperature_state | 0b00000000;
}

/* check if temperature is in critical state */
if (values.eval_temp_celsius <5.0F || values.eval_temp_celsius >=105.0F){
    values.temperature_state = values.temperature_state | 0b00000001;

}

else{
    values.temperature_state = values.temperature_state | 0b00000000;
}

printf("temperature state variable%i\n", values.temperature_state);


}

return values;
}
