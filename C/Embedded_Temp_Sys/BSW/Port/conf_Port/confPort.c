/* Project: Embedded Temperature Monitoring System
 * Client:  CZ-SMT
 * Date:    2026/10
 * Author:  Jochen Buck
 */

#include <../../../main_global.h>
#include <confPort.h>

struct init_transfer Init_Conf_Port(struct init_transfer values) {
    /* This is a dummy function, only for description purpose */
    /* Here in real embedded system Ports will be set         */
    /* e.g. dio -> output / input                             */
    /* e.g. Ports with multiple function will configured      */
    /* to according function e.g analog / digital             */
    
    return values;
}
