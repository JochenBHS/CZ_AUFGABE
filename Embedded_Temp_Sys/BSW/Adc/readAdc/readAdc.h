/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */

#ifndef READADC_H_INCLUDED
#define READADC_H_INCLUDED


struct init_transfer Init_Read_Adc(struct init_transfer values);
struct transfer Run_Read_Adc(struct transfer values);
const char* init_adc_timer_dma();

#endif /* READADC_H_INCLUDED  */
