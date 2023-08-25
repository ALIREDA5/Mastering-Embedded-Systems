/*
 * main.c
 *
 *  Created on: Aug 22, 2023
 *      Author: Ali Reda
 */

#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
#include "FIFO.h"

#define  DPrintf(...)   {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin); }

int main()
{
	int n;
	extern Queue q;
	Queue_Create(&q);
	while(1)
	{
		DPrintf("\n ==============================");
		DPrintf("\n\t Choose one of the following options \n");
		DPrintf("\n\t 1: ADD Student From File \n");
		DPrintf("\n\t 2: ADD Student Manually \n");
		DPrintf("\n\t 3: Find the student by given ID \n");
		DPrintf("\n\t 4: Find the student by given first name \n");
		DPrintf("\n\t 5: Find all the students registered in a course\n");
		DPrintf("\n\t 6: Count of students \n");
		DPrintf("\n\t 7: Update a student details by ID number\n");
		DPrintf("\n\t 8: Delete a student details by ID number \n");
		DPrintf("\n\t 9: Show all information \n");
		DPrintf("\n\t 10: Exit \n");
		DPrintf("\n\t Enter Option Number : ");

		scanf("%d", &n);
		DPrintf("\n ==============================");

		switch(n)
		{
		case 1:
			ADD_Student_From_File();
			break;
		case 2:
			ADD_Student_Manually();
			break;
		case 3:
			Find_student_by_ID();
			break;
		case 4:
			Find_student_by_first_name();
			break;
		case 5:
			Find_all_students_in_course();
			break;
		case 6:
			Count_of_students();
			break;
		case 7:
			Update_student();
			break;
		case 8:
			Delete_student();
			break;
		case 9:
			Show_all_information();
			break;
		case 10 :
			Exit();
			break;
		default :
			DPrintf("\n Wrong Option");
			break;
		}
	}


	return 0;
}

