#include<stdio.h>
#include"CSTK.h"
void main()
{
	CSTK p;
	char ch;
	int opt,i;
	init(&p);
	while(1)
	{
		printf("\nMenu\n1.Push\n2.Pop\n3.Stack Top\n4.Display\n5.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>4)
			break;
		switch(opt)
		{
			case 1:
				printf("\nDATA:");
				scanf(" %c",&ch);
				push(&p,ch);
				break;
			case 2:
				if(p.top==-1)
					printf("\nUnderflow");
				else
					pop(&p);
				break;
			case 3:
				if(p.top==-1)
					printf("\nUnderFlow");
				else
					printf("\nTop %c",stacktop(&p));
					break;
			case 4:
				if(p.top==-1)
					printf("\nEmpty");
				else
				{
					printf("\nStack Data\n");
					for(i=p.top;i>=0;i--)
						printf("%c",p.arr[i]);
				}
		}
	}
}
