/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */
#include<stdio.h>
#include<../../../main_global.h>
#include <confEeprom.h>
#include <mockedEeprom.h>  /* header file of mocked HW Eeprom     */

/* adress of I2c slave (Eeprom) has to be defined                  */
#define EEPROM_ADDR 0x40

/* adress in Eeprom where serial number starts                    */
#define EEPROM_SERIAL_START_ADDR 0x90

 struct init_transfer Init_Conf_Eeprom(struct init_transfer values){

/* check if I2c Init was successful done in confI2c.c              */
if(values.I2c_Init_OK == TRUE){

/* begin communication with Eeprom, which is mocked HW in other SW fcn  */
/* begin communication with Eeprom by transmitting address              */

read_mockedEeprom_dev(EEPROM_ADDR);

/* sending address for read out serial number of EEPROM            */
/* and Hardware Revision A or B (last letter of serial number      */

const char *text = read_mockedEeprom_serial(EEPROM_SERIAL_START_ADDR);
    printf("EEPROM serial number is %s\n\n", text);
int length = strlen(text);
    printf("EEPROM Hardware Revision is: %s\n\n", text + (length - 1));
}

return values;
 };


