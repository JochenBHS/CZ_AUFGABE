/* Project: Embedded Temperature Monitoring System
 * Client: CZ-SMT
 * Date: 2026/10
 * Author: Jochen Buck
 */

#ifndef MOCKEDEEPROM_H_INCLUDED
#define MOCKEDEEPROM_H_INCLUDED

void read_mockedEeprom_dev(int addr_dev);
const char* read_mockedEeprom_serial(int addr_serial);

#endif /* MOCKEDEEPROM_H_INCLUDED */
