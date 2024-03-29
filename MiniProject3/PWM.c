/*
 * PWM.c
 *
 *  Created on: 6 Oct 2022
 *      Author: Aly Tarek
 */


#include<avr/io.h>
#include "std_types.h"

void TIMER0_INIT(uint8 set_duty_cycle)
{

    TCCR0=(1<<WGM01)|(1<<WGM00)|(1<<CS01)|(1<<COM01);
    TCNT0=0;
    OCR0=((float)set_duty_cycle/100)*255; /*duty cycle percentage of the generated
    * PWM signal will be in range from zero to hundred */
    DDRB|=(1<<PB3);

}
