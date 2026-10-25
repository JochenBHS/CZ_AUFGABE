/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */

#include "main_global.h"
#include <add_fcn.h>

struct transfer add_loop_fcn(struct transfer values){

values.loop_counter++;
values.loop_counter_test++;
return values;

};
