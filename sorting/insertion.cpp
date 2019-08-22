#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	int n,i,j,t;
	printf("Enter number of elements");
	scanf("%d",&n);
	int a[n];
	printf("Enter array");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for( j=1;j<=n-1;j++)
	{
		 t=a[j];
		for( i=j-1;t<a[i]&&i>=0;i--)
		a[i+1]=a[i];
		
		a[i+1]=t;
	}
	
	printf("sorted array is:\n\n");
	int k;
	
	for( k=0;k<n;k++)
	printf("%d ",a[k]);
	
	return 0;
}
