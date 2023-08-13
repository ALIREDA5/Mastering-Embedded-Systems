/*
 * List_t.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Ali Reda
 */

#ifndef LIST_H_
#define LIST_H_

// Entry
//typedef struct Entry{
//	char name[50];
//	int ID;
//	float height;
//}Entry_t;
typedef int  Entry_t;

// Node
typedef struct node{
	struct node *next;
	Entry_t entry;
}Node_t;

// List data types
typedef struct list {
	Node_t *head;
	int size;
}List_t;

// List status
typedef enum{
List_no_error,
List_full,
List_not_full,
List_empty,
List_non_empty,
List_fail,
List_un_init
}List_Status;

//List APIs
void  List_Create(List_t *pq);
void  List_Destroy(List_t *pq);
// Insert element at any pos from index 0 to Max of List
List_Status  List_Insert_Element(int pos, List_t *pq, Entry_t e);
// Add element at top of List
List_Status  List_Add_Element(List_t *pq, Entry_t e);
List_Status  List_Delete_Element(int pos, List_t *pq, Entry_t *e);
List_Status  List_Empty(List_t *pq);
List_Status  List_Full(List_t *pq);
int  List_Size(List_t *pq);
List_Status  List_Traverse(List_t *pq, void(*pf)(Entry_t e));

#endif /* LIST_H_ */
