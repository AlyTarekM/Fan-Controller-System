/*
 * dcMotor.h
 *
 *  Created on: 6 Oct 2022
 *      Author: Aly Tarek
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "gpio.h"
#include "std_types.h"
#include "common_macros.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_PORT_ID PORTB_ID
#define DC_MOTOR_PIN1_ID PIN0_ID
#define DC_MOTOR_PIN2_ID PIN1_ID

/*******************************************************************************
 *                                Types                                 *
 *******************************************************************************/

typedef enum {
	Stop,CW,A_CW
}DcMotor_State;

/*******************************************************************************
 *                                Prototypes                                 *
 *******************************************************************************/

void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DCMOTOR_H_ */
