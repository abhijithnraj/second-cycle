#include<stdio.h>
#include<conio.h>
#include<string.h>


void main()
{
	char *names[20],name[20];
	int i,n,j,f,index;
	char *temp,ch;
	clrscr();

	printf("\n Enter the no of names you want to enter:");
	scanf("%d",&n);

	for(i=0;i<=n;i++)
		names[i]=(char *)malloc(20*sizeof(char));

	printf("\n Enter the names:");
	for(i=0;i<=n;i++)
			gets(names[i]);


	for(i=0;i<=n;i++) //sorting the names
	{
		for(j=i+1;j<=n;j++)
		{
			if(*names[i]>*names[j])
			{
				temp=names[i];
				names[i]=names[j];
				names[j]=temp;
			}
		}
	}

	printf("The sorted list of names:\n");
	for(i=0;i<=n;i++)
			puts(names[i]);


	printf("Enter the name you want to search:\n");
	gets(name);

	for(i=0;i<=n;i++)
	{
		if(strcmp(names[i],name)==0)
		{
			f=1;
			index=i+1;
			break;
		}
		else
			f=0;
	}

	if(f==1)
		printf("The name is found at %dth position\n",index);
	else
		printf("The name is not in the list\n");

	printf("Enter a character\n");
	scanf("%c",&ch);

	printf("Names starting with %c:\n",ch);
	for(i=0;i<=n;i++)
		if(names[i][0]==ch)
			puts(names[i]);


	getch();
}