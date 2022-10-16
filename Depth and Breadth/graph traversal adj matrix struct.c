#include<stdio.h>
#define N 10
struct node
{
	int data;
	struct node *next;
}
*arr[N];
int visited[N];
int f=0,r=-1,q[N],n;
struct node *createnode(int d)
{
	struct node *a;
	a=(struct node *)malloc(sizeof(struct node));
	a->data=d;
	a->next=NULL;
	return a;
}
void Createlist()
{
	int i=1,v;
	struct node *p;
	while(i<=n)
	{
		printf("\nVertex :\n");
		scanf("%d",&v);
		arr[i]=p=createnode(v);
		printf("\nAdjacent Vertices :\n");
		while(1)
		{
			scanf("%d",&v);
			if(v==0)
				break;
			p->next=createnode(v);
			p=p->next;
		}
		i++;
	}
}
void init()
{
	int i=0;
	while(i<N)
	{
		visited[i]=0;
		i++;
	}
}
void deft(int v)
{
	struct node *p;
	visited[v]=1;
	p=arr[v];
	printf("%4d",p->data);
	while(p!=NULL)
	{
		if(visited[p->data]==0)
			dft(p->data);
		else
			p=p->next;
	}
}
void bft(int v)
{
	struct node *a;
	visited[v]=1;
	printf("%4d",v);
	q[r++]=v;
	while(f<=r)
	{
		v=q[f++];
		a=arr[v];
		while(a!=NULL)
		{
			if(visited[a->data]==0)
			{
				q[r++]=a->data;
				visited[a->data]=1;
				printf("%4d",a->data);
			}
			a=a->next;
		}
	}
}
void main()
{
	int opt,n;
	printf("\nVertices Count :");
	scanf("%d",&n);
	createlist();
	while(1)
	{
		printf("\nGraph Traversal\n1 Depth\n2 Breadth\n3 Exit\nOption :");
		scanf("%d",&opt);
		if(opt>2)
			break;
		init();
		if(opt==1)
			deft(1);
		else
		{
			r=-1;
			f=0;
			bft(1);
		}
	}
}
