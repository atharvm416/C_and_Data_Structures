#include<stdio.h>
#include"Dstu.h"
int search(int no)
{
	int pos=0;
	rewind(fs);
	while(1)
	{
		fread(&st,sizeof(STU),1,fs);
		if(feof(fs))
		{
			pos=-1;
			break;
		}
		if(st.rno==no)
			break;
		pos=ftell(fs);
	}
	return pos;
}
void add()
{
	int no,pos;
	printf("\nRoll No:");
	scanf("%d",&no);
	pos=search(no);
	if(pos>=0)
	{
		printf("\nRecord Exists");
		return;
	}
	input(no);
	fwrite(&st,sizeof(STU),1,fs);
}
void mod()
{
	int no,pos;
	printf("\nRoll No:");
	scanf("%d",&no);
	pos=search(no);
	if(pos==-1||st.state==0)
	{
		printf("\nRecord Not Exists");
		return;
	}
	input(no);
	fseek(fs,pos,SEEK_SET);
	fwrite(&st,sizeof(STU),1,fs);
}
void del()
{
	int no,pos;
	printf("\nRoll No:");
	scanf("%d",&no);
	pos=search(no);
	if(pos==-1||st.state==0)
	{
		printf("\nRecord Not Exists");
		return;
	}
	st.state=0;
	fseek(fs,pos,SEEK_SET);
	fwrite(&st,sizeof(STU),1,fs);
}
void displayAll()
{
	rewind(fs);
	while(1)
	{
		fread(&st,sizeof(STU),1,fs);
		if(feof(fs))
			break;
		display();
	}
	return;
}
void main()
{
	int opt,no,res;
	fs=fopen("stu.dat","r+b");
	if(fs==NULL)
	{
		fs=fopen("stu.dat","wb");
		fclose(fs);
		fs=fopen("stu.dat","r+b");
	}
	while(1)
	{
		printf("\nMenu\n1.Add\n2.Modify\n3.Delete\n4.DisplayAll\n5.Search\n6.Exit\nOption:");
		scanf("%d",&opt);
		if(opt>5)
			break;
		switch(opt)
		{
			case 1:
					add();
					break;
			case 2:
					mod();
					break;
			case 3:
					del();
					break;
			case 4:
					displayAll();
					break;
			case 5:
					printf("\nRoll No To Search:");
					scanf("%d",&no);
					res=search(no);
					if(res==-1)
						printf("\nInvalid Roll No");
					else
					{
						display();
						printf("\nFound Record");
					}
		}
	}
	fclose(fs);
}
