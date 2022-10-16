#include<stdio.h>
void main()
{
	int opt,no,cnt=0,i,j,sup1,sup2,k;
	float mean,medn,mode,data[100],rem[100],tmp;
	while(1)
	{
		printf("\n\nMenu\n1.Add\n2.remove\n3.Display\n4.Mean\n5.Median\n6.Mode\n7.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>6)
			break;
		switch(opt)
		{
			case 1:
				printf("\nHow many numbers do you want to enter:");
				scanf("%d",&no);
				no=no+cnt;
				printf("\nEnter Data:\n");
				for(i=cnt;i<no;i++)
				{
					scanf("%f",&data[i]);
					cnt++;
				}
				break;
			case 2:
				if(cnt!=0)
				{
					printf("\nEnter the Position:");
					scanf("%d",&no);
					for(i=no-1;i<cnt;i++)
						data[i]=data[i+1];
					cnt--;
					break;
				}
				else
				{
					printf("\nNo data to remove");
					break;
				}
				
			case 3:
				if(cnt!=0)
				{
					printf("\nData is\n");
					for(i=0;i<cnt;i++)
						printf("\n%.2f",data[i]);
					break;
				}
				else
				{
					printf("\nNo data Found");
					break;
				}
			case 4:
				mean=0;
				for(i=0;i<cnt;i++)
					mean=mean+data[i];
				mean=mean/cnt;
				printf("\nMean Wil be %.4f",mean);
				break;
			case 5:
				for(i=0;i<cnt;i++)
					rem[i]=data[i];
				for(i=0;i<cnt-1;i++)
				{
					no=i;
					for(j=i+1;j<cnt;j++)
					{
						if(rem[j]<rem[no])
							no=j;
					}
					if(i!=no)
					{
						tmp=rem[i];
						rem[i]=rem[no];
						rem[no]=tmp;
					}
				}
				if(cnt%2==1)
				{
					i=cnt/2;
					printf("\nMedian will be %f",rem[i]);
				}
				else
				{
					i=cnt/2;
					medn=(rem[i]+rem[i-1])/2;
					printf("\nMedian will be %f",medn);
				}
				break;
			case 6:
				for(i=0;i<cnt;i++)
					rem[i]=data[i];
				no=cnt;
				for(i=0;i<no;i++)
				{
					for(j=i+1;j<no;j++)
					{
						if(rem[i]==rem[j])
						{
							for(k=j;k<no;k++)
								rem[k]=rem[k+1];
							no--;
							j--;
						}
					}
				}
				if(cnt==no)
					printf("\nNo Mode Found");
				else
				{
					sup1=0;
					for(i=0;i<no;i++)
					{
						sup2=0;
						for(j=i;j<cnt;j++)
						{
							if(data[j]==rem[i])
								sup2++;
						}
						if(sup2>sup1)
						{
							sup1=sup2;
							k=i;
						}
						if(sup2==sup1)
						{
							if(rem[k]>rem[i])
								k=i;
						}
					}
						printf("\nMode will be %f",rem[k]);
				}
		}
	}
	return;
}
