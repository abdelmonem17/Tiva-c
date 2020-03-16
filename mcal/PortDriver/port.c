
/*
 *
 *
 *  Created on: Jul 8, 2019
 *      Author: Abdelmonem Mostafa
 */
#define MAX_NUM_OF_CH_IN_PORT       8
#define MAX_NUM_OF_PORTS            6

#include "utils/Std_Types.h"
#include "utils/Bit_Math.h"
#include "config/port_cfg.h"
#include "mcal/mcu_hw.h"
#include "mcal/PortDriver/port_types.h"
#include "mcal/PortDriver/port.h"

extern Port_CfgType PortCfgArr[];

void PORT_init(void)
{
    volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                                   PORTC_BaseAddr,PORTD_BaseAddr,
                                                                   PORTE_BaseAddr,PORTF_BaseAddr};
    uint8 CfgArrIndex;
    uint8 PortId;
    Port_ChIdType ChannelId;
    uint8 ChannelPosInPort;
    volatile PORT_RegType* BaseAddr;

    for (CfgArrIndex = 0; CfgArrIndex < PORT_NUM_OF_ACTIVATED_CH; ++CfgArrIndex)
    {
        /*get channelID from CfgIndex*/
        ChannelId = PortCfgArr[CfgArrIndex].Channel;

        /*get PORTId using ChannelId*/
        PortId = ChannelId / MAX_NUM_OF_CH_IN_PORT;

        /*get baseAddress using PortId*/
        BaseAddr = BaseAddrArr[PortId];

        /*get Channel Position in PortGroup using ChannelId */
        ChannelPosInPort = ChannelId % MAX_NUM_OF_CH_IN_PORT;

        /* check if pin locked*/

        if(PortCfgArr[CfgArrIndex].LockStatus)
        {
            BaseAddr->GPIOLOCK = 0x4C4F434B;
            BaseAddr->GPIOCR   |=  (1<<ChannelPosInPort);
        }

        /*  select internal resistance option */
        switch(PortCfgArr[CfgArrIndex].AttachedRes)
        {
            case  Port_InternalAttach_PullUpRes :
                BaseAddr->GPIOPUR  |=  (1<<ChannelPosInPort);
            break;
            default:

            break;
        }



        /*NOTE use channel position in Group to write in corresponding bit in Desired Register */
        switch(PortCfgArr[CfgArrIndex].Mode)
        {

            case PORT_MODE_PIN_X_DIO:
                    /*disable alternative function*/
                BaseAddr->GPIOAFSEL &= ~(1<<ChannelPosInPort);
                   /*set the direction */
                switch(PortCfgArr[CfgArrIndex].Dir)
                {
                    case port_Dir_Output :
                        BaseAddr->GPIODIR |=(1<<ChannelPosInPort);
                        break;
                    default :
                        BaseAddr->GPIODIR &=~(1<<ChannelPosInPort);
                        break;
                }
                break;
                default :
                    /*enable alternative function */
                    BaseAddr->GPIOAFSEL |= (1<<ChannelPosInPort);
                    /*select the alternative function */
                                            /* clear 4 bits that used for this pin  & set the alternative function value */
                    BaseAddr->GPIOPCTL   &=  ( ~(0x0F << ChannelPosInPort) );
                    BaseAddr->GPIOPCTL   |=  ( (0x0F & PortCfgArr[CfgArrIndex].Mode ) << ChannelPosInPort) ;
                    break;
        }
        /*TODO: set channel direction */


        /*TODO: set channel mode */


        /*TODO: set Interrupt configuration */
        if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntDisable)
        {

            CLR_BIT(BaseAddr->GPIOIM, ChannelPosInPort);
        }
        else
        {
            SET_BIT(BaseAddr->GPIOIM, ChannelPosInPort);

        }

        /*TODO: set Internal Attachment configuration */


        /*TODO: set current strength configuration */


        /*Check if analog functionality is required*/
        if(PortCfgArr[CfgArrIndex].Mode != Port_Mode_AIN )
        {
            /* enable digital and disable ADC  */
            /*enable digit to this pin *             */
            BaseAddr->GPIOAMSEL &= ~(1<<ChannelPosInPort);
            BaseAddr->GPIODEN   |= (1<<ChannelPosInPort);

        }
        else
        {
            /* disable digital and enable ADC */
            BaseAddr->GPIODEN   &= ~(1<<ChannelPosInPort);
            BaseAddr->GPIOAMSEL |= (1<<ChannelPosInPort);

        }
    }
}
