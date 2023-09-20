
#include "stdint.h"

typedef volatile uint32_t vuint32_t ;

// Macros
#define SET_BIT(reg,bit) (reg=reg|(1<<bit))
#define CLEAR_BIT(reg,bit) (reg=reg&(~(1<<bit)))
#define READ_BIT(reg,bit) ((reg>>bit)&1)
#define TOGGLE_BIT(reg,bit)  (reg=reg^(1<<bit))
#define WRITE_BIT(reg,bit,value)  (reg=(reg&(~(1<<bit)))|(value<<bit))

// register address

// RCC
#define  RCC_BASE      0X40021000
#define  RCC_APB2ENR   (*(vuint32_t *)(RCC_BASE + 0X18))
#define  RCC_CR        *(vuint32_t *)(RCC_BASE + 0x0)
#define  RCC_CFGR      *(vuint32_t *)(RCC_BASE + 0x04)
#define  RCC_APB2RSTR      *(vuint32_t *)(RCC_BASE + 0x0C)

// GPIO
#define  GPIOA_BASE    0X40010800
#define  GPIOA_CRH     (*(vuint32_t *)(GPIOA_BASE + 0X04))
#define  GPIOA_CRL     (*(vuint32_t *)(GPIOA_BASE + 0x00))
#define  GPIOA_ODR     (*(vuint32_t *)(GPIOA_BASE + 0X0C))
#define  GPIOA_IDR     (*(vuint32_t *)(GPIOA_BASE + 0x08))

#define  GPIOB_BASE    0x40010C00
#define  GPIOB_CRH     (*(vuint32_t *)(GPIOB_BASE + 0X04))
#define  GPIOB_CRL     (*(vuint32_t *)(GPIOB_BASE + 0x00))
#define  GPIOB_ODR     (*(vuint32_t *)(GPIOB_BASE + 0X0C))
#define  GPIOB_IDR     (*(vuint32_t *)(GPIOB_BASE + 0x08))


// AFIO
#define  AFIO_BASE      0x40010000
#define  AFIO_EXTICR1   (*(vuint32_t *)(AFIO_BASE + 0X08))

// External interrupt
#define  EXI_BASE      0x40010400
#define  EXTI_IMR     (*(vuint32_t *)(EXI_BASE + 0X00))
#define  EXTI_RTSR     (*(vuint32_t *)(EXI_BASE + 0x08))
#define  EXTI_FTSR     (*(vuint32_t *)(EXI_BASE + 0x0C))
#define  EXTI_SWIER     (*(vuint32_t *)(EXI_BASE + 0x10))
#define  EXTI_PR       *(vuint32_t *)(EXI_BASE + 0x14)
//  NVIC
#define  NVIC_ISER0   *(vuint32_t*)(0xE000E100)

void RCC_init()
{
	// set clock for port A
	SET_BIT(RCC_APB2ENR, 2);
	// set clock for port B
	SET_BIT(RCC_APB2ENR, 3);
}

void GPIO_init()
{
	GPIOA_CRL=0;
	GPIOA_CRH=0;
	GPIOB_CRH=0;
	GPIOB_CRL=0;
	// PINA1 input pull up (single pressing)
	SET_BIT(GPIOA_CRL,6);
	// PINA13 input pull down ( multi pressing )
	SET_BIT(GPIOA_CRH,22);
	// PINB1 output (push pull Mode)
	GPIOB_CRL |= (0b01 << 4);
	GPIOB_CRL &= ~(0b11 << 6);
	// PINB13 output (open drain Mode)
	GPIOB_CRH |= (0b01 << 20);
	GPIOB_CRH &= ~(0b11 << 22);}

int main(void)
{
	RCC_init();
	GPIO_init();

	while(1)
	{
		if(((GPIOA_IDR & (1<<1)) >> 1) == 0)
		{
			TOGGLE_BIT(GPIOB_ODR, 1);
			while (((GPIOA_IDR & (1<<1)) >> 1) == 0); // single pressing
		}
		if(((GPIOA_IDR & (1<<13)) >> 13) == 1)
		{
			TOGGLE_BIT(GPIOB_ODR, 13);              // multi pressing
		}
		// delay
		for(int i=0 ; i<500 ; i++);
	}
}
