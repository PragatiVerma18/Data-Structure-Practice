#include<stdio.h>

int rfib(int n)
{
	if(n<=1)
	return n;
	printf("%d", rfib(n-1)+rfib(n-2));
	return rfib(n-1)+rfib(n-2);
}

int main()
{
	printf("%d\n", rfib(10));
	
	return 0;
}
