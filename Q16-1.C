#include<stdio.h>
#include<conio.h>

void median(int a[10],int n)
{
	float med;
	int i,j,temp;
	for(i=0;i<n;i++)//arranging the elements in ascending order
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}

	if(n%2==0)
	    med=(a[n/2-1]+a[n/2])/2;
	else
	    med=a[(n-1)/2];

	printf("\nThe Medianof the entered elements = %f\n",med);
}


int freq(int a[10],int n,int freqt[10][2])
{
	int i,j,k,no,s;
	k=0;
	for(i=0;i<n;i++)
	{
		freqt[k][0]=a[i];
		freqt[k][1]=1;

		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				freqt[k][1]++;
			}
		}
		k++;
	}
	no=n+1;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(freqt[i][0]==freqt[j][0])
			{
				freqt[j][0]=freqt[j+1][0];
				freqt[j][1]=freqt[j+1][1];
				for(s=j+1;s<n+1;s++)
				{
					freqt[s][0]=freqt[s+1][0];
					freqt[s][1]=freqt[s+1][1];
				}
				no--;
			}
		}
	}
	return no;
}

void mode(int freqt[10][2],int no)
{
	int large,mod,i,f,in;
	in=freqt[0][1];
	for(i=0;i<no-1;i++)
	{
		if(freqt[i][1]==in)
			f=1;
		else
		{
			f=0;
			break;
		}
	}
	if(f==0)
	{
		for(i=0;i<no-1;i++)
		{
			if(i==0)
			{
				large=freqt[0][1];
				mod=freqt[0][0];
			}
			if(freqt[i][1]>large)
			{
				large=freqt[i][1];
				mod=freqt[i][0];
			}
		}
		printf("The Mode for given values=%d\n",mod);
	}
	else
		printf("No mode can be found for the given values\n");
}


void main()
{
	int i,n,a[10],freqt[10][2],j,no;
	clrscr();
	printf("Enter the no of elements:\n");
	scanf("%d",&n);
	printf("Enter elements:\n");

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	median(a,n);
	no=freq(a,n,freqt);
	printf("\n");
	printf("The frequency distribution table is\n");
	printf("NO\t FREQUENCY\n");
	for(i=0;i<no-1;i++)
		{
			printf("%d \t %d\n",freqt[i][0],freqt[i][1]);
		}
	mode(freqt,no);

	getch();
}



