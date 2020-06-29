//learning about Fibonacci 
#include<stdio.h>

int FIB1(int n) //return the result in N----recurrence
{
	int k = n-1;
	if(k == 0) return 0;
	else if(k == 1) return 1;
	else 
	{
		int F = -1;
		int F1 = 0,F2 = 1;
		while(k>1)
		{
			F = F2 + F1;
			F1 = F2;
			F2 = F;
			k--;
		}
		return F;
	}
}

int FIB2(int n)//return the result in N----recursion
{
	if(n == 1) return 0;
	else if(n == 2) return 1;
	else return (FIB2(n-1)+FIB2(n-2));
}

int main()
{
	//Function FIB1
	for(int i = 1;i <= 10;i++)
	{
		printf("%d ",FIB1(i));
	}
	printf("\n");
	//Function FIB2
	for(int i = 1;i <= 10;i++)
	{
		printf("%d ",FIB2(i));
	}
	getchar();
	return 0;
}
