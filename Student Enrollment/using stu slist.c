#include<stdio.h>
typedef struct student
{
	int rno;
	char nm[15];
	int mrk;
}STU;
void input(STU *t,int n)
{
	t->rno=n;
	printf("\nName:");
	scanf("%s",t->nm);
	printf("\nMarks:");
	scanf("%d",&t->mrk);
	return;
}
void output(STU *t)
{
	printf("\nRoll No:%d\nName:%s\nMarks:%d",t->rno,t->nm,t->mrk);
}
typedef struct node
{
	STU data;
	struct node *next;
}NODE;
typedef struct stulist
{
	NODE *st;
	int cnt;
}SLIST;
void init(SLIST *t)
{
	t->st=NULL;
	t->cnt=0;
}
NODE*search(SLIST *t,int n)
{
	NODE *a=t->st;
	while(a!=NULL)
	{
		if((a->data).rno==n)
			break;
		a=a->next;
	}
	return a;
}
void add(SLIST *t)
{
	int no;
	NODE *a;
	printf("\nRoll No:");
	scanf("%d",&no);
	a=search(t,no);
if(a!=NULL)
	printf("\nRecord Exists");
else
{
	a=(NODE*)malloc(sizeof(NODE));
	input(&a->data,no);
	a->next=t->st;
	t->st=a;
	t->cnt=t->cnt+1;
}
}
void mod(SLIST *t)
{
	NODE *a;
	int no;
	if(t->st==NULL)
	{
		printf("\nEmpty List");
		return;
	}
	printf("\nRoll No To Modify:");
	scanf("%d",&no);
	a=search(t,no);
	if(a==NULL)
		printf("\nInvalid Roll No.");
	else
		input(&a->data,no);
}
void del(SLIST *t)
{
	NODE *a,*b;
		int no;
	if(t->st==NULL)
	{
		printf("\nEmpty List");
		return;
	}
	printf("\nRoll No To Delete:");
	scanf("%d",&no);
	a=b=t->st;
	while(a!=NULL)
	{
		if((a->data).rno==no)
			break;
		b=a;
		a=a->next;
	}
	if(a==NULL)
		printf("\nNot Found");
	else
	{
		if(a==t->st)
			t->st=a->next;
		else
			b->next=a->next;
		free(a);
		t->cnt=t->cnt-1;
	}
}
void displayall(SLIST *t)
{
	NODE *a=t->st;
	if(t->st==NULL)
	{
		printf("\nEmpty List");
		return;
	}
	while(a!=NULL)
	{
		output(&a->data);
		a=a->next;
	}
}
void delall(SLIST *t)
{
	NODE *a=t->st;
	while(t->st!=NULL)
	{
		t->st=a->next;
		free(a);
		a-t->st;
	}
	t->cnt=0;
}
void tofile(SLIST *t)
{
	FILE *f1;
	STU a;
	NODE *p=t->st;
	if(t->st==NULL)
	{
		printf("\nEmpty List");
		return;
	}
	f1=fopen("stu.dat","wb");
	while(p!=NULL)
	{
		a=p->data;
		fwrite(&a,sizeof(STU),1,f1);
		p=p->next;
	}
	fclose(f1);
}
void fromfile(SLIST *t)
{
	FILE *f1;
	STU a;
	NODE *p,*q;
	f1=fopen("stu.dat","rb");
	if(f1==NULL)
		return;
	if(t->st!=NULL)
		delall(t);
	while(1)
	{
		fread(&a,sizeof(STU),1,f1);
		if(feof(f1))
			break;
		p=(NODE*)malloc(sizeof(NODE));
		p->data=a;
		p->next=t->st;
		t->st=p;
		t->cnt=t->cnt+1;
	}
}
void main()
{
	SLIST p;
	int opt;
	init(&p);
	while(1)
	{
		printf("MENU\n1.Add New Record\n2.Modify\n3.Delete\n4.Display All\n5.TO FILE\n6.From FILE\n7.Del ALL\n8.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>7)
			break;
		switch(opt)
		{
			case 1:
				add(&p);
				break;
			case 2:
				mod(&p);
				break;
			case 3:
				del(&p);
				break;
			case 4:
				displayall(&p);
				break;
			case 5:
				tofile(&p);
				break;
			case 6:
				fromfile(&p);
			case 7:
				delall(&p);
		}
	}
}
