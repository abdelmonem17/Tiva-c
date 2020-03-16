
#include "gpio.h"
#include "mcu_hw.h"
#include "Bit_Math.h"

    /* write to port */
#define OUT_A  PORTA_BaseAddr->GPIODATA
#define OUT_B  PORTB_BaseAddr->GPIODATA
#define OUT_C  PORTC_BaseAddr->GPIODATA
#define OUT_D  PORTD_BaseAddr->GPIODATA
#define OUT_E  PORTE_BaseAddr->GPIODATA
#define OUT_F  PORTF_BaseAddr->GPIODATA

    /* read port */
#define IN_A  PORTA_BaseAddr->GPIODATA
#define IN_B  PORTB_BaseAddr->GPIODATA
#define IN_C  PORTC_BaseAddr->GPIODATA
#define IN_D  PORTD_BaseAddr->GPIODATA
#define IN_E  PORTE_BaseAddr->GPIODATA
#define IN_F  PORTF_BaseAddr->GPIODATA





#define PORT_SET			0xFF
#define PORT_CLEAR			0
#define NIBBLE_HIGH_MASK	0xF0
#define NIBBLE_LOW_MASK		0x0F		





/****************************************************************************
*
*   @brief function write to GPIO PORTS
*   this function takes port profile and value
*   @params  name : port
*			 type :uint8
*   @params  name : value
*			 type :uint8
*
*   @return void
****************************************************************************/

void Gpio_PortWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case PORT_A :
			OUT_A =value;
			break;
		case PORT_B :
			OUT_B =value;
			break;
		case PORT_C :
			OUT_C =value;
			break;
		case PORT_D :
			OUT_D =value;
			break;
        case PORT_E :
            OUT_E =value;
            break;
        case PORT_F :
            OUT_F =value;
            break;
		default:
			/*		error option      */
			break;
	}
}

/****************************************************************************
*
*   @brief function toggle GPIO PORTS
*   this function takes port profile and value
*   @params  name : port
*			 type :uint8
*
*   @return void
****************************************************************************/
void Gpio_PortToggle(uint8 port)
{
	switch(port)
	{
		case PORT_A :
			//OUT_A ^=0xff;
			TOGGLE_BYTE(OUT_A);
			break;
		case PORT_B :
			//OUT_B ^=0xff;
			TOGGLE_BYTE(OUT_B);
			break;
		case PORT_C :
			//OUT_C ^=0xff;
			TOGGLE_BYTE(OUT_C);
			break;
		case PORT_D :
			//OUT_D ^=0xff;
			TOGGLE_BYTE(OUT_D);
			break;
        case PORT_E :
            //OUT_C ^=0xff;
            TOGGLE_BYTE(OUT_E);
            break;
        case PORT_F :
            //OUT_D ^=0xff;
            TOGGLE_BYTE(OUT_F);
            break;
		default:
			/*       error option          */
			break;
	}
}


/****************************************************************************
*
*   @brief function read GPIO PORTS
*   this function takes port profile
*   @params  name : port
*			 type :uint8
*
*   @return uint8
****************************************************************************/
uint8 Gpio_PortRead(uint8 port)
{
    uint8 data =0;
		switch(port)
		{
			case PORT_A :
				data = (uint8)IN_A ;
				break;
			case PORT_B :
                data =(uint8) IN_B ;
                break;
			case PORT_C :
                data = (uint8)IN_C ;
                break;
			case PORT_D :
                data = (uint8)IN_D ;
                break;
            case PORT_E :
                data = (uint8)IN_E ;
                break;
            case PORT_F :
                data = (uint8)IN_F ;
                break;
			default:
			/*           error option              */
			    break;

		}

		return data;
}






/****************************************************************************
*
*   @brief function write high or low to specific pins
*   this function takes port profile ,pins and value
*   @params  name : port
*			 type : uint8
*   @params  name : pins
*			 type : uint8
*   @params  name : value
*			 type : uint8
*
*   @return  void
****************************************************************************/
void Gpio_PinWrite_Same_Value(uint8 port, uint8 pins, uint8 value)
{
	switch(port)
	{
		case PORT_A :
			/*     clear location            ,set value ones or zeros  */
			OUT_A = ( OUT_A & (~pins) ) | ( (value ==HIGH) ? pins : 0 )  ;
			break;
		case PORT_B :
			/*     clear location            ,set value ones or zeros  */
			OUT_B = ( OUT_B & (~pins) ) | ( (value ==HIGH) ? pins : 0 )  ;
			break;
		case PORT_C :
			/*     clear location            ,set value ones or zeros  */
			OUT_C = ( OUT_C & (~pins) ) | ( (value ==HIGH) ? pins : 0 )  ;
			break;
		case PORT_D :
			/*     clear location            ,set value ones or zeros  */
			OUT_D = ( OUT_D & (~pins) ) | ( (value ==HIGH) ? pins : 0 )  ;
			break;
        case PORT_E :
            /*     clear location            ,set value ones or zeros  */
            OUT_E = ( OUT_E & (~pins) ) | ( (value ==HIGH) ? pins : 0 )  ;
            break;
        case PORT_F :
            /*     clear location            ,set value ones or zeros  */
            OUT_F = ( OUT_F & (~pins) ) | ( (value ==HIGH) ? pins : 0 )  ;
            break;
		default:
			/*     error option                                        */
			break;
	}
	
}



/****************************************************************************
*
*   @brief function write to specific pins
*   this function takes port profile ,pins and value
*   @params  name : port
*			 type : uint8
*   @params  name : pins
*			 type : uint8
*   @params  name : value
*			 type : uint8
*
*   @return  void
****************************************************************************/
void Gpio_PinWrite(uint8 port, uint8 pins, uint8 value)
{
	switch(port)
	{
		case PORT_A :
		/*      clear location            ,set value        */
			OUT_A = ( OUT_A & (~pins) ) | ( value & pins)  ;
			break;
		case PORT_B :
			/*      clear location            ,set value        */
			OUT_B = ( OUT_B & (~pins) ) | ( value & pins  )  ;
			break;
		case PORT_C :
			/*      clear location            ,set value        */
			OUT_C = ( OUT_C & (~pins) ) | ( value & pins )   ;
			break;
		case PORT_D :
			/*      clear location            ,set value        */
			OUT_D = ( OUT_D & (~pins) ) | ( value & pins )    ;
			break;
        case PORT_E :
            /*      clear location            ,set value        */
            OUT_E = ( OUT_E & (~pins) ) | ( value & pins )   ;
            break;
        case PORT_F :
            /*      clear location            ,set value        */
            OUT_F = ( OUT_F & (~pins) ) | ( value & pins )    ;
            break;
		default:
			/*                  error option                   */
			break;
	}
	
}


/****************************************************************************
*
*   @brief function toggle specific pins
*   this function takes port profile and pins
*   @params  name : port
*			 type : uint8
*   @params  name : pins
*			 type : uint8
*
*   @return  void
****************************************************************************/
void Gpio_PinToggle(uint8 port, uint8 pins)
{
	switch(port)
	{
		case PORT_A :
			OUT_A ^=pins;
			break;
		case PORT_B :
			OUT_B ^=pins;
		break;
		case PORT_C :
			OUT_C ^=pins;
			break;
		case PORT_D :
			OUT_D ^=pins;
		break;
        case PORT_E :
            OUT_E ^=pins;
            break;
        case PORT_F :
            OUT_F ^=pins;
        break;
			default:
		//error option
		break;
	}
}


/****************************************************************************
*
*   @brief function read a specific pin
*   this function takes port profile and pin
*   @params  name : port
*			 type : uint8
*   @params  name : pin
*			 type : uint8
*
*   @return  uint8
****************************************************************************/
uint8 Gpio_PinRead(uint8 port, uint8 pin)
{
    uint8 pinLevel=LOW;
	pin %= 8;
	switch(port)
	{
		case PORT_A :
			pinLevel =  ( ( IN_A & (1<<pin) ) !=0  ? HIGH :LOW) ;
			break;
        case PORT_B :
            pinLevel =  ( ( IN_B & (1<<pin) ) !=0  ? HIGH :LOW) ;
            break;
        case PORT_C :
            pinLevel =  ( ( IN_C & (1<<pin) ) !=0  ? HIGH :LOW) ;
            break;
        case PORT_D :
            pinLevel =  ( ( IN_D & (1<<pin) ) !=0  ? HIGH :LOW) ;
            break;
        case PORT_E :
            pinLevel =  ( ( IN_E & (1<<pin) ) !=0  ? HIGH :LOW) ;
            break;
        case PORT_F :
            pinLevel =  ( ( IN_F & (1<<pin) ) !=0  ? HIGH :LOW) ;
            break;
		default:
			/*           error option                    */
			break;
	}
	return pinLevel;
}


/****************************************************************************
*
*   @brief function write to to higher four pins in a port
*   this function takes port profile and direction
*   @params  name : port
*			 type : uint8
*   @params  name : value
*			 type : uint8
*
*   @return  void
****************************************************************************/
void Gpio_UpperNibbleWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case PORT_A :
			//clear upper ,		set upper	,shift value
			OUT_A = (OUT_A & NIBBLE_LOW_MASK) | (value<<4);
			break;
		case PORT_B :
			OUT_B = (OUT_B & NIBBLE_LOW_MASK) | (value<<4);
			break;
		case PORT_C :
			OUT_C = (OUT_C & NIBBLE_LOW_MASK) | (value<<4);
			break;
		case PORT_D :
			OUT_D = (OUT_D & NIBBLE_LOW_MASK) | (value<<4);
			break;
        case PORT_E :
            OUT_E = (OUT_E & NIBBLE_LOW_MASK) | (value<<4);
            break;
        case PORT_F :
            OUT_F = (OUT_F & NIBBLE_LOW_MASK) | (value<<4);
            break;
		default:
			/*        error option */
			break;
	}
}


/****************************************************************************
*
*   @brief function read higher four pins in a port
*   this function takes port profile and return port value
*   @params  name : port
*			 type : uint8
*   @params  name : direction
*			 type : uint8
*
*   @return  void
****************************************************************************/
uint8 Gpio_UpperNibbleRead(uint8 port)
{
    uint8 data;
	switch(port)
	{
		case PORT_A :
			data = (uint8)(IN_A >>4);
			break;
        case PORT_B :
            data = (uint8)(IN_B >>4);
            break;
        case PORT_C :
            data = (uint8)(IN_C >>4);
            break;
        case PORT_D :
            data = (uint8)(IN_D >>4);
            break;
        case PORT_E :
            data = (uint8)(IN_E >>4);
            break;
        case PORT_F :
            data = (uint8)(IN_F >>4);
            break;
		default:
			//error option
		   break;
	}
	return data;
}


/****************************************************************************
*
*   @brief function toggle higher four pins in a port
*   this function takes port profile
*   @params  name : port
*			 type : uint8
*
*   @return  void
****************************************************************************/
void Gpio_UpperNibbleToggle(uint8 port)
{
	switch(port)
	{
		case PORT_A :
			OUT_A  ^=NIBBLE_HIGH_MASK ;
			break;
		case PORT_B :
			OUT_B ^= NIBBLE_HIGH_MASK ;
			break;
		case PORT_C :
			OUT_C ^=NIBBLE_HIGH_MASK ;
			break;
		case PORT_D :
			OUT_D  ^=NIBBLE_HIGH_MASK ;
			break;
        case PORT_E :
            OUT_E ^=NIBBLE_HIGH_MASK ;
            break;
        case PORT_F :
            OUT_F  ^=NIBBLE_HIGH_MASK ;
            break;
		default:
			/*error option*/
		break;
	}
	
}



/****************************************************************************
*
*   @brief function write to lowest four pins in a port
*   this function takes port profile and direction
*   @params  name : port
*			 type : uint8
*   @params  name : value
*			 type : uint8
*
*   @return  void
****************************************************************************/
void Gpio_LowerNibbleWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case PORT_A :
			/*		clear upper ,		set upper	,value			*/
			OUT_A = (OUT_A & NIBBLE_HIGH_MASK) | (value & NIBBLE_LOW_MASK);
			break;
		case PORT_B :
			OUT_B = (OUT_B & NIBBLE_HIGH_MASK) | (value & NIBBLE_LOW_MASK);
			break;
		case PORT_C :
			OUT_C = (OUT_C & NIBBLE_HIGH_MASK) | (value & NIBBLE_LOW_MASK);
			break;
		case PORT_D :
			OUT_D = (OUT_D & NIBBLE_HIGH_MASK) | (value & NIBBLE_LOW_MASK);
			break;
        case PORT_E :
            OUT_E = (OUT_E & NIBBLE_HIGH_MASK) | (value & NIBBLE_LOW_MASK);
            break;
        case PORT_F :
            OUT_F = (OUT_F & NIBBLE_HIGH_MASK) | (value & NIBBLE_LOW_MASK);
            break;
		default:
			/*error option*/
			break;
	}
}


/****************************************************************************
*
*   @brief function toggle lowest four pins in a port
*   this function takes port profile and direction
*   @params  name : port
*			 type : uint8
*
*   @return  void
****************************************************************************/
void Gpio_LowerNibbleToggle(uint8 port)
{
	switch(port)
	{
		case PORT_A :
			/*clear upper ,		set upper	,shift value*/
			OUT_A  ^=NIBBLE_LOW_MASK ;
		break;
		case PORT_B :
			OUT_B ^= NIBBLE_LOW_MASK;
			break;
		case PORT_C :
			OUT_C ^= NIBBLE_LOW_MASK;
			break;
		case PORT_D :
			OUT_D  ^= NIBBLE_LOW_MASK;
			break;
        case PORT_E :
            OUT_E ^= NIBBLE_LOW_MASK;
            break;
        case PORT_F :
            OUT_F  ^= NIBBLE_LOW_MASK;
            break;
		default:
			/* error option         */
			break;
	}
}




/****************************************************************************
*
*   @brief function read lowest four pins in a port
*   this function takes port profile and direction
*   @params  name : port
*			 type : uint8
*
*   @return  void
****************************************************************************/

uint8 Gpio_LowerNibbleRead(uint8 port)
{
    uint8 data;
	switch(port)
	{
		case PORT_A :
			data = (uint8) (IN_A & 0x0f);
			break;
        case PORT_B :
            data = (uint8) (IN_B & 0x0f);
            break;
        case PORT_C :
            data = (uint8) (IN_C & 0x0f);
            break;
        case PORT_D :
            data = (uint8) (IN_D & 0x0f);
            break;
        case PORT_E :
            data = (uint8) (IN_E & 0x0f);
            break;
        case PORT_F :
            data = (uint8) (IN_F & 0x0f);
            break;
		default:
			//error option
			break;
	}
	return data;
}
