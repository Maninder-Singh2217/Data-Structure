#include<stdio.h>
#include<stdlib.h>
struct stack
{
 int data;
 struct stack *next;
 struct stack *prev;
};
typedef struct stack sdlist;

//function to push a value in stack
void push_sdlist(sdlist **top, sdlist **rp,int value);
//to pop a value
int pop_sdlist(sdlist **top);
//to check if stack is empty
void check_empty_sdlist(sdlist *top, sdlist *rp);
//to perform peep operation
void peep_sdlist(sdlist **top, sdlist **rp);
void traversal_sdlist(sdlist **top, sdlist **rp);
void update_sdlist(sdlist **top,sdlist **rp);

int main()
{
	sdlist *top,*rp;
	top=(sdlist*)malloc(sizeof(sdlist));
	rp=(sdlist*)malloc(sizeof(sdlist));
	top=NULL;
	rp=NULL;
	
	int option,value;
	
	do {
		printf("---------------**Enter your option**-----------------\n");
		printf("1. Push operation\n2. Pop operation\n3. Peep operation\n4. Traversal\n5. Update\n6. Exit\n\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				push_sdlist(&top,&rp,1);
				push_sdlist(&top,&rp,2);
				push_sdlist(&top,&rp,3);
				push_sdlist(&top,&rp,4);
				printf("\n\n");
				break;
				
			case 2:
				check_empty_sdlist(top,rp);
				value=pop_sdlist(&top);
				if(value!=0)
					printf("Element removed is %d\n\n",value);
				break;	
				
			case 3:
				check_empty_sdlist(top,rp);
				peep_sdlist(&top,&rp);	
				break;
				
			case 4:
				check_empty_sdlist(top,rp);
				traversal_sdlist(&top,&rp);	
				break;
				
			case 5:
				check_empty_sdlist(top,rp);
				update_sdlist(&top,&rp);	
				break;
			
			case 6:
				exit(1);
				
			default:
				exit(1);
		}	
	}while(option!=6);

	return 0;
}

void check_empty_sdlist(sdlist *top,sdlist *rp)
{
	if(top==NULL && rp==NULL)
	{
		printf("Underflow\n\n");
		exit(1);
	}
}

void push_sdlist(sdlist **top,sdlist **rp,int value)
{
	sdlist *node;
	node=(sdlist*)malloc(sizeof(sdlist));
	node->data=value;
	if(*top==NULL && *rp==NULL)
	{
		node->prev='\0';
		node->next='\0';
		*top=node;
		*rp=node;
	}
	else
	{
		node->prev='\0';
		node->next=*top;
		(*top)->prev=node;
		(*top)=node;
	}
}

int pop_sdlist(sdlist **top)
{
	int value=0;
	sdlist *temp;
	temp=(sdlist*)malloc(sizeof(sdlist));
	if((*top)!=NULL)
	{
		value=(*top)->data;
		temp=*top;
		*top=(*top)->next;
		//(*top)->prev='\0';
		free(temp);
	}
	else 
		printf("Underflow\n\n");
	
	return value;
}

void peep_sdlist(sdlist **top,sdlist **rp)
{
	int value,find=0,value2;
	printf("Enter desired value :");
	scanf("%d",&value);
	
	sdlist *top1,*rp1;
	top1=(sdlist*)malloc(sizeof(sdlist));
	rp1=(sdlist*)malloc(sizeof(sdlist));
	top1=NULL;
	rp1=NULL;
	
	while(*top!=NULL)
	{
		if((*top)->data==value)
		{
			printf("%d is present in the stack\n\n",value);
			value2=pop_sdlist(top);
			find=1;
			break;
		}
		else
		{
			value2=pop_sdlist(top);
			push_sdlist(&top1,&rp1,value2);
		}
	}
	
	while(top1!=NULL)
	{
		value2=pop_sdlist(&top1);
		push_sdlist(top,rp,value2);
	}
	
	if(find==0)
		printf("Element not found\n\n");
}

void traversal_sdlist(sdlist **top,sdlist **rp)
{
	int value2;
	sdlist *top1,*rp1;
	top1=(sdlist*)malloc(sizeof(sdlist));
	rp1=(sdlist*)malloc(sizeof(sdlist));
	top1=NULL;
	rp1=NULL;
	
	while(*top!=NULL)
	{
		printf("%d ",(*top)->data);
		value2=pop_sdlist(top);
		push_sdlist(&top1,&rp1,value2);
	}

	printf("\n");
	*top=NULL;
	*rp=NULL;
	
	while(top1!=NULL)
	{
		value2=pop_sdlist(&top1);
		push_sdlist(top,rp,value2);
	}
}

void update_sdlist(sdlist **top,sdlist **rp)
{
	int value,find=0,value2;
	printf("Enter desired value :");
	scanf("%d",&value);
	
	sdlist *top1,*rp1;
	top1=(sdlist*)malloc(sizeof(sdlist));
	rp1=(sdlist*)malloc(sizeof(sdlist));
	top1=NULL;
	rp1=NULL;
	
	while(*top!=NULL)
	{
		if((*top)->data==value)
		{
			printf("Enter a new value");
			scanf("%d",&(*top)->data);
			find=1;
			break;
		}
		else
		{
			value2=pop_sdlist(top);
			push_sdlist(&top1,&rp1,value2);
		}
	}
	
	printf("\n\n");
	while(top1!=NULL)
	{
		value2=pop_sdlist(&top1);
		push_sdlist(top,rp,value2);
	}
	
	if(find==0)
		printf("Element not found\n\n");
}

