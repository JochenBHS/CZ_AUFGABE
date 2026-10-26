/* Project: Embedded Temperature Monitoring System
 * Client:  CZ-SMT
 * Date:    2026/10
 * Author:  Jochen Buck
 */

#ifndef RECEIVEADCSIGTEMP_H_INCLUDED
#define RECEIVEADCSIGTEMP_H_INCLUDED

    struct transfer Run_Receive_Adc_Sig_Temp(struct transfer values);
    struct transfer Run_Convert_Digits_Celsius(struct transfer values);

#endif /* RECEIVEADCSIGTEMP_H_INCLUDED */
