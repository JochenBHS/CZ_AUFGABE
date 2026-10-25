/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */


#ifndef QUANTADC_H_INCLUDED
#define QUANTADC_H_INCLUDED

#include <math.h>

struct init_transfer Init_Quant_Adc(struct init_transfer values);
struct transfer Run_Quant_Adc(struct transfer values);

#endif /* QUANTADC_H_INCLUDED */
