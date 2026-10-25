/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */
#include <mockedEeprom.h>

/* these functions replace real HW of Eeprom and act as */
/* mocked HW                                            */

/* function read in address of EEPROM as SLAVE on I2c   */

void read_mockedEeprom_dev(int addr_dev){


 };

const char* read_mockedEeprom_serial(int addr_serial){

if(addr_serial == 0x90){
return "STM234REVA";
}
else{
return "0";
}
 };
