
#include "stdint.h"


// register address
typedef volatile unsigned int vuint32_t ;
#define  RCC_BASE      0X40021000
#define  GPIOA_BASE    0X40010800
#define  GPIOA_CRH     (*(vuint32_t *)(GPIOA_BASE + 0X04))
#define  GPIOA_ODR     (*(vuint32_t *)(GPIOA_BASE + 0X0C))
#define  RCC_APB2ENR   (*(vuint32_t *)(RCC_BASE + 0X18))
#define  RCC_CR        *(vuint32_t *)(RCC_BASE + 0x0)
#define  RCC_CFGR      *(vuint32_t *)(RCC_BASE + 0x04)


/************LAB2****************/

/*
 Configure Board to run with the
Following rates:
 APB1 Bus frequency 4MHZ
 APB2 Bus frequency 2MHZ
 AHB frequency 8 MHZ
 SysClk 8 MHZ
 Use only internal HSI_RC
*/


typedef union {
	vuint32_t   all_fields;
	struct {
		vuint32_t   reserved : 13;
		vuint32_t   P_13 : 1;
	}Pin;
} R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0X0C);


int main(void)
{
	// clock source control

	/*
	Bit 0 HSION: Internal high-speed clock enable
	Set and cleared by software.
	Set by hardware to force the internal 8 MHz RC oscillator ON when leaving Stop or Standby
	mode or in case of failure of the external 4-16 MHz oscillator used directly or indirectly as
	system clock. This bit cannot be reset if the internal 8 MHz RC is used directly or indirectly
	as system clock or is selected to become the system clock.
	0: internal 8 MHz RC oscillator OFF
	1: internal 8 MHz RC oscillator ON
	*/
	RCC_CR |= (1<<0);

	/*
	   Bit 24 PLLON: PLL enable
	Set and cleared by software to enable PLL.
	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	PLL clock is used as system clock or is selected to become the system clock.
	0: PLL OFF
	1: PLL ON
	 */
	// RCC_CR |= (1<<24) ;

		/*
		Bits 1:0 SW: System clock switch
	Set and cleared by software to select SYSCLK source.
	Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
	System is enabled).
	00: HSI selected as system clock
	01: HSE selected as system clock
	10: PLL selected as system clock
	11: not allowed
		 */
	RCC_CFGR |= (0b00<<0);

	/*Bits 7:4 HPRE: AHB prescaler
	Set and cleared by software to control the division factor of the AHB clock.
	0xxx: SYSCLK not divided
	1000: SYSCLK divided by 2
	1001: SYSCLK divided by 4
	1010: SYSCLK divided by 8
	1011: SYSCLK divided by 16
	1100: SYSCLK divided by 64
	1101: SYSCLK divided by 128
	1110: SYSCLK divided by 256
	1111: SYSCLK divided by 512*/
	RCC_CFGR |= (0b0000<<4);

	/*Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB low-speed clock
	(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/
	RCC_CFGR |= (0b100<<8);

	/*Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB high-speed clock
	(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/
	RCC_CFGR |= (0b101<<11);


	RCC_APB2ENR |= (1 << 2);
	GPIOA_CRH  &= 0XFF0FFFFF;
	GPIOA_ODR |= 0X00200000;

	while(1)
	{
		R_ODR -> Pin.P_13 =1;
		for(int i=0 ; i<5000 ; i++); // delay
		R_ODR -> Pin.P_13 =0;
		for(int i=0 ; i<5000 ; i++); // delay
	}


}
