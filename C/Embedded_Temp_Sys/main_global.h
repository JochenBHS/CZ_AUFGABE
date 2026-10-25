/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */

#ifndef MAIN_GLOBAL_H_INCLUDED
#define MAIN_GLOBAL_H_INCLUDED
#include <windows.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>

/* data transfer structure for Run-Mode */

struct transfer{

float read_adc_voltage; /* variable of reading adc voltages from port (csv) file */
uint16_t adc_digit; /* variable to get digit value */
uint16_t receive_adc_digit_Temp; /* variable to get digit value */
uint16_t eval_temp_digits;
float temp_celsius; /* variable to get celsius value */
float eval_temp_celsius; /* variable to to eval celsius value */
uint8_t temperature_state;
uint8_t receive_Do_Sig;
uint8_t set_Do_Sig;

uint8_t loop_counter; /* loop counter and limiter for run mode */
uint8_t loop_counter_test; /* loop counter and limiter for run 12 loops */

char adc_hw_rev; /*char variable with adc HW revision value     */

int16_t adc_value;
uint8_t quant_formula; /* type of quantization formula */
                       /* A -> 1 */
                       /* B -> 2 */
uint8_t init_status; /* initialization status -> value 255 failed */
};

/* declaration of global data Run-Mode transfer variable */

struct transfer ti_1;

/* data transfer structure for init-Mode */

struct init_transfer{

uint8_t init_status; /* initialization status variable, forseen to e.g. identify number of int steps, error condition on value = 255 */
char adc_hw_rev; /*HW revision for adc_sens */
uint8_t quant_formula; /* type of quantization formula */
bool I2c_Init_OK;    /* check flag for successful I2c initialization */

};

/* declaration of global data init-Mode transfer variable */

struct init_transfer ti1;

#endif /* MAIN_GLOBAL_H_INCLUDED */
