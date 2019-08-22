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
	int min,t,p,j;
	for(int i=0;i<n;i++)
	{
		 min=a[i];
		 p=i;
		 
		for( j=i+1;j<n;j++)
		{
			if(min>a[j])
			{
				min=a[j];
				p=j;
			}
		}
	 t=a[i];
	a[i]=a[p];
	a[p]=t;	
		
	}
	
	printf("sorted array is:\n\n");
	int k;
	for( k=0;k<n;k++)
	printf("%d ",a[k]);
	
	return 0;
}
