/*
 * main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Ali Reda
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display(int e)
{
	printf("e = %d \n", e);
}

int main()
{
	Entry_t y;
	List_t l;
	List_Create(&l);
	int i;
	for(i=0; i<5; i++)
	{
		List_Add_Element(&l, i);
		printf("e = %d \n", i);
	}
	List_Insert_Element(2,&l,5);
	printf(" \n");
	int s=List_Size(&l);
	printf("s = %d \n", s);
	List_Traverse(&l, &display);
	if(List_Empty(&l)== List_non_empty)  List_Delete_Element(2,&l,&y);
	printf(" \n");
	List_Traverse(&l, &display);
	printf("y = %d \n", y);
	List_Destroy(&l);
	s=List_Size(&l);
	printf("s = %d \n", s);
	return 0;
}

