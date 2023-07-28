
/* startup code */


#include  <stdint.h>
#define   Stack_start_sp  0x20001000
extern int main(void);

void Rest_Handler (void);

void Default_Handler (void)
{
	Rest_Handler();
}

void NMI_Handler (void) __attribute__((weak,alias ("Default_Handler")));
void H_Fault_Handler (void) __attribute__((weak,alias ("Default_Handler")));
void MM_Handler (void) __attribute__((weak,alias ("Default_Handler")));
void Bus_Handler (void) __attribute__((weak,alias ("Default_Handler")));
void Usage_Fault_Handler (void) __attribute__((weak,alias ("Default_Handler")));


uint32_t Vectors[] __attribute__((section(".vectors"))) =
{
Stack_start_sp,
(uint32_t) &Rest_Handler,
(uint32_t) &NMI_Handler,
(uint32_t) &H_Fault_Handler,
(uint32_t) &MM_Handler,
(uint32_t) &Bus_Handler,
(uint32_t) &Usage_Fault_Handler
};

extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;

void Rest_Handler (void)
{
	// copy data from flash to sram
	unsigned int Data_Size = (unsigned char *)&_E_data - (unsigned char *)&_S_data;
	unsigned char* P_scr = (unsigned char *)&_E_text;
	unsigned char* P_dst = (unsigned char *)&_S_data;
	for(int i=0 ; i< Data_Size ; i++)
	{
		*((unsigned char*) P_dst++) = *((unsigned char*) P_scr++) ;
	}
	
	// init bss with zero in sram
	unsigned int bss_Size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
	 P_scr = (unsigned char *)&_S_bss;
	 for(int i=0 ; i< bss_Size ; i++)
	{
		*((unsigned char*) P_dst++) = 0 ;
	}
	
	// Jump to main
	main();
}








