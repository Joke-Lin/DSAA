//八皇后问题是一个古老而著名的问题，是回溯算法的典型例题。该
//问题是十九世纪著名的数学家高斯1850年提出：
//在8X8格的国际象棋上摆放八个皇后，使其不能互相攻击，
//即任意两个皇后都不能处于同一行、同一列或同一斜线(对角线)上，问有多少种摆法。

#include<stdio.h>
#include<stdlib.h>

#define max 8

int queen[max],sum = 0;

void show()  //输出queen 
{
	for(int i = 0;i < max;i++)
	{
		printf("(%d,%d)  ",i+1,queen[i]);
	}
	printf("\n");
	sum++;
}

int check(int n) //检查当前能否放置 
{
	for(int i = 0;i < n;i++)
	{
		if(queen[i]==queen[n]||abs(queen[i]-queen[n])==(n-i))
		{
			return 0;
		}
	}	
	return 1;
}

void putqueen(int n)
{
	int N = n-1;
	for(int i = 1;i <= max;i++)
	{
		queen[N] = i;
		if(check(N))              //如果可以放置 
		{
			if(n == max) show(); //放完了打印 
			else putqueen(n+1);  //没放完就放下一个 
		}
	}
	return;
}

int main()
{
	putqueen(1);
	printf("the sum is %d",sum);
	return 0;
}
