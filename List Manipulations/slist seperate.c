#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
typedef struct slist
{
	NODE *st;
}SLIST;
void init(SLIST *t)
{
	t->st=NULL;
}
NODE*CreateNode(int d)
{
	NODE *a=(NODE*)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
}
void display(SLIST *t)
{
	NODE *a=t->st;
	if(a==NULL)
		printf("\nEmpty List");
	else
	{
		printf("\nDATA\n");
		while(a!=NULL)
		{
			printf("%5d",a->data);
			a=a->next;
		}
	}
}
void addend(SLIST *t,int d)
{
	NODE *a,*b;
	a=CreateNode(d);
	if(t->st==NULL)
		t->st=a;
	else
	{
		b=t->st;
		while(b!=NULL)
			b=b->next;
		b->next=a;
	}
}
void addbeg(SLIST *t,int d)
{
	NODE *a;
	a=CreateNode(d);
	a->next=t->st;
	t->st=a;
}
int count(SLIST *t)
{
	int cnt=0;
	NODE *a=t->st;
	while(a!=NULL)
	{
		cnt++;
		a=a->next;
	}
	return cnt;
}
void delall(SLIST *t)
{
	NODE *a=t->st;
	while(t->st!=NULL)
	{
		t->st=a->next;
		free(a);
		a=t->st;
	}
}
int isOrdered(SLIST *t)
{
	NODE *a=t->st,*b;
	for(b=a->next;b!=NULL;b=b->next)
	{
		if(b->data<a->data)
			break;
		a=b;
	}
	if(b==NULL)
		return 1;
	else
		return 0;
} 
void copylist(SLIST *d,SLIST *s)
{
	NODE *a=s->st,*b,*c;
	if(d->st!=NULL)
		delall(d);
	while(a!=NULL)
	{
		b=CreateNode(a->data);
		if(d->st==NULL)
			d->st=b;
		else
			c->next=b;
		c=b;
		a=a->next;
	}
}
void appendlist(SLIST *d,SLIST *s)
{
	NODE *a=s->st,*b,*c;
	if(d->st==NULL)
		copylist(d,s);
	else
	{
		c=d->st;
		while(c->next!=NULL)
			c=c->next;
		while(a!=NULL)
		{
			b=CreateNode(a->data);
			c->next=b;
			c=b;
			a=a->next;
		}
	}
}
void createlist(SLIST *t)
{
	NODE *a,*b;
	int d;
	delall(t);
	while(1)
	{
		printf("\nDATA\n");
		scanf("%d",&d);
		if(d==0)
			break;
		a=CreateNode(d);
		if(t->st==NULL)
			t->st=a;
		else
			b->next=a;
		b=a;
	}
}
void sort(SLIST *t)
{
	NODE *a,*b,*c;
	int tmp;
	if(t->st==NULL)
		return;
	a=t->st;
	while(a->next!=NULL)
	{
		c=a;
		for(b=a->next;b!=NULL;b=b->next)
		{
			if(b->data<c->data)
				c=b;
		}
		if(a!=c)
		{
			tmp=a->data;
			a->data=c->data;
			c->data=tmp;
		}
		a=a->next;
	}
}
SLIST merge(SLIST *p,SLIST *q)
{
	SLIST r;
	NODE *a=p->st,*b=q->st,*c,*d;
	int data;
	init(&r);
	sort(p);
	sort(q);
	while(a&&b)
	{
		if(a->data<b->data)
		{
			data=a->data;
			a=a->next;
		}
		else
		{
			data=b->data;
			b=b->next;
		}
		c=CreateNode(data);
		if(r.st==NULL)
			r.st=c;
		else
			d->next=c;
		d=c;
	}
	while(a!=NULL)
	{
		data=a->data;
		c=CreateNode(data);
		d->next=c;
		d=c;
		a=a->next;
	}	
}
SLIST intersection(SLIST *p,SLIST *q)
{
	SLIST r;
	NODE *a=p->st,*b=q->st,*c,*d;
	int data;
	init (&r);
	if(p->st==NULL||q->st==NULL)
		return r;
	sort(p);
	sort(q);
	while(a&&b)
	{
		if(a->data==b->data)
		{
			data=a->data;
			a=a->next;
			b=b->next;
		}
		else
		{
			if(a->data<b->data)
				a=a->next;
			else
				b=b->next;
			continue;
		}
		if(r.st==NULL)
			r.st=c=CreateNode(data);
		else
		{
			if(data==d->data)
				continue;
			c=CreateNode(data);
			d->next=c;
		}
		d=c;
	}
	return r;
}
SLIST unionlist(SLIST *p,SLIST *q)
{
	SLIST r;
	NODE *a=p->st,*b=q->st,*c,*d;
	int data;
	init (&r);
	if(p->st==NULL||q->st==NULL)
		return r;
	sort(p);
	sort(q);
	while(a&&b)
	{
		if(a->data==b->data)
		{
			data=a->data;
			a=a->next;
			b=b->next;
		}
		else
		{
			if(a->data<b->data)
				a=a->next;
			else
				b=b->next;
			continue;
		}
		if(r.st==NULL)
			r.st=c=CreateNode(data);
		else
		{
			if(data==d->data)
				continue;
			c=CreateNode(data);
			d->next=c;
		}
		d=c;
	}
	while(a!=NULL)
	{
		data=a->data;
		if(r.st==NULL)
			r.st=c=CreateNode(data);
		else
		{
			if(data==d->data)
				continue;
			c=CreateNode(data);
			d->next=c;
		}
		d=c;
		a=a->next;
	}
	while(b!=NULL)
	{
		data=b->data;
		if(r.st==NULL)
			r.st=c=CreateNode(data);
		else
		{
			if(data==d->data)
				continue;
			c=CreateNode(data);
			d->next=c;
		}
		d=c;
		b=b->next;
	}
	return r;
}
void main()
{
	SLIST p,q,r;
	int opt;
	init(&p);
	init(&q);
	init(&r);
	while(1)
	{
		printf("\nMENU\n");
		printf("\n1.Create List 1:");
		printf("\n2.Create List 2:");
		printf("\n3.Display List 1:");
		printf("\n4.Display List 2:");
		printf("\n5.Display List 3:");
		printf("\n6.Delete List 1:");
		printf("\n7.Delete List 2:");
		printf("\n8.Delete List 3:");
		printf("\n9.sort List 1:");
		printf("\n10.Sort List 2:");
		printf("\n11.Copy List 1 To List 3:");
		printf("\n12.Copy List 2 To List 3:");
		printf("\n13.Appende List 1 To List 3:");
		printf("\n14.Appende List 2 To List 3:");
		printf("\n15.Merge:");
		printf("\n16.Intersection:");
		printf("\n17.Union:");
		printf("\n18.Exit\nOptions:");
	
	scanf("%d",&opt);
	if(opt>17)
		break;
	switch(opt)
	{
		case 1:
		createlist(&p);
		break;
		case 2:
		createlist(&q);
		break;
		case 3:
		display(&p);
		break;
		case 4:
		display(&q);
		break;
		case 5:
		display(&r);
		break;
		case 6:
		delall(&p);
		break;
		case 7:
		delall(&q);
		break;
		case 8:
		delall(&r);
		break;
		case 9:
		sort(&p);
		break;
		case 10:
		sort(&q);
		break;
		case 11:
		copylist(&r,&p);
		break;
		case 12:
		copylist(&r,&q);
		break;
		case 13:
		appendlist(&r,&p);
		break;
		case 14:
		appendlist(&r,&q);
		break;
		case 15:
			r=merge(&p,&q);
			break;
		case 16:
			r=intersection(&p,&q);
			break;
		case 17:
			r=unionlist(&p,&q);
			break;
	}
	}
}
