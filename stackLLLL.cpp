// stackLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
struct record {
	int data;
	struct record* next;
};

typedef struct record list;



void push(list** head, int n)
{
	list* new_node;
	new_node = (list*)malloc(sizeof(list));
	new_node->data = n;
	new_node->next = (*head);
	(*head) = new_node;

}

void pop(list** head)
{
	printf("The data to be deleted is %d \n", (*head)->data);
	list* temp;
	temp = (*head);
	(*head) = (*head)->next;
	free(temp);

}

void display(list* head) {
	if (head == NULL)
	{
		printf("UNDERFLOW, stack empty, exiting");
		exit(0);
	}
	printf(" %d <--\n", head->data);
	head = head->next;
	while (head) {
		printf(" %d \n", head->data);
		head = head->next;
	}

}

void peep(list** head, int element) {
	if ((*head) == NULL)
	{
		printf("UNDERFLOW, stack is empty, exiting");
		exit(0);
	}
	int flag = 0;
	list* headS = NULL;
	while ((*head) && flag != 1)
	{
		if ((*head)->data == element)
		{
			printf("Element found in stack \n");
			flag = 1;
		}
		else
		{
			push(&headS, (*head)->data);
			list* temp;
			temp = (*head);
			(*head) = (*head)->next;
			free(temp);
		}

	}

	while ((headS))
	{
		push(&(*head), headS->data);
		list* temp;
		temp = (headS);
		(headS) = (headS)->next;
		free(temp);
	}
}
int main()
{
	list* start;
	start = NULL;



	int c;
	char f;

	do
	{
		printf("******MAIN MENU*******\n");
		printf("\t 1.Push an element.\n");
		printf("\t 2.Pop an element.\n");
		printf("\t 3.Print stack.\n");
		printf("\t 4.Peep a desired element.\n");
		printf("\t 5.Exit.\n");
		scanf("%d", &c);

		switch (c) {
		case 1:
			int x;
			char d;
			do {
				printf("Enter the data to be inserted\n");
				scanf(" %d", &x);
				push(&start, x);
				printf("The stack after addition of new element is as follows\n");
				display(start);
				printf("Want to enter more data?(Y/N)");
				scanf(" %c", &d);
			} while (d == 'Y' || d == 'y');
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 2:
			printf("The stack is as follows:\n");
			display(start);
			char y;
			printf("Do you want to pop an element?(Y/N)");
			scanf(" %c", &y);
			if (y == 'Y' || y == 'y')
				pop(&start);
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 3:
			printf("The stack is as follows:\n");
			display(start);
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 4:
			int pos;
			printf("Enter the element which you want to search in stack\n");
			scanf(" %d", &pos);
			peep(&start, pos);
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Invalid Choice, re-enter choice.");
			printf("Want to return to main menu?(Y/N)");
			scanf(" %c", &f);
			break;

		}
	} while (f == 'Y' || f == 'y');



}