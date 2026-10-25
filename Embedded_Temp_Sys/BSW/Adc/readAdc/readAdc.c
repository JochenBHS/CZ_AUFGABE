/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */
#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <main_global.h>
#include "readAdc.h"

/* definition maximum buffer size per line (csv file)             */

#define MAX_LINE_SIZE 1024

/* definition of the function Init_Read_Adc                       */
/* purpose of this function is to define the connected HW-Rev     */
/* of the adc temperature sensor                                  */
/* 2 HW-Revs are allowed (A, B), the desired HW-Rev is read out   */
/* of a calibration file adc_sens.csv                             */
/* also error handling and error message printout (only for PC-   */
/* version of this program is performed                           */

struct init_transfer Init_Read_Adc(struct init_transfer values){

/* init adc channel, timer and DMA access to configure adc        */
/* every 100us with low jitter                                    */

printf("%s\n\n",init_adc_timer_dma());


/* check if values.init_status is 255 (ERROR)                    */

if(values.init_status != 255) {



/* selection of ADC sensor Rev A or Rev B with read Cal variable */
/* out of calibration file (*csv)                                */

FILE *file = fopen("CAL/adc_sens.csv", "r");
if (file == NULL) {
    /* error message mocked HW in real embedded sys could be blinking warning lamp */
    /* or display                                                                  */
    perror("error while opening adc_sens.csv\n");
    values.init_status = 255;  /* return init failure */
    return values;
}

/* variable for number of lines used in csv file*/
/* value is set to 1024 to get save to end of   */
/* new line character \n                        */
char line[MAX_LINE_SIZE];

/* fgets function reads in first line and       */
/* ignores it                                   */

if (fgets(line, sizeof(line), file) == NULL) {
fclose(file);

}

/* fgets function reads in second line, fgets   */
/* rembember line where it stopped              */

if (fgets(line, sizeof(line), file) != NULL) {

/* remove hidden signs and add string end \0    */
line[strcspn(line, "\r\n")] = '\0';

/* saves string/token until seperation symbol";"*/
char *cell1_row2 = strtok(line, ";");


if (cell1_row2 != NULL) {
    /* Output Print of selected HW Revision of Sensor, in real embedded */
    /* system HW, could be a e.g. display forseen                       */

    /* store string red out from csv in hw revision variable */
    values.adc_hw_rev = *cell1_row2;
    if (values.adc_hw_rev == 'A' || values.adc_hw_rev == 'B'){
    printf("Selection of Adc Sensor Hardware Revision: %c\n\n", values.adc_hw_rev);

    }else{
    /* No value in HW Revision */
    printf("Error, no valid Adc HW revision selected\n");
    values.init_status = 255;  /* return init failure */
    return values;
    }
    }else{
    printf("Error, no valid or empty adc_sens.csv\n");
    values.init_status = 255;  /* return init failure */
    return values;

    }
    }
    fclose(file);
}
    return values;

};




struct transfer Run_Read_Adc(struct transfer values){

/* if(values.adc_test_voltages_read != TRUE){ */

/* Read in of adc values from sensor (here replaced by csv file  */
/* out of value file (*csv)                                      */

FILE *file = fopen("CAL_SENS_VAL/Adc_Voltage_Values.csv", "r");
if (file == NULL) {
    /* error message mocked HW in real embedded sys could be blinking warning lamp */
    /* or display                                                                  */
    perror("error no adc voltages (error while opening Adc_Voltage_Values.csv)\n");
    values.init_status = 255;  /* return init failure */
    return values;
}

/* variable for number of lines used in csv file*/
/* value is set to 1024 to get save to end of   */
/* new line character \n                        */
char line[MAX_LINE_SIZE];

/*int counter = 0; */

if(values.loop_counter_test==0){
printf("Will read/check 11 different adc test voltages\n\n");
}
/* loop read in 11 cells first column */

/* algorithm, that reads out according line of csv file every function call */

if(values.loop_counter_test < 12){

int while_counter=0;

/* while loop with conditions is here, to skip lines in csv file every function call e.g. (call 1 -> line 1)    */
/* at second function call algorithm runs 2 times, first result gets ignored second is saved (call 2 -> line 2) */

    while(fgets(line, sizeof(line), file) != NULL && (values.loop_counter_test != while_counter||values.loop_counter_test==0)) {
     while_counter++;
      /* remove hidden signs and add string end \0    */
        line[strcspn(line, "\r\n")] = '\0';


       /* saves string/token until seperation symbol";"*/
        char *cell = strtok(line, ";");

        if (cell != NULL) {
        /* new solution */
           if(values.loop_counter_test==while_counter){
           values.read_adc_voltage = (float)atof(cell);
            printf("[%2d] %fV\n", values.loop_counter_test, values.read_adc_voltage);
           }
        }

    }
}
    if(values.loop_counter_test > 12){
    fclose(file);
    }


return values;

};


/* configure Adc Hardware, for prevent jitter while sampling      */
/* adc is configured directly on HW Timer dependency. From uC     */
/* internal HW Timer signal, adc gets triggered and as soon adc   */
/* is completed result get's saved via DMA (direct memory access) */
/* into RAM / output register of adc section of uc                */

const char* init_adc_timer_dma(){

/* init and configure Adc to HW Trigger from internal uc timer    */

/* select desired ADC, e.g. ADC1                                  */

/* adc_trigger_label = ADC1;                                      */

/* configure reaction of ADC to rising edge                       */

/* adc_edge_ADC1 = RISING;                                        */

/* select desired internal uC timer for triggering adc 1          */
/* for ADC1, e.g. TIMER3                                          */

/* adc_trigger_conf_label = UC_TIMER3                             */

/* config uc TIMER3 to trigger every 100us                        */

/* prescaler PSC is configured and devide system clock e.g. 10Mhz */
/* down to 1Mhz, because counting starts on 0, it will be devided */
/* by 10-1Mhz                                                     */
/* devision down to 1 Mhz is handy, because then every count step */
/* will be 1us                                                    */

/* set_prescaler_TIMER3 = 9;                                      */

/* now auto-reload register ARR has to be configured, since       */
/* sampling update is required every 100us and counting starts    */
/* from 0, also ARR has to be configured to 100-1                 */
/* also set counter Mode to counting up from 0 to 99              */
/* also activate internal signal trigger, when reaching count     */
/* limit                                                          */

/* set_ARR_TIMER3 = 99;                                           */

/* set_ARR_TIMER3_COUT_MODE = UP;                                 */

/* set_TRIGGER_LINE_TIMER3 = ACTIVE                               */

/* now activation of direct memory access has to be activated     */
/* DMA request after every single conversion result               */

/* set_DMA_request_Single_Conv_ADC1 = ENABLE                      */



return "ADC1 configured to 100us with DMA";
};
