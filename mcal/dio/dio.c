

#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "dio.h"
#include "../mcu_hw.h"

#define MAX_NUM_OF_CH_IN_PORT       8
#define MAX_NUM_OF_PORTS            6

/*TODO: include the header file that contains register definitions */

volatile PORT_RegType* BaseAddrArr[MAX_NUM_OF_PORTS] = {PORTA_BaseAddr,PORTB_BaseAddr,
                                                                   PORTC_BaseAddr,PORTD_BaseAddr,
                                                                   PORTE_BaseAddr,PORTF_BaseAddr};




Std_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{

    Std_levelType ret;
    Dio_PortType PortId = ChannelId / MAX_NUM_OF_CH_IN_PORT;
    Dio_ChannelType ChannelPos = ChannelId % MAX_NUM_OF_CH_IN_PORT;


    ret =  ( ( BaseAddrArr[PortId]->GPIODATA & (1<<ChannelPos) ) !=0 );

    return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, Std_levelType Level)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    /*                                      clear location                set location with the value                */
    BaseAddrArr[PortId]->GPIODATA =  ( BaseAddrArr[PortId]->GPIODATA & (~(1<<ChannelPos) )  ) | (Level<<ChannelPos) ;
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
    uint8 ret;

    ret = BaseAddrArr[PortId]->GPIODATA;

    return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{

    BaseAddrArr[PortId]->GPIODATA = value;

}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
    Dio_PortType PortId = ChannelId / 8;
    Dio_ChannelType ChannelPos = ChannelId % 8;

    BaseAddrArr[PortId]->GPIODATA ^=(1<<PortId);

}
void Dio_FlipPort(Dio_PortType PortId)
{
    BaseAddrArr[PortId]->GPIODATA  ^=0xFF;;

}



