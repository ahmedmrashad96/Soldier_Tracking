/*
 * INTERRUPT.h
 *
 *  Created on: Dec 21, 2019
 *      Author: Ahmed Rashad
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define SREG (*((volatile uint8 *)(0x5f)))
#define Enable_Global_Interrupt()  SREG|=0x80;
#define Disable_Global_Interrupt() SREG&=0x7f;
#define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
#define _VECTOR(N) __vector_ ## N

#define RESET_VECTOR_NUM 		_VECTOR( 0)
#define INT0_VECTOR_NUM 		_VECTOR( 1)
#define INT1_VECTOR_NUM 		_VECTOR( 2)
#define INT2_VECTOR_NUM 		_VECTOR( 3)
#define TIMER2_COMP_VECTOR_NUM	_VECTOR( 4)
#define TIMER2_OVF_VECTOR_NUM 	_VECTOR( 5)
#define TIMER1_CAPT_VECTOR_NUM 	_VECTOR( 6)
#define TIMER1_COMPA_VECTOR_NUM _VECTOR( 7)
#define TIMER1_COMPB_VECTOR_NUM _VECTOR( 8)
#define TIMER1_OVF_VECTOR_NUM 	_VECTOR( 9)
#define TIMER0_COMP_VECTOR_NUM 	_VECTOR(10)
#define TIMER0_OVF_VECTOR_NUM 	_VECTOR(11)
#define SPI_STC_VECTOR_NUM 		_VECTOR(12)
#define USART_RXC_VECTOR_NUM 	_VECTOR(13)
#define USART_UDRE_VECTOR_NUM 	_VECTOR(14)
#define USART_TXC_VECTOR_NUM 	_VECTOR(15)
#define ADC_VECTOR_NUM 			_VECTOR(16)
#define EE_RDY_VECTOR_NUM 		_VECTOR(17)
#define ANA_COMP_VECTOR_NUM 	_VECTOR(18)
#define TWI_VECTOR_NUM 			_VECTOR(19)
#define SPM_RDY_VECTOR_NUM		_VECTOR(20)



#endif /* INTERRUPT_H_ */

