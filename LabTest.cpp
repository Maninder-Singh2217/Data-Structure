// LabTest.cpp : 
//

#include <iostream>
#include<stdio.h>
struct EmpNum{
	char E;
	int Y;
	int M;
	int No;

};

struct Address
{
	char town[40];
	char city[40];
	char state[40];
	int pin;
};

struct Employee {
	struct EmpNum empN;
	char name[40];
	char Fname[50];
	struct Address adr;
	struct Employee * next;

};

typedef struct Employee list;




list* getnewNode() {
	list* newNod = (list*)malloc(sizeof(list));
	newNod->next = NULL;
	return (newNod);
}

void insert(list** head) {			//at beginning
	list* newNode = getnewNode(); char buff[100];
	printf("\nEnter the Entry of the Employee(O/C/M)(O-Office,C-Clerk,M-Multitask)");
	scanf(" %c",&newNode->empN.E);
	printf("\nEnter the Year of the entry of the employee");
	scanf(" %d", &newNode->empN.Y);
	printf("\nEnter the month of the entry of the employee");
	scanf(" %d", &newNode->empN.M);
	printf("\nEnter the social security number of the employee");
	scanf(" %d", &newNode->empN.No);

	
	gets_s(buff);
	printf("\nEnter the  Name of the Employee: ");
	gets_s(newNode->name);
	printf("\nEnter the Father's Name of the Employee: ");
	gets_s(newNode->Fname);
	printf("\nEnter the Name of town/village of the Employee: ");
	gets_s(newNode->adr.town);
	printf("\nEnter the Name of City of the Employee: ");
	gets_s(newNode->adr.city);
	printf("\nEnter the Name of state of the Employee: ");
	gets_s(newNode->adr.state);
	printf("\nEnter the PIN code of the Employee: ");
	scanf(" %d", &newNode->adr.pin);

	if ((*head) == NULL)(*head) = newNode;
	else if ((*head)->next == NULL) {
		(*head)->next = newNode;
	}
	else
	{
		newNode->next = (*head);
		(*head) = newNode;
	}
}
void create(list** head) {
	int n;
	printf("Enter the number of records you want to enter \n");
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		insert(&(*head));
	}
}

void display(list* head) {
	if (head == NULL) {
		printf("Record empty, exiting.");
		return;
	}
	while (head != NULL) {
		printf("\nEmployee Number in order (O Y M N)\n  %c %d %d %d", head->empN.E, head->empN.Y, head->empN.M, head->empN.No);
		printf("\nName of the Employee \n %s", head->name);
		printf("\nFather's Name of the Employee\n %s", head->Fname);
		printf("\nName of town/village of the Employee\n %s", head->adr.town);
		printf("\nCity of the Employee\n  %s", head->adr.city);
	
		printf("\nState of the Employee\n %s", head->adr.state);
		
		printf("\nEnter the PIN code of the Employee\n %d",head->adr.pin);
		head = head->next;
	}
	return; 
}

void disp(list* head) {
	printf("\nEmployee Number in order (O Y M N)\n  %c %d %d %d", head->empN.E, head->empN.Y, head->empN.M, head->empN.No);
	printf("\nName of the Employee \n %s", head->name);
	printf("\nFather's Name of the Employee\n %s", head->Fname);
	printf("\nName of town/village of the Employee\n %s", head->adr.town);
	printf("\nCity of the Employee\n  %s", head->adr.city);

	printf("\nState of the Employee\n %s", head->adr.state);

	printf("\nEnter the PIN code of the Employee\n %d", head->adr.pin);
	return;
}

void searchNo(list* head, int ssn) {
	int flag = 0;
	while ((head != NULL)&& flag==0) {
		if (head->empN.No = ssn) {
			printf("\nRecord Found");
			flag = 1;
		}
	}
	if (flag == 0)printf("\nRecord not found");
}

void delet(list** head, int ssn) {
	if ((*head)==NULL){
		printf("Record empty, exiting.");
		return ;
	}
	
	if ((*head)->empN.No == ssn) (*head) = (*head)->next;
	list* temp;
	temp = getnewNode();
	(*head) = temp;
	(*head)=(*head)->next;
	while ((*head)!=NULL)
	{
		if ((*head)->empN.No == ssn) {
			temp->next = (*head) ->next;
			temp = (*head);
			free(temp);
		}
		(*head)=(*head)->next;
	}
	printf("\n New Record list is as follows \n");
	display(*head);
	
}
void count(list* head, int Yr) {
	int count = 0;
	while (head != NULL) {
		if (head->empN.Y == Yr) {
			disp(head);
			count++;
		}
		head = head->next;
	}
	printf("No of employees in the year %d are %d", Yr,count);

}
int main()
{
	list* head;
	head = NULL;
	int choice;
	char ans = 'y';
	do{
		printf("\t\t MAIN MENU\n");
		printf("1.Create new record list.\n");
		printf("2.Insert new record into the list.\n");
		printf("3.Display the records.\n");
		printf("4.Search the record for a given Social Security Number.\n");
		printf("5.Delete a record for a given SSN.\n");
		printf("6.Count the number of employees from a particular year. \n");
		scanf(" %d", &choice);
		switch (choice) {
		case 1:
			create(&head);
			printf("\nDo you want to return to main menu(Y/N)");
			scanf(" %c", &ans);
			break;
		case 2:
			insert(&head);
			printf("\nDo you want to return to main menu(Y/N)");
			scanf(" %c", &ans);
			break;
		case 3:
			display(head);
			printf("\nDo you want to return to main menu(Y/N)");
			scanf(" %c", &ans);
			break;
		case 4:
			int ssn;
			printf("\nEnter the SSN you want to search in the record\n");
			scanf(" %d", &ssn);
			searchNo(head, ssn);
			printf("\nDo you want to return to main menu(Y/N)");
			scanf(" %c", &ans);
			break;
		case 5:
			int sn;
			printf("\nEnter the SSN of the record you want to delete \n");
			scanf(" %d", &sn);
			delet(&head, sn);
			printf("\nDo you want to return to main menu(Y/N)");
			scanf(" %c", &ans);
			break;
		case 6:
			int y;
			printf("\nEnter the year of which you want to count the employees.\n");
			scanf(" %d", &y);
			count(head, y);
			printf("\nDo you want to return to main menu(Y/N)");
			scanf(" %c", &ans);
			break;
		default:
			printf("\n Wrong choice selected.");
			printf("\nDo you want to return to main menu(Y/N)");
			scanf(" %c", &ans);
			break;
		}
	} while (ans == 'y' || ans == 'Y');

	return 0;
}