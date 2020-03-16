/*
 *
 *
 *  Created on: Jul 8, 2019
 *      Author: Abdelmonem Mostafa
 */


#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"


#include "../../config/nvic_cfg.h"
#include "../mcu_hw.h"
#include "nvic_types.h"
#include "nvic.h"


extern NVIC_CfgType NVIC_CfgArr[];


void NVIC_init(void)
{
    
   uint8 IrqX=0;
   uint8 au8_InterruptEnablex;
   uint8  au8_InterruptEnablex_Bit;

   uint8 au8_InterruptPriorityx;
   uint8  au8_IndexLocationInPRIx;
   uint8 aArryu8_InterruptPriorityLocationAtPRIReg[] = {5,13,21,29};

   for (IrqX=0 ; IrqX<NVIC_NUM_OF_ENABLED_INT ; IrqX++ )
   {
       /* select enable interrupt register */
       au8_InterruptEnablex     = NVIC_CfgArr[IrqX].IRQx / 32;
       /*   select bit in enable interrupt register        */
       au8_InterruptEnablex_Bit = NVIC_CfgArr[IrqX].IRQx % 32;
      INTERRUPT_EN_ADDRESS[au8_InterruptEnablex] |= 1<<au8_InterruptEnablex_Bit;

      /* select set interrupt priority register */
      au8_InterruptPriorityx     = NVIC_CfgArr[IrqX].IRQx / 4;
       /*   select bit in  interrupt register        */
      au8_IndexLocationInPRIx = NVIC_CfgArr[IrqX].IRQx % 4;

      INTERRUPT_PRI_ADDRESS[au8_InterruptPriorityx] |=( NVIC_CfgArr[IrqX].groupsSubGroups << (aArryu8_InterruptPriorityLocationAtPRIReg[au8_IndexLocationInPRIx]) );

   }



}



