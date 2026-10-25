/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */

#include<../../../main_global.h>
#include <confPort.h>

/* here will be included I2c library                      */
/* e.g. #include <I2c.h>                                  */


 struct init_transfer Init_Conf_I2c(struct init_transfer values){

/* this is a dummy function, only for description purpose */
/* here in real embedded I2c bus will be configured       */

/* some function out of library to start I2c bus in Master */
/* Mode                                                    */

/* e.g. I2c.start();                                       */


/* some function out of library to set I2c bus clock freq. */
/* e.g. 100 khz                                            */

/* e.g. I2c.setClock(100000);                              */

/* also possibly some error handling with re-init after    */
/* failed init                                             */

/* if init was successful, status variable is set TRUE     */

values.I2c_Init_OK = TRUE;

return values;

};
