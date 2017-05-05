#include<stdio.h>
#include<conio.h>

void swapr(int *,int *);
void swapv(int,int);
void main()
{
	int n1,n2;
	clrscr();
	printf("\n Enter two values:");
	scanf("%d %d",&n1,&n2);
	printf("\n Swapping by value:");
	swapv(n1,n2);
	printf("\n swapping by reference:");
	swapr(&n1,&n2);
	printf(" %d %d",n1,n2);
	getch();
}
void swapr(int *n1,int *n2)
{
	int temp;
	temp=*n1;
	*n1=*n2;
	*n2=temp;
}
void swapv(int n1,int n2)
{
	int temp;
	temp=n1;
	n1=n2;
	n2=temp;
	printf("%d %d",n1,n2);
}


