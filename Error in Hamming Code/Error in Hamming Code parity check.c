#include<stdio.h>
#include<math.h>
void main()
{
	int data[8],c[4],h[12],i=0,j,k,n=0,r[12],c1,pb=0,pos=0;
	printf("\nEnter 12-bit code");
	for(k=0;k<12;k++)
	{
		printf("\nEnter %d bit Of Data Transmitted:",k);
		if((pow(2,n)-1)==k)
		{
			scanf("%d",&c[n]);
			n++;
		}
		else
		{
			scanf("%d",&data[i]);
			i++;
		}
	}
	printf("\nError At:");
	if(c[3]!=data[4]^data[5]^data[6]^data[7])
	{
		printf("\n1");
		pb++;
		pos=pos+8;
	}
	else
		printf("\n0");
	if(c[2]!=data[1]^data[2]^data[3]^data[7])
	{
		printf("\t1");
		pb++;
		pos=pos+4;
	}
	else
		printf("\t0");
	if(c[1]!=data[0]^data[2]^data[3]^data[5]^data[6])
	{
		printf("\t1");
		pb++;
		pos=pos+2;
	}
	else
		printf("\t0");
	if(c[0]!=data[0]^data[1]^data[3]^data[4]^data[6])
	{
		printf("\t1");
		pb++;
		pos=pos+1;
	}
	else
		printf("\t0");
	n=0;
	i=0;
	if(pb==0)
	{
		printf("\n\nData inputted Doesn't have any errors");
	}
	else
	{
		for(j=0;j<12;j++)
		{
			if((pow(2,n)-1)==j)
			{
				h[j]=c[n];
				n++;
			}
			else
			{
				h[j]=data[i];
				i++;
			}
		}
		if(h[pos-1]==0)
			h[pos-1]=1;
		else
			h[pos-1]=0;
		printf("\ni.e. At Position %d",pos);
		printf("\n\nData Corrected:");
		for(i=0;i<12;i++)
			printf("%d",h[i]);
	}
	return;
}
