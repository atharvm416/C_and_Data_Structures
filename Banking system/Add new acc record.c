#include<stdio.h>
#include"acct.h"
void main()
{
	FILE *fa;
	int no,flg;
	fa=fopen("acct.txt","r+");
	if(fa==NULL)
	{
		fa=fopen("acct.txt","w");
		fclose(fa);
		fa=fopen("acct.txt","r+");
	}
	while(1)
	{
		printf("\nEnter A/C No :");
		scanf("%d",&no);
		if(no==0)
			break;
		flg=0;
		rewind(fa);
		while(1)
		{
			fscanf(fa,"%d %s %d",&ac.acno,ac.acnm,&ac.opnbal);
			if(feof(fa))
				break;
			if(ac.acno==no)
			{
				flg=1;
				break;
			}
		}
		if(flg==1)
		{
			printf("\nA/C No Exists");
			continue;
		}
		input(no);
		fprintf(fa,"%d %s %d\n",ac.acno,ac.acnm,ac.opnbal);
	}
	fclose(fa);
	return;
}
