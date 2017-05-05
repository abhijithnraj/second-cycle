
#include<stdio.h>
#include<conio.h>
typedef struct student
{
	int rollno;
	char name[20];
	int marks[3];
}stud;
void getdata(stud *s,int *n)
{
	int i,j;
	printf("Enter no of students:\n");
	scanf("%d",n);
	for(i=0;i<*n;i++)
	{
		printf("Enter details of student %d ->\n",i+1);
		printf("Roll no:\n");
		scanf("%d",&s[i].rollno);
		printf("Name:\n");
		scanf("%s",s[i].name);
		for(j=0;j<3;j++)
		{
			printf("mark of subject %d: \n",j+1);
			scanf("%d",&s[i].marks[j]);
		}

	}
}
void main()
{
	stud s[100],temp;
	int n,i,j,k,f=1;
	FILE *p,*in;
	clrscr();
	getdata(s,&n);
	if((p=fopen("student.dat","wb+"))==NULL)
	{
		printf("Error opening file...\n");
		exit(0);
	}
	else
	{
		for(i=0;i<n;i++)
			fwrite(&s[i],sizeof(s),1,p);
		fclose(p);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(s[i].rollno>s[j].rollno)
				{
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
			}
		}
		if((p=fopen("studsort.dat","wb+"))==NULL)
		{
			printf("Error opening file...\n");
			exit(0);
		}
		else
		{
			for(i=0;i<n;i++)
				fwrite(&s[i],sizeof(s),1,p);
			fclose(p);
			in=fopen("studsort.dat","rb+");
			printf("List of students failed:\n");
			k=0;
			while(k<n)
			{
				fread(&temp,sizeof(s),1,in);
				for(j=0;j<3;j++)
				{
					if(temp.marks[j]<40)
					{
						printf("\t%s\n",temp.name);
						break;
					}

				}
				k++;

			}
			fclose(in);
		}
	}
	getch();
}
