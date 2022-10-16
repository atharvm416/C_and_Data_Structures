#include<stdio.h>
struct account
{
	int acno;
	char acnm[15];
	int opnbal;
}ac;
void input(int no)
{
	ac.acno=no;
	printf("\nEnter Account Name :");
	scanf("%s",ac.acnm);
	do
	{
		printf("\nOpening Balance :");
		scanf("%d",&ac.opnbal);
	}while(ac.opnbal<500);
}
void display()
{
	printf("\n%5d %-15s %5d",ac.acno,ac.acnm,ac.opnbal);
}
