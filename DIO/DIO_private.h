/*
 * DIO_private.
h
 *
 *  Created on: Mar 1, 2024
 *      Author: Rehab Khaled
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/* registers addresses */
#define DIO_u8_PORTA_REG		(*(volatile u8*) 0X3B)
#define DIO_u8_DDRA_REG			(*(volatile u8*) 0X3A)
#define DIO_u8_PINA_REG			(*(volatile u8*) 0X39)
#define DIO_u8_PORTB_REG		(*(volatile u8*) 0X38)
#define DIO_u8_DDRB_REG			(*(volatile u8*) 0X37)
#define DIO_u8_PINB_REG			(*(volatile u8*) 0X36)
#define DIO_u8_PORTC_REG		(*(volatile u8*) 0X35)
#define DIO_u8_DDRC_REG			(*(volatile u8*) 0X34)
#define DIO_u8_PINC_REG			(*(volatile u8*) 0X33)
#define DIO_u8_PORTD_REG		(*(volatile u8*) 0X32)
#define DIO_u8_DDRD_REG			(*(volatile u8*) 0X31)
#define DIO_u8_PIND_REG			(*(volatile u8*) 0X30)

#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
