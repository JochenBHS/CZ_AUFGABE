/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */
#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "main_global.h"
#include "readAdc.h"
#include "quantAdc.h"
#include "sendAdc.h"
#include "receiveAdcSigTemp.h"
#include "evalTemp.h"
#include "sendTempStates.h"
#include "setDo.h"
#include <confPort.h>
#include <confEeprom.h>
#include <confI2c.h>
#include <add_fcn.h>
#include <receiveDoSig.h>

int main()
{

    printf("Welcome to Embedded System Monitoring Temperature (10/2026 by Jochen Buck)\n\n");
    /* Init Routine */
    ti1 = Init_Conf_Port(ti1);
    ti1 = Init_Read_Adc(ti1);
    ti1 = Init_Quant_Adc(ti1);
    ti1 = Init_Conf_I2c(ti1);
    ti1 = Init_Conf_Eeprom(ti1);

 /* copy variables from init routine to Run routine */
 /* Copy struct message from init sequence to run sequence, maybe later to be removed */
    ti_1.quant_formula = ti1.quant_formula;
    ti_1.adc_hw_rev = ti1.adc_hw_rev;

 /* check if there is no initialization error */

    if(ti1.init_status != 255){
    printf("Initialization was successful! Now operation in Run Mode starts!\n\n");


 /* go into Run routine / idle task for 12 loops */
    while(ti_1.loop_counter_test <12){
    ti_1 = Run_Read_Adc(ti_1);
    ti_1 = Run_Quant_Adc(ti_1);
    ti_1 = Run_Send_Adc(ti_1);

    /* ASW Components */

    ti_1 = Run_Receive_Adc_Sig_Temp(ti_1);
    ti_1 = Run_Convert_Digits_Celsius(ti_1);
    ti_1 = Run_evaluate_temperature(ti_1);
    ti_1 = Run_send_temperature_state(ti_1);
    ti_1 = Run_Receive_Do_Sig(ti_1);
    ti_1 = Run_Set_Do(ti_1);
    ti_1 = add_loop_fcn(ti_1);
    }

}
printf("System shut down, execution ended\n");
    return 0;

}
