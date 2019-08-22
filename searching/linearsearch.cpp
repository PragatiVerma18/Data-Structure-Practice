#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	int n,i,j,p,val;
	printf("Enter number of elements");
	scanf("%d",&n);
	int a[n];
	printf("Enter array");
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf("Enter element to be searched");
	scanf("%d",&val);
	
	for(int i=0;i<n;i++)
	{	
	if(a[i]==val)
	p=i;
	}
	
	printf("Loaction of element in array is:\n\n");
	printf("%d ",p+1);
	
	return 0;
}
