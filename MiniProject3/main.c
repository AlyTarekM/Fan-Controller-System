/*
 * main.c
 *
 *  Created on: 9 Oct 2022
 *      Author: Aly Tarek
 */
#include "avr/io.h"
#include "PWM.h"
#include "lm35_sensor.h"
#include "dcMotor.h"
#include "ADC.h"
#include "lcd.h"

int main(void){
	uint8 temp;
	LCD_init();
	ADC_ConfigType * Config_Ptr;
	Config_Ptr->prescaler= F_CPU_8;
	Config_Ptr->refVolt= INTERNAL;
	ADC_init(Config_Ptr);
	DcMotor_Init();
	LCD_moveCursor(0, 3);
	LCD_displayString("Fan Is");
	LCD_moveCursor(1, 3);
	LCD_displayString("Temp =  C");
	while(1){
		temp= LM35_getTemperature();
		LCD_moveCursor(0, 11);
		if(temp<30){
			LCD_displayString("OFF");
			DcMotor_Rotate(Stop, 0);

		}
		else if(temp > 30 && temp< 60 ){
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 25);
		}
		else if(temp>=60 && temp< 90){
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 50);
		}
		else if(temp>=90 && temp< 120){
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 75);
		}
		else if(temp>= 120){
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 100);
		}
		LCD_moveCursor(1, 8);
		LCD_intgerToString(temp);
	}
}

