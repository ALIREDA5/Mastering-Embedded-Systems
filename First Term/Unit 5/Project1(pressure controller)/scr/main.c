// High Pressure Dectection Project

#include <stdint.h>
#include <stdio.h>
#include "GPIO.h"
#include "Alarm.h"
#include "pressure_sensor.h"
#include  "Timer.h"
#include  "fifo.h"

int main (){
	// init queue
	Queue Pvalues;
	Queue_Create(&Pvalues);
	// init gpio
	GPIO_INITIALIZATION();
	// alarm is off initialiy
	Set_Alarm_actuator(1);
 	int Pval=0;
	while (1)
	{
	        Pval=getPressureVal();
		// storing pressure values in a queue
		Queue_Append(&Pvalues, Pval);
		if(Pval>=20)
		{
		// alarm is on for 60s 
			Set_Alarm_actuator(0);
			Delay(10000000);
		}
		Set_Alarm_actuator(1);	
	}
	return 0;

}
