#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	int priority;
	struct queue *next;
	struct queue *prev;
};
typedef struct queue list;

void create_queue(list **rear,list **front);
void insert_queue(list **rear,list **front,int dat,int prior);
void check_priority(list *node,list **front,list **rear,int prior);
void delete_queue(list **rear,list **front);
void traverse(list *front);
void update_priority(list **rear,list **front);

void main()
{
	list *rear,*front;
	rear=(list*)malloc(sizeof(list));
	front=(list*)malloc(sizeof(list));
	if(rear==NULL || front==NULL)
	{
		printf("Queue cannot be created\n");
		exit(0);
	}
	rear=NULL;
	front=NULL;
	int option;
	do {
		printf("---------------**Enter your option**-----------------\n");
		printf("1. Insert a record in the queue\n2. Delete a record from the queue\n3. Traversal\n4. Update priority of a record\n5.Exit\n\n\n");
		scanf("%d",&option);
		switch(option)
	  {
	    case 1:
				insert_queue(&rear,&front,2,5);
				insert_queue(&rear,&front,3,9);
				insert_queue(&rear,&front,8,4);
				insert_queue(&rear,&front,1,7);
				insert_queue(&rear,&front,5,6);
	      break;

			case 2:
				delete_queue(&rear,&front);
				break;

			case 3:
				traverse(front);
				break;
				
			case 4:
				update_priority(&rear,&front);
				break;

			case 5:
				exit(1);
			
			default:	 
			   exit(1);
		}
	}while(option!=5);
}

void insert_queue(list **rear,list **front,int dat,int prior)
{
	list *node;
	node=(list*)malloc(sizeof(list));
	node->data=dat;
	node->priority=prior;
	if(*rear==NULL && *front==NULL)
	{
		node->next='\0';
		node->prev='\0';
		*front=node;
		*rear=node;
	}
	
	else if(prior>(*front)->priority)
	{
			(*front)->next=node;
			node->prev=*front;
			node->next='\0';
			*front=node;
	}
		
	else if(prior<=(*rear)->priority)
	{
			node->prev='\0';
			node->next=*rear;
			(*rear)->prev=node;
			*rear=node;
	}
	else
			check_priority(node,rear,front,prior);
}

void check_priority(list *node,list **rear,list **front,int prior)
{
	list *temp;
	temp=(list*)malloc(sizeof(list));
	temp=*rear;
	while(prior>temp->priority)
	{
		temp=temp->next;
	}
	(temp->prev)->next = node; 
  node->next = temp; 
  node->prev = temp->prev; 
  temp->prev = node; 
}

void traverse(list *front)
{
	list *temp;
	temp=(list*)malloc(sizeof(list));
	temp=front;
	while(temp!=NULL)
	{
		printf("%d %d\n",temp->data,temp->priority);
		temp=temp->prev;
	}
}

void delete_queue(list **rear,list **front)
{
	list *temp;
	temp=(list*)malloc(sizeof(list));
	temp=*front;
	if(temp!=NULL)
	{
		*front=(*front)->prev;
		free(temp);
	}
	else
		printf("Underflow\n");
}

void update_priority(list **rear,list **front)
{
	list *temp;
	temp=(list*)malloc(sizeof(list));
	temp=*rear;
	
	int new_p,value;
	
	printf("Enter element : ");
	scanf("%d",&value);
	while(temp!=NULL)
	{
		if(temp->data==value)
		{
			printf("Priority is %d\n\n",temp->priority);
			free(temp);
			break;
		}
		else
			temp=temp->next;
	}
	
	printf("Enter new priority : ");
	scanf("%d",&new_p);
	insert_queue(rear,front,value,new_p);
}
