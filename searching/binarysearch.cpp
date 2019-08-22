#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
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
int l=0,u=n-1,m;
while(l<=u)
{
	m=(l+u)/2;
	
	if(val>a[m])
	l=m+1;
	else
	if(val<a[m])
	u=m-1;
	else
	if(val==a[m])
	{
		p=m;
		printf("element found\n\n");
		break;
	}
}
	
	return 0;
}
