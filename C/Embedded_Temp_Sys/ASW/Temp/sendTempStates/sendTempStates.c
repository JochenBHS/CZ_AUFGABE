/* Project: Embedded Temperature Monitoring System
 * Client:  CZ-SMT
 * Date:    2026/10
 * Author:  Jochen Buck
 */

#include <stdint.h>
#include <stdio.h>
#include <../../../main_global.h>
#include "sendTempStates.h"

struct transfer Run_send_temperature_state(struct transfer values) {
    values.receive_Do_Sig = values.temperature_state;
    return values;
}
