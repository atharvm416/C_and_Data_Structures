#include<stdio.h>
#include"acct.h"
void main()
{
	FILE *fa;
	fa=fopen("acct.txt","r");
	if(fa==NULL)
	{
		printf("\nFile Not Found");
		return;
	}
	while(1)
	{
		fscanf(fa,"%d %s %d",&ac.acno,ac.acnm,&ac.opnbal);
		if(feof(fa))
			break;
		display();
	}
	fclose(fa);
	return;
}
