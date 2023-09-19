
#include "stdint.h"

typedef volatile uint32_t vuint32_t ;

// Macros
#define SET_BIT(reg,bit) (reg=reg|(1<<bit))
#define CLEAR_BIT(reg,bit) (reg=reg&(~(1<<bit)))
#define READ_BIT(reg,bit) ((reg>>bit)&1)
#define TOGGLE_BIT(reg,bit)  (reg=reg^(1<<bit))
#define WRITE_BIT(reg,bit,value)  (reg=(reg&(~(1<<bit)))|(value<<bit))

// register address
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

#define  NVIC_ISER0   *(vuint32_t*)(0xE000E100)



int main(void)
{
	// to select the source input for EXTI0 external interrupt
	CLEAR_BIT(AFIO_EXTICR1,0);
	CLEAR_BIT(AFIO_EXTICR1,1);
	CLEAR_BIT(AFIO_EXTICR1,2);
	CLEAR_BIT(AFIO_EXTICR1,3);

	// enable EXTI line 0 (Mask 1)
	SET_BIT(EXTI_IMR,0);

	// Rising trigger for EXTI line 0
	SET_BIT(EXTI_RTSR,0);

	// set clock for port A
	SET_BIT(RCC_CR,0);
	SET_BIT(RCC_APB2ENR, 2);
	SET_BIT(RCC_APB2ENR, 0);

	// enable NVIC line 0
	SET_BIT(NVIC_ISER0,6);

	// GPIO A
	// set pin 13 as output
	GPIOA_CRH  &= 0XFF0FFFFF;
	GPIOA_ODR |= 0X00200000;
	// set pin 0 as floating input
	CLEAR_BIT(GPIOA_CRL,0);
	CLEAR_BIT(GPIOA_CRL,1);
	SET_BIT(GPIOA_CRL,2);

	while(1);

}

void EXTI0_IRQHandler(void)
{
	// toggle pin 13
	TOGGLE_BIT(GPIOA_ODR, 13);
	// Clear pending request
	SET_BIT(EXTI_PR,0);
}
