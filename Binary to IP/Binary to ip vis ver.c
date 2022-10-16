#include<stdio.h>
void main()
{
	char ip[50],bin[50],a;
	int data[4],bind[4],ipa[4],i,mf,rem;
	printf("\nTo Enter the IP address\nPress 'b' for Binary and 'd' for Decimal:");
	scanf("%c",&a);
	if(a=='d'||a=='D')
	{
		printf("\nNOTE:Please put a dot between the numbers");
		printf("\nEnter The Decimal IP ADDRESS:");
		scanf("%s",&ip);
		sscanf(ip,"%d.%d.%d.%d",&data[0],&data[1],&data[2],&data[3]);
		for(i=0;i<4;i++)
		{
			bind[i]=0;
			mf=1;
			while(data[i]>0)
			{
				rem=data[i]%2;
				bind[i]=(rem*mf)+bind[i];
				data[i]/=2;
				mf=mf*10;
			}
		}
		printf("\nBinary Number will be  %08d %08d %08d %08d",bind[0],bind[1],bind[2],bind[3]);
	}
	else
	{
		if(a=='b'||a=='B')
		{
			printf("\nNOTE:Please put a space between the numbers");
			printf("\nEnter The  Binary IP Address:");
			scanf("%d %d %d %d",&data[0],&data[1],&data[2],&data[3]);
			for(i=0;i<5;i++)
			{
				ipa[i]=0;
				mf=1;
				while(data[i]>0)
				{
					rem=data[i]%10;
					ipa[i]=ipa[i]+(mf*rem);
					mf=mf*2;
					data[i]/=10;
				}
			}
			printf("\nIP Address will be %d.%d.%d.%d",ipa[0],ipa[1],ipa[2],ipa[3]);
		}
		else
		{
			printf("\nTry Again!!");
			return;
		}
	}
	return;
}
