/*
 * DIO__pro
gram.c
 *
 *  Created on: Mar 1, 2024
 *      Author: Rehab Khaled
 */


#include "DIO_private.h"
#include "DIO_configration.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Utils.h"
#include "DIO_interface.h"



void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	if(copy_u8PinDirection==DIO_PIN_HIGH)
	{
		switch(copy_u8PortId)
		{
		case DIO_PORTA	:
		SET_BIT(DIO_u8_DDRA_REG, copy_u8PinId);
	     break;
		case DIO_PORTB	:
		SET_BIT(DIO_u8_DDRB_REG, copy_u8PinId);
		break;
		case DIO_PORTC	:
       	SET_BIT(DIO_u8_DDRC_REG, copy_u8PinId);
	     break;
		case DIO_PORTD	:
       SET_BIT(DIO_u8_DDRD_REG, copy_u8PinId);
       break;


     	}



	}
	else if(copy_u8PinDirection==DIO_PIN_LOW)
	{
		switch(copy_u8PortId)
				{
				case DIO_PORTA	:
					CLR_BIT(DIO_u8_DDRA_REG, copy_u8PinId);
			     break;
				case DIO_PORTB	:
					CLR_BIT(DIO_u8_DDRB_REG, copy_u8PinId);
				break;
				case DIO_PORTC	:
					CLR_BIT(DIO_u8_DDRC_REG, copy_u8PinId);
			     break;
				case DIO_PORTD	:
					CLR_BIT(DIO_u8_DDRD_REG, copy_u8PinId);
		       break;


		     	}

	}


}
void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA	:

		if(copy_u8PinValue==DIO_PIN_LOW)
		{
			CLR_BIT(DIO_u8_PORTA_REG, copy_u8PinId);
		}

		else
		{
			 SET_BIT(DIO_u8_PORTA_REG, copy_u8PinId);
		}

	break;


	case DIO_PORTB	:
			if(copy_u8PinValue==DIO_PIN_LOW)
			{
				CLR_BIT(DIO_u8_PORTB_REG, copy_u8PinId);
			}

			else
			{
				 SET_BIT(DIO_u8_PORTB_REG, copy_u8PinId);
			}

		break;

	case DIO_PORTC	:

			if(copy_u8PinValue==DIO_PIN_LOW)
			{
				CLR_BIT(DIO_u8_PORTC_REG, copy_u8PinId);
			}

			else
			{
				 SET_BIT(DIO_u8_PORTC_REG, copy_u8PinId);
			}

		break;

	case DIO_PORTD	:

			if(copy_u8PinValue==DIO_PIN_LOW)
			{
				CLR_BIT(DIO_u8_PORTD_REG, copy_u8PinId);
			}

			else
			{
				 SET_BIT(DIO_u8_PORTD_REG, copy_u8PinId);
			}

		break;


	}

}

void DIO_voidGetPinValue  (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	switch(copy_u8PortId)
	{
	case DIO_PORTA:
		* copy_pu8PinValue = (DIO_u8_PINA_REG	 >> copy_u8PinId) & 0x01;
	break;

	case DIO_PORTB:
			* copy_pu8PinValue = (DIO_u8_PINB_REG	 >> copy_u8PinId) & 0x01;
		break;

	case DIO_PORTC:
			* copy_pu8PinValue = (DIO_u8_PINC_REG	 >> copy_u8PinId) & 0x01;
		break;

	case DIO_PORTD:
			* copy_pu8PinValue = (DIO_u8_PIND_REG	 >> copy_u8PinId) & 0x01;
		break;

	}

}
void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{

	switch(copy_u8PortId)
		{
		case DIO_PORTA:
			DIO_u8_PORTA_REG^= (1	 << copy_u8PinId);
		break;

		case DIO_PORTB:
			DIO_u8_PORTB_REG^= (1	 << copy_u8PinId);
			break;

		case DIO_PORTC:
			DIO_u8_PORTC_REG^= (1	 << copy_u8PinId);
			break;

		case DIO_PORTD:
			DIO_u8_PORTD_REG^= (1	 << copy_u8PinId);
			break;

		}



}


void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	 switch(copy_u8PortId)
	 {
		case DIO_PORTA:
	 DIO_u8_PORTA_REG|= (1 << copy_u8PinId);
	 break;

		case DIO_PORTB:
			 DIO_u8_PORTB_REG|= (1 << copy_u8PinId);
			 break;

		case DIO_PORTC:
			 DIO_u8_PORTC_REG|= (1 << copy_u8PinId);
			 break;

		case DIO_PORTD:
			 DIO_u8_PORTD_REG|= (1 << copy_u8PinId);
			 break;
	 }
}


/***********************************************API_PORT****************************/

void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{

		switch (copy_u8PortId)
		{
		case DIO_PORTA:
		 DIO_u8_PORTA_REG=copy_u8PortDirection;
		 break;

		case DIO_PORTB:
		 DIO_u8_PORTB_REG=copy_u8PortDirection;
		 break;


		case DIO_PORTC:
		 DIO_u8_PORTC_REG=copy_u8PortDirection;
			 break;

		case DIO_PORTD:
		 DIO_u8_PORTD_REG=copy_u8PortDirection;
		break;


		}

}


void DIO_voidSetPortValue  (u8 copy_u8PortId, u8 copy_u8PortValue)
{
	switch (copy_u8PortId)
			{
			case DIO_PORTA:
			 DIO_u8_PORTA_REG=copy_u8PortValue;
			 break;

			case DIO_PORTB:
				 DIO_u8_PORTB_REG=copy_u8PortValue;
			 break;


			case DIO_PORTC:
				 DIO_u8_PORTC_REG=copy_u8PortValue;
				 break;

			case DIO_PORTD:
				 DIO_u8_PORTD_REG=copy_u8PortValue;
			break;


			}
}

void DIO_voidGetPortValue (u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	switch (copy_u8PortId)
				{
				case DIO_PORTA:
					* copy_pu8PortValue = DIO_u8_PINA_REG;
				 break;

				case DIO_PORTB:
					* copy_pu8PortValue = DIO_u8_PINB_REG;
				 break;


				case DIO_PORTC:
					* copy_pu8PortValue = DIO_u8_PINC_REG;
					 break;

				case DIO_PORTD:
					* copy_pu8PortValue = DIO_u8_PIND_REG;
				break;


				}
}
void DIO_voidTogglePortValue(u8 copy_u8PortId)
{
	switch (copy_u8PortId)
					{
					case DIO_PORTA:
						DIO_u8_PORTA_REG ^= 0xff ;
					 break;

					case DIO_PORTB:
						DIO_u8_PORTB_REG ^= 0xff;
					 break;


					case DIO_PORTC:
						DIO_u8_PORTA_REG^= 0xff;
						 break;

					case DIO_PORTD:
						DIO_u8_PORTA_REG^= 0xff;
					break;


					}
}

void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
	switch (copy_u8PortId)
						{
						case DIO_PORTA:
							DIO_u8_PORTA_REG|= 0xff;
						 break;

						case DIO_PORTB:
							DIO_u8_PORTA_REG|= 0xff;
						 break;


						case DIO_PORTC:
							DIO_u8_PORTA_REG|= 0xff;
							 break;

						case DIO_PORTD:
							DIO_u8_PORTA_REG|= 0xff;
						break;


						}
}
