#include<stdio.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *st=NULL;
NODE*createnode(int t)
{
	NODE *a;
	a=(NODE*)malloc(sizeof(NODE));
	a->data=t;
	a->next=NULL;
	return a;
}
void display()
{
	NODE *a=st;
	if(st==NULL)
		printf("\nEmpty List");
	else
	{
		printf("\nData:\n");
		while(a!=NULL)
		{
			printf("%4d",a->data);
			a=a->next;
		}
	}
}
NODE*getlastnode()
{
	NODE *a=st;
	while(a->next!=NULL)
		a=a->next;
	return a;
}
void addend(int d)
{
	NODE *a=createnode(d);
	NODE *b;
	if(st==NULL)
		st=a;
	else
	{
		b=getlastnode();
		b->next=a;
	}
}
void addbeg(int d)
{
	NODE *a=createnode(d);
	a->next=st;
	st=a;
}
int count()
{
	NODE *a=st;
	int cnt=0;
	while(a!=NULL)
	{
		cnt++;
		a=a->next;
	}
	return cnt;
}
int sum()
{
	NODE *a=st;
	int tot=0;
	while(a!=NULL)
	{
		tot=tot+a->data;
		a=a->next;
	}
	return tot;
}
void delfirst()
{
	NODE *a=st;
	if(st==NULL)
		return;
	st=a->next;
	free(a);
}
void dellast()
{
	NODE *a=st,*b;
	if(st==NULL)
		return;
	if(a->next==NULL)
	{
		st==NULL;
		free(a);
		return;
	}
	while(a->next!=NULL)
	{
		b=a;
		a=a->next;
	}
	b->next=NULL;
	free(a);
}
void delall()
{
	NODE *a=st;
	while(st!=NULL)
	{
		st=a->next;
		free(a);
		a=st;
	}
}
int search(int sv)
{
	NODE *a=st;
	while(a!=NULL)
	{
		if(a->data==sv)
			break;
		a=a->next;
	}
	if(a!=NULL)
		return 1;
	else
		return 0;
}
void FindReplace(int sv,int rv)
{
	NODE *a=st;
	while(a!=NULL)
	{
		if(a->data==sv)
			a->data=rv;
		a=a->next;
	}
	return;
}
int FindMax()
{
	NODE *a=st;
	int max=a->data;
	a=a->next;
	while(a!=NULL)
	{
		if(max<a->data)
			max=a->data;
		a=a->next;
	}
	return max;
}
int FindMin()
{
	NODE *a=st;
	int min=a->data;
	a=a->next;
	while(a!=NULL)
	{
		if(min>a->data)
			min=a->data;
		a=a->next;
	}
	return min;
}
int OddCount()
{
	NODE *a=st;
	int cnt=0;
	while(a!=NULL)
	{
		if(a->data%2==1)
			cnt++;
		a=a->next;
	}
	return cnt;
}
int EvenCount()
{
	NODE *a=st;
	int cnt=0;
	while(a!=NULL)
	{
		if(a->data%2==0)
			cnt++;
		a=a->next;
	}
	return cnt;
}
int isOrdered()
{
	NODE *a=st,*b;
	b=a;
	a=a->next;
	while(a!=NULL)
	{
		if(a->data<b->data)
			break;
		b=a;
		a=a->next;
	}
	if(a!=NULL)
		return 1;
	else
		return 0;
}
void sort()
{
	NODE *a=st,*b,*c;
	int tmp;
	while(a->next!=NULL)
	{
		b=a;
		c=a->next;
			while(c!=NULL)
			{
				if(c->data<b->data)
					b=c;
				c=c->next;
			}
			if(a!=b)
			{
				tmp=a->data;
				a->data=b->data;
				b->data=tmp;
			}
		a=a->next;
	}
	return;
}
void reverse()
{
	NODE *a=st,*b=NULL,*c;
	while(a!=NULL)
	{
		c=a->next;
		a->next=b;
		b=a;
		a=c;
	}
	st=b;
}
void revdisplay(NODE *a)
{
	if(a==NULL)
		return;
	revdisplay(a->next);
	printf("%5d",a->data);
}
void deliNode(int pos)
{
	NODE *a=st,*b,*c;
	int i=1;
	if(pos<1||st==NULL)
		return;
	if(pos==1)
		delfirst();
	else
	{
		a=st;
		while(i<pos&&a!=NULL)
		{
			b=a;
			a=a->next;
			i++;
		}
		if(a==NULL)
			return;
		c=a->next;
		b->next=c;
		free(a);
	}
}
void insertB(int pos,int d)
{
	NODE *a,*b,*c;
	int i=1;
	if(pos<1||st==NULL)
		return;
	if(pos==1)
		addbeg(d);
	else
	{
		a=st;
		while(i<pos&&a!=NULL)
		{
			b=a;
			a=a->next;
			i++;
		}
		if(a==NULL)
			return;
		c=createnode(d);
		c->next=a;
		b->next=c;
	}
}
void insertA(int pos,int d)
{
	NODE *a,*b,*c;
	int i=1;
	if(pos<1||st==NULL)
		return;
		a=st;
		while(i<=pos&&a!=NULL)
		{
			b=a;
			a=a->next;
			i++;
		}
		if(pos>=i)
			return;
		c=createnode(d);
		c->next=a;
		b->next=c;
}
void main()
{
	int opt,d,res,sv,rv,pos;
	while(1)
	{
		printf("\nMenu\n");
		printf("\n1.Add End\n2.Add Begin\n3.Display\n4.Count Nodes\n5.Data Sum\n6.Del First\n7.Del Last\n8.Del ALL\n9.Search Value\n10.Find Replace\n11.Maximum value\n12.Minimum Value\n13.Odd Count\n14.Even Count\n15.Ascending Order\n16.Selection Sort\n17.Reverse\n18.reversedisplay\n19.Del Node\n20.InsertB\n21.InsertA\nOption:");
		scanf("%d",&opt);
		if(opt>21)
			break;
		switch(opt)
		{
			case 1:
				printf("\nAdd at End Data:");
				scanf("%d",&d);
				addend(d);
				break;
			case 2:
				printf("\nAdd at the Begin Data:");
				scanf("%d",&d);
				addbeg(d);
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nNode Count:%d",count());
				break;
			case 5:
				printf("\nData Sum:%d",sum());
			case 6:
				delfirst();
				break;
			case 7:
				dellast();
				break;
			case 8:
				delall();
				break;
			case 9:
				printf("\nEnter search value");
				scanf("%d",&d);
				if(search(sv)==1)
					printf("Not");
				printf("Found");
				break;
			case 10:
				printf("\nEnter Search Value:");
				scanf("%d",&sv);
				printf("\nReplace Value:");
				scanf("%d",&rv);
				FindReplace(sv,rv);
				break;
			case 11:
				printf("\nMaximum Value is %d",FindMax());
				break;
			case 12:
				printf("\nMinimum Value is %d",FindMin());
				break;
			case 13:
				printf("\nNumber of Odd Count:%d",OddCount());
				break;
			case 14:
				printf("\nNumber of Even Count:%d",EvenCount());
				break;
			case 15:
				if(st==NULL)
					printf("\nEmpty List");
				else
				{
					if(isOrdered()==0)
						printf("\nOrdered");
					else
						printf("\nNot Ordered");
				}
				break;
			case 16:
				sort();
				break;
			case 17:
				reverse();
				break;
			case 18:
				revdisplay(st);
				break;
			case 19:
				printf("\nNode No To Delete:");
				scanf("%d",&pos);
				deliNode(pos);
				break;
			case 20:
				printf("\nInsert Before Position");
				scanf("%d",&pos);
				printf("\nDATA:");
				scanf("%d",&d);
				insertB(pos,d);
				break;
			case 21:
				printf("\nInsert After Position:");
				scanf("%d",&pos);
				printf("\nData:");
				scanf("%d",&d);
				insertA(pos,d);
				break;
		}
	}
}

