/*
 * fun.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Ali Reda
 */

#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"
#include "fun.h"
#include "string.h"

#define  DPrintf(...)   {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin); }

Queue q;

// ****************************** Sub functions ********************************* //

void display(Queue_Type* e)
{
	int i=0;
	DPrintf("\n ==================== \n");
	DPrintf("\n\t Student First Name: %s", e->fname);
	DPrintf("\n\t Student Last Name: %s", e->lname);
	DPrintf("\n\t Student ID: %d", e->student_ID);
	DPrintf("\n\t Student GPA: %.2f", e->GPA);
	while(i<e->ncourses)
	{
		printf("\n\t Student course_ID: %d", e->course_ID[i]);
		i++;
	}
}

void display_c(Queue_Type* e)
{

	DPrintf("\n\t Student First Name: %s", e->fname);
	DPrintf("\n\t Student Last Name: %s", e->lname);
	DPrintf("\n\t Student ID: %d", e->student_ID);
	DPrintf("\n\t Student GPA: %.2f", e->GPA);
	DPrintf("\n ================ \n");
}

void ID_search(Queue_Type* e, void* ID)
{
	static int loop=0;
	int count=0;
	int id = *(int *)ID;
	while(loop < Queue_Size(&q))
	{
		if(e->student_ID == id)
		{
			display(e);
			count++;
		}
		loop++;
	}
	if( count == 0)
	{
		DPrintf("\n\t [ERROR] ID number not found ");
		loop=0;
	}
}

void ID_Delete(Queue_Type* e, void* ID)
{
	static int loop=0;
	int id = *(int *)ID;
	if(e->student_ID == id)
	{
		Queue_Delete_Element(&q, e, loop+1);
		DPrintf("\n\t Element deleted ");
		loop=0;
	}
	loop++;

	if(loop == Queue_Size(&q))
	{
		DPrintf("\n\t [ERROR] ID number not found ");
		loop=0;
	}
}

void ID_Update(Queue_Type* e, void* ID)
{
	static int loop=0;
	static int count=0;
	int id = *(int *)ID;
	if(loop < Queue_Size(&q))
	{
		if(e->student_ID == id)
		{
			int m,n;
			DPrintf("\n\t Choose one option to update \n");
			DPrintf("\n 1: First Name \n");
			DPrintf("\n 2: Last Name \n");
			DPrintf("\n 3: Student ID \n");
			DPrintf("\n 4: GPA \n");
			DPrintf("\n 5: Courses \n");
			DPrintf("\n - your option :");
			scanf("%d", &m);
			int i=0;
			switch (m)
			{
			case 1 :
				DPrintf("\n\t Enter First Name : ");
				gets(e->fname);
				count++;
				break;
			case 2 :
				DPrintf("\n\t Enter last Name : ");
				gets(e->lname);
				count++;
				break;
			case 3 :
				DPrintf("\n\t Enter Student ID : ");
				scanf("%d", &(e->student_ID));
				count++;
				break;
			case 4 :
				DPrintf("\n\t Enter GPA : ");
				scanf("%f", &(e->GPA));
				count++;
				break;
			case 5 :
				while(i<e->ncourses)
				{
					DPrintf("\n\t %d. Course ID : %d \n", i+1, e->course_ID[i]);
					i++;
				}
				DPrintf("\n\t Enter your option : ");
				scanf("%d", &n);
				DPrintf("\n\t Enter your new course ID : ");
				scanf("%d", &(e->course_ID[n]));
				count++;
				break;
			}
		}
		loop++;
	}
	if(count==0)
	{
		DPrintf("\n [ERROR] ID number not found ");
		loop=0;
	}
	else
	{
		DPrintf("\n [INFO] Student info updated ");
		loop=0;
		count=0;
	}
}

void Fname_search(Queue_Type* e, void* fname)
{
	int count=0;
	static int loop=0;
	char* f_name=(char *)fname;
	while(loop < Queue_Size(&q))
	{
		if(!strcmp(e->fname, f_name))
		{
			display(e);
			count++;
		}
		loop++;
	}
	if( count == 0)
	{
		DPrintf("\n\t [ERROR] First name not found ");
		loop=0;
	}
	else if(loop == Queue_Size(&q) && count != 0)
	{
		DPrintf("\n\t There are %d Students with the name %s ", count, f_name);
	}
}

// fun to display students enrolled in a course assuming there is no course ID =0

void Course_search(Queue_Type* e, void* id_c)
{
	int i=0;
	static int count=0;
	static int loop=0;
	int id=*(int*)id_c;
	if(loop<Queue_Size(&q))
	{
		while(i < e->ncourses)
		{
			if(e->course_ID[i] == id && count==0)
			{
				DPrintf("\n ==================== \n");
				DPrintf("\n Students Details \n");
				display_c(e);
				count++;
			}
			else if(e->course_ID[i] == id && count!=0)
			{
				display_c(e);
				count++;
			}
			i++;
		}
		loop++;
	}
	if(loop==Queue_Size(&q)&&count!=0)
	{
		DPrintf("\n [INFO] : Total number of Students enrolled :  %d \n", count);
		count=0;
		loop=0;
	}
	else if(loop==Queue_Size(&q)&&count==0)
	{
		DPrintf("\n [ERROR] : Course ID not found \n");
		loop=0;
	}
}

// ******************************** Functions Used in Main program ********************************* //

void ADD_Student_From_File()
{


}


void ADD_Student_Manually()
{
	char c;
	Queue_Type s;
	DPrintf("\n\t Enter First Name : ");
	gets(s.fname);
	DPrintf("\n\t Enter Last Name : ");
	gets(s.lname);
	DPrintf("\n\t Enter Student ID Number : ");
	scanf("%d", &(s.student_ID));
	DPrintf("\n\t Enter GPA : ");
	scanf("%f", &(s.GPA));
	s.ncourses=0;
	DPrintf("\n\t Enter Course ID Number : ");
	scanf("%d", &(s.course_ID[0]));
	s.ncourses ++;
	while(1)
	{
		int i=1;
		DPrintf("\n\t Do you want to enter another Course ID (y or n) : ");
		scanf("%c", &c);
		if(c=='y')
		{
			DPrintf("\n\t Enter Course ID Number : ");
			scanf("%d", &(s.course_ID[i]));
			s.ncourses ++;
			i++;
		}
		else if(c=='n')
			break;
	}
	Queue_Append(&q, s);
	DPrintf("\n\t[INFO] Student details are added successfully  ");
}


void Find_student_by_ID()
{
	int id;
	DPrintf("\n\t Enter Student ID Number : ");
	scanf("%d", &id);
	Queue_Traverse1(&q, &ID_search, &id);
}

void Find_student_by_first_name()
{
	char fname[50];
	DPrintf("\n\t Enter Student first name : ");
	gets(fname);
	Queue_Traverse1(&q, &Fname_search, fname);
}

void Find_all_students_in_course()
{
	int course_id;
	DPrintf("\n\t Enter course ID Number : ");
	scanf("%d", &course_id);
	Queue_Traverse1(&q, &Course_search, &course_id);
}

void Count_of_students()
{
	int size=Queue_Size(&q);
	DPrintf("\n\t [INFO] Total number of Students = %d", size);
	DPrintf("\n\t [INFO] You can add up to  %d Student", MaxQueue);
	DPrintf("\n\t [INFO] You can %d more Students", MaxQueue-size);
}


void Update_student()
{
	int id;
	DPrintf("\n ==============================");
	DPrintf("\n\t Enter ID number to update Student info : ");
	scanf("%d", &id);
	Queue_Traverse1(&q, &ID_Update, &id);

}


void Delete_student()
{
	int id;
	DPrintf("\n ==============================");
	DPrintf("\n\t Enter ID number : \n");
	scanf("%d", &id);
	Queue_Traverse1(&q, &ID_Delete, &id);
}


void Show_all_information()
{
	if(Queue_Size(&q)!=0)
	{
		DPrintf("\n ==================== \n");
		DPrintf("\n Students Details \n");
		Queue_Traverse0(&q, &display);
	}
	else
	{
		DPrintf("\n [ERROR] : No Students found \n");
	}
}


void Exit()
{


}

