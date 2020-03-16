/*
 * SysCtr.c
 *
 *  Created on: Aug 2, 2019
 *      Author: Abdelmonem Mostafa
 */
#include "../mcu_hw.h"
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/SysCtr_cfg.h"

#define APINT_CODE 0x05FAUL
#define INTERNAL_CPU        16000000



void SysCtr_init(void)
{


    RCGCGPIO_REG.R0 = PORTA;
    RCGCGPIO_REG.R1 = PORTB;
    RCGCGPIO_REG.R2 = PORTC;
    RCGCGPIO_REG.R3 = PORTD;
    RCGCGPIO_REG.R4 = PORTE;
    RCGCGPIO_REG.R5 = PORTF;



    /*    UART   */
    RCGCUART_REG.R0  = UART0;
    RCGCUART_REG.R1  = UART1;
    RCGCUART_REG.R2  = UART2;
    RCGCUART_REG.R3  = UART3;
    RCGCUART_REG.R4  = UART4;
    RCGCUART_REG.R5  = UART5;
    RCGCUART_REG.R6  = UART6;
    RCGCUART_REG.R7  = UART7;

    /*  SSI config */
     RCGCSSI_REG.R0    =SSI0;
     RCGCSSI_REG.R1    =SSI1;
     RCGCSSI_REG.R2    =SSI2;
     RCGCSSI_REG.R3    =SSI3;


     /* I2C config*/

     RCGCI2C_REG.R0  =I2C0;
     RCGCI2C_REG.R1  =I2C1;
     RCGCI2C_REG.R2  =I2C2;
     RCGCI2C_REG.R3  =I2C3;



    /*   set code APINT */
    APINT = ( APINT & ( (0x0000FFFF) ) ) | (APINT_CODE<<16)  ;
    APINT = ( APINT & ( ~(0x7<<8) ) ) | (GROUPS_SUBGROUPS<<8)  ;


}

uint32 SysCtr_getSysClockFreq(void)
{
    return INTERNAL_CPU;

}

