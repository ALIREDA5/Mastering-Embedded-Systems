/*
 * IncFile1.h
 *
 * Created: 9/20/2023 11:19:32 PM
 *  Author: Ali Reda
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#define SET_BIT(reg,bit) (reg |=(1<<bit))
#define CLEAR_BIT(reg,bit) (reg &=(~(1<<bit)))
#define READ_BIT(reg,bit) ((reg>>bit)&1)
#define TOGGLE_BIT(reg,bit)  (reg ^=(1<<bit))
#define WRITE_BIT(reg,bit,value)  (reg=(reg&(~(1<<bit)))|(value<<bit))

#endif /* INCFILE1_H_ */