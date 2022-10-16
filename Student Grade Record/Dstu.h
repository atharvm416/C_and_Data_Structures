#include<stdio.h>
typedef struct student
{
	int rno;
	char nm[15];
	int mrk;
	int state;
}STU;
STU st;
FILE *fs;
void input(int no)
{
	st.rno=no;
	printf("\nStudent Name:");
	scanf("%s",st.nm);
	printf("\nMarks:");
	scanf("%d",&st.mrk);
	st.state=1;
}
void display()
{
	printf("\n%d %-15s %5d %d",st.rno,st.nm,st.mrk,st.state);
}
