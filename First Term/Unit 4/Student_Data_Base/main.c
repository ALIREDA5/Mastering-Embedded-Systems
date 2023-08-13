/*
 * main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Ali Reda
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "string.h"

#define  DPrintf(...)   {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin); }

List_t l;

void display(Entry_t e)
{
	DPrintf("\n ==================== \n");
	printf("\n\t Student Name: %s", e.name);
	printf("\n\t Student ID: %d", e.ID);
	printf("\n\t Student Height: %.2f", e.height);
}

void ADD_Student();
void DELETE_Student();
void VIEW_All_Students();
void DELETE_ALL_Students();
void SEARCH_For_Student_Data();
void EDIT_Student_Data();


int main()
{
	int n;
	List_Create(&l);
	while(1)
	{
		DPrintf("\n ==============================");
		DPrintf("\n\t Choose one of the following options \n");
		DPrintf("\n\t 1: ADD_Student \n");
		DPrintf("\n\t 2: DELETE_Student \n");
		DPrintf("\n\t 3: VIEW_All_Students \n");
		DPrintf("\n\t 4: DELETE_ALL_Students \n");
		DPrintf("\n\t 5: SEARCH_For_Student_Data \n");
		DPrintf("\n\t 6: EDIT_Student_Data \n");
		DPrintf("\n\t Enter Option Number : ");

		scanf("%d", &n);
		DPrintf("\n ==============================");

		switch(n)
		{
		case 1:
			ADD_Student();
			break;
		case 2:
			DELETE_Student();
			break;
		case 3:
			VIEW_All_Students();
			break;
		case 4:
			DELETE_ALL_Students();
			break;
		case 5:
			SEARCH_For_Student_Data();
			break;
		case 6:
			EDIT_Student_Data();
			break;
		default :
			DPrintf("\n Wrong Option");
			break;
		}


	}




	return 0;
}

void ADD_Student()
{
	Entry_t s;
	DPrintf("\n\t Enter ID Number : ");
	scanf("%d", &(s.ID));
	DPrintf("\n\t Enter  Name : ");
	gets(s.name);
	DPrintf("\n\t Enter Height  : ");
	scanf("%f", &(s.height));
	List_Add_Element(&l, s);
}

void DELETE_Student()
{
	int pos;
	DPrintf("\n\t Enter Position at the list : ");
	scanf("%d", &pos);
	Entry_t s;
	List_Delete_Element(pos, &l, &s);
	DPrintf("\n\t Students %d is deleted from the list", pos);
}
void VIEW_All_Students()
{
	DPrintf("\n\t All Students Data");
	List_Traverse(&l, &display);
}
void DELETE_ALL_Students()
{
	List_Destroy(&l);
	DPrintf("\n\t All Students are deleted from the list");
}
void SEARCH_For_Student_Data()
{
	int ID;
	DPrintf("\n\t Enter Student ID : ");
	scanf("%d", &ID);
	Entry_t s;
	s=List_Search(&l, ID);
	display(s);
}
void EDIT_Student_Data()
{
	int ID;
	DPrintf("\n\t Enter Student ID (which you want to edit its information) : ");
	scanf("%d", &ID);
	Entry_t s;
	s.ID=ID;
	DPrintf("\n\t Enter  Name : ");
	gets(s.name);
	DPrintf("\n\t Enter Height  : ");
	scanf("%f", &(s.height));
	List_Edit_Element(&l, ID, s);
}

