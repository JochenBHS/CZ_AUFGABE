/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */
#include <windows.h> /* used for Mocked HW interface */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <../../../main_global.h>
#include "setDo.h"



struct transfer Run_Set_Do(struct transfer values){


    /* set digital outputs bits 210 of output register */
    /* mocked HW output on screen instead of HW output */
    /* state critical */

if(values.loop_counter_test < 12 && values.loop_counter_test !=0){

int8_t bit_temp=0;

    bit_temp = values.set_Do_Sig;
    bit_temp = bit_temp & 0b00000001;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (bit_temp == 0b00000001){
    /* set color to red  */
    SetConsoleTextAttribute(hConsole, 4 | FOREGROUND_INTENSITY);

    printf("RED LED / CRITICAL LEVEL OF TEMPERATURE\n");

    /* reset color to standard  */

    SetConsoleTextAttribute(hConsole, 7);
    }
    bit_temp = values.set_Do_Sig;
    bit_temp = bit_temp & 0b00000010;
    if (bit_temp == 0b00000010) {
    /* set color to green  */
    SetConsoleTextAttribute(hConsole, 10 | FOREGROUND_INTENSITY);

    printf("GREEN LED / NORMAL LEVEL OF TEMPERATURE\n");

    /* reset color to standard  */

    SetConsoleTextAttribute(hConsole, 7);
    }
    bit_temp = values.set_Do_Sig;
    bit_temp = bit_temp & 0b00000100;
    if (bit_temp == 4) {
    /* set color to yellow  */
    SetConsoleTextAttribute(hConsole, 14 | FOREGROUND_INTENSITY);

    printf("YELLOW LED / WARNING LEVEL OF TEMPERATURE\n");

    /* reset color to standard  */

    SetConsoleTextAttribute(hConsole, 7);
    }

}
    return values;

};
