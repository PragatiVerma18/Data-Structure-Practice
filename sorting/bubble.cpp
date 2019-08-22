#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter number of elements");
	scanf("%d",&n);
	int a[n];
	printf("Enter array");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	
	printf("sorted array is:\n\n");
	int k;
	for( k=0;k<n;k++)
	printf("%d ",a[k]);
	
	return 0;
}
