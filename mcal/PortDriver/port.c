
/*
 * port.c
 *
 *  Created on: Nov 12, 2019
 *      Author: Muammad Elzeiny
 */
#define MAX_NUM_OF_CH_IN_PORT       8
#define MAX_NUM_OF_PORTS            6

#include <tm4c123_firmware/utils/Std_Types.h>
#include "../../utils/Bit_Math.h"
#include "../../config/port_cfg.h"
#include "../mcu_hw.h"
#include <tm4c123_firmware/mcal/PortDriver/port_types.h>
#include <tm4c123_firmware/mcal/PortDriver/port.h>

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

        /*NOTE use channel position in Group to write in corresponding bit in Desired Register */
        switch(PortCfgArr[CfgArrIndex].Mode)
        {

            case PORT_MODE_PIN_X_DIO:
                BaseAddr->GPIODEN |=(1<<ChannelPosInPort);
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
                    /*   */
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
            /*TODO: enable digital and disable ADC  */


        }
        else
        {
            /*TODO: disable digital and enable ADC */

        }
    }
}
