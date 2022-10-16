#include<stdio.h>
#include"acct.h"
void main()
{
	FILE *f1,*f2;
	int no,flg;
	f1=fopen("acct.txt","r");
	if(f1==NULL)
	{
		printf("\nFile Open Failed");
		return;
	}
	while(1)
	{
		printf("\nEnter A/C No :");
		scanf("%d",&no);
		if(no==0)
			break;
		f2=fopen("tmp.txt","w");
		while(1)
		{
			fscanf(f1,"%d %s %d",&ac.acno,ac.acnm,&ac.opnbal);
			if(feof(f1))
				break;
			if(ac.acno==no)
				input(no);
			fprintf(f2,"%d %s %d\n",ac.acno,ac.acnm,ac.opnbal);
		}
		fclose(f1);
		fclose(f2);
		remove("acct.txt");
		rename("tmp.txt","acct.txt");
		f1=fopen("acct.txt","r");
	}
	fclose(f1);
	return;
}
