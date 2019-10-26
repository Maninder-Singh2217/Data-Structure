#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Record {
	char roll_no[8];
	char name[50];
	int sem;
	char branch[10];
};

struct Dlist
{
	struct Record data;
	struct Dlist *next;
  struct Dlist *prev; 
};
typedef struct Dlist dlist;

void create(dlist **lp,dlist **rp);
void check_empty(dlist *lp,dlist *rp);
void file_read(dlist **lp,dlist **rp);
void file_write(dlist *lp);
void ltr_traverse(dlist *lp);
void rtl_traverse(dlist *rp);
void search(dlist *lp);
void insert(dlist **lp,dlist **rp);
void update(dlist *lp);
void file_update(char *str,dlist *std);
void del(dlist **lp,dlist **rp);
void report(dlist *lp);

int main(void)
{
	int option;
	dlist *lp,*rp;
	lp=(dlist*)malloc(sizeof(dlist));
	rp=(dlist*)malloc(sizeof(dlist));
	
	file_read(&lp,&rp);
	
	do {
		printf("---------------**Enter your option**-----------------\n");
		printf("1. Create a linked list\n2.Traversal LTR\n3.Traversal RTL\n4.Search a record\n5.Insert a record\n6.Delete a record\n7.Update a record\n8. Report Generation\n9.Save the data\n10.Exit\n\n\n");
		scanf("%d",&option);
		switch(option)
	  {
	     case 1:	
				create(&lp,&rp);		
	     	break;

	     case 2:
	     	check_empty(lp,rp);
				ltr_traverse(lp);
				break;

			 case 3:
			 	check_empty(lp,rp);
				rtl_traverse(rp);
	        break;
		
				case 4:
					check_empty(lp,rp);
					search(lp);
					break;
					
				case 5:
					check_empty(lp,rp);
					insert(&lp,&rp);
					break;
					
				case 6:
					check_empty(lp,rp);
					del(&lp,&rp);
					break;
					
				case 7:
					check_empty(lp,rp);
					update(lp);
					break;
					
				case 8:
					check_empty(lp,rp);
					report(lp);
					break;
					
				case 9:
					check_empty(lp,rp);
					file_write(lp);
					break;
					
			default:
					exit(1);
		}
	}while(option!=10);
	
	return 0;
}

void check_empty(dlist *lp,dlist *rp)
{
	if(lp==NULL && rp==NULL)
	{
		printf("List is empty\n");
	}
}

void file_write(dlist *lp)
{
	FILE *fp;
	fp=fopen("doubly.dat","wb");
	dlist *temp;
	temp=lp;
	if(fp==NULL)
	{
		printf("File cannot be created");
		exit(0);
	}
	while(temp->next!=NULL)
	{
		fwrite(&temp->data,sizeof(struct Record),1,fp);
		temp=temp->next;
	}
	fclose(fp);
}

void file_read(dlist **lp,dlist **rp)
{
	FILE *fp;
	fp=fopen("doubly.dat","rb");
	if(fp==NULL)
	{
		printf("File cannot be opened");
		exit(0);
	}
	
	dlist *node;
	node=(dlist *)malloc(sizeof(dlist));
	node->next='\0';
	node->prev='\0';
	if(node==NULL)
	{
		printf("\n Not possible to create list");
		exit(0);
	}
	
	*lp=node;
	while(fread(&node->data,sizeof(struct Record),1,fp)==1)
	{
		node->next=(dlist*)malloc(sizeof(dlist));
		node->next->prev = node;
		node=node->next;
	}
	node->next='\0';
	*rp=node->prev;
	fclose(fp);
}

void create(dlist **lp,dlist **rp)
{
	int i=0,num;
	dlist *node;
	node=(dlist*)malloc(sizeof(dlist));
	node->next='\0';
	*lp=node;
	if(node==NULL)
	{
		printf("\n Not possible to create list");
		exit(0);
	}
	
	node->prev='\0';
	printf("Enter the number of students");
	scanf("%d",&num);
	while(i<num)
	{
		printf("Enter Roll number: ");
		scanf("%s",node->data.roll_no);
		printf("Enter Name : ");
		scanf("%s",node->data.name);
		printf("Enter Branch : ");
		scanf("%s",node->data.branch);
		printf("Enter Semester: ");
		scanf("%d",&node->data.sem);
		printf("\n\n");
		node->next = (dlist*)malloc(sizeof(dlist));
	 	node->next->prev = node;
		node = node->next;
		i++;
	}
	node->next='\0';
	*rp=node->prev;
}

void ltr_traverse(dlist *lp)
{
		printf("Roll number\t\tName\t\tSemester\t  Branch\n");
		dlist *temp;
		temp=lp;
		while(temp->next)
		{
			printf("%10s	%10s	%10d	%10s\n",temp->data.roll_no,temp->data.name,temp->data.sem,temp->data.branch);
			temp=temp->next;
		}
}

void rtl_traverse(dlist *rp)
{
		dlist *temp;
		temp=rp;
		printf("Roll number\t\tName\t\tSemester\t  Branch\n");
		while(temp!=NULL)
		{
			printf("%10s	%10s	%10d	%10s\n",temp->data.roll_no,temp->data.name,temp->data.sem,temp->data.branch);
			temp=temp->prev;
		}
}

void search(dlist *lp)
{
	char roll[8];
	int find=0;
	dlist *temp;
	printf("Enter roll number : ");
	scanf("%s",roll);
	temp=lp;
	while(temp->next!=NULL)
	{
		if(strcmp(roll,temp->data.roll_no)==0)
		{
			printf("%10s	%10s	%10d	%10s\n",temp->data.roll_no,temp->data.name,temp->data.sem,temp->data.branch);
			find=1;		
			break;				
		}
		temp=temp->next;	
	}

	if(find==0)
		printf("Record not found\n");
	
	printf("\n\n");
}

void update(dlist *lp)
{
		char roll[7];  
		int find=1;
		dlist *temp;
		temp=lp;
		printf("Enter roll number to be updated : ");
		scanf("%s",roll);
		while(temp->next!=NULL)
		{
			if(strcmp(roll,temp->data.roll_no)==0)
			{			
				printf("Enter new Roll number: ");
				scanf("%s",temp->data.roll_no);
				printf("Enter Name : ");
				scanf("%s",temp->data.name);
				printf("Enter Semester: ");
				scanf("%d",&temp->data.sem);
				printf("Enter Branch : ");
				scanf("%s",temp->data.branch);
				file_update(roll,temp);
				find=1;				
				break;
			}
			else
			{
					temp=temp->next;
					find=0;
			}
		}
			
		if(find==0)
				printf("Record not found,please enter new reord\n");
}

void file_update(char *str,dlist *std)
{
			FILE *fp;
			dlist *temp;
			temp=(dlist *)malloc(sizeof(dlist));
			fp=fopen("doubly.dat","rb+");
			if(fp!=NULL)
			{
					while(fread(&temp->data,sizeof(struct Record),1,fp)==1)
					{
						if(strcmp(str,temp->data.roll_no)==0)
						{			
							printf("Found");
							fseek(fp,-sizeof(struct Record),SEEK_CUR);				
							fwrite(&std->data,sizeof(struct Record),1,fp);
						}
					}
			}
			fclose(fp);
}

void insert(dlist **lp,dlist **rp)
{
	int option;
	char roll[8];
	dlist *new_node,*temp;
	new_node=(dlist*)malloc(sizeof(dlist));
	if(new_node==NULL)
	{
		printf("Memory Error\n");
		exit(1);
	}
	printf("Enter Roll number: ");
	scanf("%s",new_node->data.roll_no);
	printf("Enter Name : ");
	scanf("%s", new_node->data.name);				
	printf("Enter Branch : ");
	scanf("%s",new_node->data.branch);
	printf("Enter Semester: ");
	scanf("%d",&new_node->data.sem);
	printf("\nInsert the node as -\n 1.As a first record\n2.Before a record\n3.After a record\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
				printf("\n\n");
				new_node->prev='\0';
				new_node->next=*lp;
				*lp=new_node;
				new_node->next->prev=new_node;
				printf("Record inserted\n\n");
			break;
			
		case 2:
				printf("Enter the roll number before which data has to be inserted : ");
				scanf("%s",roll);		
				printf("\n\n");
				temp=*lp;
				while(strcmp(temp->data.roll_no,roll)!=0 && temp!=NULL)
				{
					temp=temp->next;
				}
				if(new_node==NULL) 
				{
				 printf("\n The element after which you want to insert does not exist:");
				 exit(0);
				}
				temp->prev->next=new_node;
				new_node->prev=temp->prev;
				new_node->next=temp;
				temp->prev=new_node;
				printf("Record inserted\n\n");
			break;
		
		case 3:
				printf("Enter the roll number after which data has to be inserted : ");
				scanf("%s",roll);				
				printf("\n\n");
				temp=*lp;
				while(strcmp(temp->data.roll_no,roll)!=0 && temp!=NULL)
				{
					temp=temp->next;
				}
				if(new_node==NULL) 
				{
				 printf("\n The element after which you want to insert does not exist:");
				 exit(0);
				}
				if(temp==*rp)
				{	
					new_node->next='\0';
					temp->next=new_node;
					new_node->prev=temp;
					(*rp)->prev=new_node;
				}
				else
				{
					temp->next->prev=new_node;
					new_node->next=temp->next;
					temp->next=new_node;
					new_node->prev=temp;
				}
			break;
		
		default:
			printf("Choose right option\n");
			exit(1);
	}
	
	printf("\n\n");
}

void del(dlist **lp,dlist **rp)
{
	int option;
	char roll[8];
	dlist *temp;
	temp=(dlist*)malloc(sizeof(dlist));
	printf("\nDelete the node -\n 1.First record\n2.Last record\n3. At any desired position\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
				temp=*lp;
				*lp=temp->next;
				temp->next->prev='\0';
				free(temp);
				printf("Record deleted");
			break;
			
		case 2:
				temp=*lp;
				while(temp->next!=NULL)
				{	
					temp=temp->next;
				}
				temp->prev->next='\0';
				*rp=temp->prev->prev;
				free(temp);
				printf("Record deleted\n");
			break;
		
		case 3:
				printf("Enter roll number to be deleted : ");
				scanf("%s",roll);
				temp=*lp;
				while(strcmp(temp->data.roll_no,roll)!=0)
				{
					temp=temp->next;
				}
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;				
				free(temp);
				printf("Record deleted\n");
			break;

		default:
			printf("Choose right option\n");
			exit(1);
	}
	
	printf("\n\n");
}

void report(dlist *lp)
{
	dlist *temp;
	temp=lp;
	int count=0,option,sem,find=0;
	char branch[10];
	printf("\n1. Based on semester\n2. Based on branch\n");	
	scanf("%d",&option);	
	switch(option)
	{
		case 1:
			printf("Enter semester : ");
			scanf("%d",&sem);
			printf("Roll number\t\tName\t\t  Branch\n");
			while(temp->next!=NULL)
			{
				if(sem==temp->data.sem)
				{
					printf("%10s	%10s  %10s\n",temp->data.roll_no,temp->data.name,temp->data.branch);
					count++;
					find=1;		
				}
				temp=temp->next;	
			}
			printf("Total number of students enrolled for %d semester are %d\n\n",sem,count);
			break;
		
		case 2:
			printf("Enter branch : ");
			scanf("%s",branch);
			printf("Roll number\t\tName\t\tSemester\n");
			while(temp->next!=NULL)
			{
				if(strcmp(branch,temp->data.branch)==0)
				{
					printf("%10s	%10s	%10d\n",temp->data.roll_no,temp->data.name,temp->data.sem);
					count++;
					find=1;				
				}
				temp=temp->next;	
			}
			printf("Total number of students in %s branch are %d\n\n",branch,count);
		break;
		
		default:
			printf("Choose right option\n");
			exit(1);
	}
	
	if(find==0)
				printf("Record not found\n");
}


