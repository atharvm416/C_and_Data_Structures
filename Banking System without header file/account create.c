#include<stdio.h>
typedef struct account
{
	int acno;
	char acnm[15];
	int opbal;
	int state;
}ACC;
ACC ac[10];
int pos=0;
int search(int no)
{
	int i=0;
	while(i<pos)
	{
		if(ac[i].acno==no)
			break;
		i++;
	}
	if(i==pos)
		return -1;
	else
		return i;
}
void add()
{
	int no,res;
	if(pos==10)
	{
		printf("\nNo Room For Insersertion");
		return;
	}
	printf("\nEnter A/C NO:");
	scanf("%d",&no);
	res=search(no);
	if(res>=0)
	{
		printf("\nA/C No Exists");
		return;
	}
	ac[pos].acno=no;
	printf("\nA/C Name:");
	scanf("%s",ac[pos].acnm);
	do
	{
		printf("\nOpening Balance");
		scanf("%d",ac[pos].opbal);
	}while(ac[pos].opbal<100);
	ac[pos].state=1;
	pos++;
	printf("\nInsertion Successful");
	return;
}
void mod()
{
	int no,res;
	if(pos==0)
	{
		printf("\nNo Records");
		return;
	}
	printf("\nEnter a A/C No:");
	scanf("%d",&no);
	res=search(no);
	if(res==-1)
	{
		printf("\nA/C Not Found");
		return;
	}
	if(ac[res].state==0)
	{
		printf("\nDeleted Record");
		return;
	}
	printf("\nA/C Name");
	scanf("%s",ac[res].acnm);
	do
	{
		printf("\nOpening Balance");
		scanf("%d",ac[res].opbal);
	}while(ac[res].opbal<100);
	ac[res].state=1;
	printf("\nModification Successful");
	return;
}
void del()
{
	int no,res;
	if(pos==0)
	{
		printf("\nNo Records");
		return;
	}
	printf("\nEnter a A/C No:");
	scanf("%d",&no);
	res=search(no);
	if(res==-1)
	{
		printf("\nA/C Not Found");
		return;
	}
	if(ac[res].state==0)
	{
		printf("\nDeleted Record");
		return;
	}
	ac[res].state=0;
	printf("\nRecord Deleted");
	return;
}
void display()
{
	int i=0;
	if(pos==0)
	{
		printf("\nNo Records Exists");
		return;
	}
	printf("\nA/C Records:\n");
	for(i=0;i<pos;i++)
		printf("\n%5d %s %5d %d",ac[i].acno,ac[i].acnm,ac[i].opbal,ac[i].state);
	return;
}
void main()
{
	int opt;
	while(1)
	{
		printf("\nA/C Menu\n1.Add\n2.Modification\n3.Delete\n4.Display\n5.Exit\nOptions:");
		scanf("%d",&opt);
		if(opt>4)
			break;
		switch(opt)
		{
			case 1:
				add();
				break;
			case 2:
				mod();
				break;
			case 3:
				del();
				break;
			case 4:
				display();
				break;	
		}
	}
}
