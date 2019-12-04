/*
 * SysCtr_cfg.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_
#define E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_
#include "../utils/STD_types.h"

/*TODO implement suitable container to store the followings
 *
 * which peripheral clock gate Enabled
 * Desired System clock Source
 * Desired System CLock Frequency
 * */

#define     CLOCK_ENABLE        1
#define     CLOCK_DISABLE       0

#define     PORTA               CLOCK_DISABLE
#define     PORTB               CLOCK_DISABLE
#define     PORTC               CLOCK_DISABLE
#define     PORTD               CLOCK_DISABLE
#define     PORTE               CLOCK_DISABLE
#define     PORTF               CLOCK_DISABLE

 #define    UART0                CLOCK_DISABLE
 #define    UART1                CLOCK_DISABLE
 #define    UART2                CLOCK_DISABLE
 #define    UART3                CLOCK_DISABLE
 #define    UART4                CLOCK_DISABLE
 #define    UART5                CLOCK_DISABLE
 #define    UART6                CLOCK_DISABLE
 #define    UART7                CLOCK_DISABLE

 #define    SSI0                 CLOCK_DISABLE
 #define    SSI1                 CLOCK_DISABLE
 #define    SSI2                 CLOCK_DISABLE
 #define    SSI3                 CLOCK_DISABLE

 #define    I2C0                  CLOCK_DISABLE
 #define    I2C1                  CLOCK_DISABLE
 #define    I2C2                  CLOCK_DISABLE
 #define    I2C3                  CLOCK_DISABLE


#define GROUPS8_SUBGROUPS1         0
#define GROUPS4_SUBGROUPS2         5
#define GROUPS2_SUBGROUPS4         6
#define GROUPS1_SUBGROUPS8         7

#define GROUPS_SUBGROUPS            GROUPS8_SUBGROUPS1

#endif /* E15_ARM_REPO_CONFIG_SYSCTR_CFG_H_ */
