#include<stdio.h>
int length(int no)
{
	int len=0;
	while(no>0)
	{
		len++;
		no/=10;
	}
	return len;
}
int digitsum(int no)
{
	int tot=0;
	while(no>0)
	{
		tot=tot+(no%10);
		no/=10;
	}
	return tot;
}
int rev(int no)
{
	int r=0;
	while(no>0)
	{
		r=r*10+(no%10);
		no/=10;
	}
	return r;
}
int ispalin(int no)
{
	return (rev(no)==no);
}
int isprime(int no)
{
	int i=2;
	while(i<no)
	{
		if(no%i==0)
			break;
		i++;
	}
	return(i==no);
}
void main()
{
	int opt,no,res;
	int (*ptr)(int);
	while(1)
	{
		printf("\n\n\nMenu\n1 Enter No\n2 Length\n3 Digit Sum\n4 Reverse\n5 Pallindrone\n6 Prime\n7 Exit\nOptions :");
		scanf("%d",&opt);
		if(opt<1||opt>6)
			break;
		switch(opt)
		{
			case 1:
				printf("\nEnter Number :");
				scanf("%d",&no);
				break;
			default:
				switch (opt)
				{
					case 2:
						ptr=length;
						break;
					case 3:
						ptr=digitsum;
						break;
					case 4:
						ptr=rev;
						break;
					case 5:
						ptr=ispalin;
						break;
					case 6:
						ptr=isprime;
						break;
						
				}
				res=(* ptr) (no);
				switch(opt)
				{
					case 2:
						printf("\nDigit %d",res);
						break;
					case 3:
						printf("\nDigitSum %d",res);
						break;
					case 4:
						printf("\nReverse %d",res);
						break;
					case 5:
						if(res==0)
							printf("\nNot");
						printf("\nPallindrome");
						break;
					case 6:
						if(res==0)
							printf("\nNot");
						printf("\nPrime");
				}
		}
	}
}
