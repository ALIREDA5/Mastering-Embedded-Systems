
#include "pressure_sensor.h"

int getPressureVal(){
	return (GPIOA_IDR & 0xFF);
}
