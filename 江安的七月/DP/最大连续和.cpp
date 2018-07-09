//:HDU1231  http://acm.hdu.edu.cn/showproblem.php?pid=1231

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<memory.h>

using namespace std;

int array[10005];
int dp[10005];

int main()
{
	int n;
	while(scanf("%d",&n))
	{
		int Max = 0;
		int flag = false;
		memset(array,0,sizeof(array));
		memset(dp,0,sizeof(dp));
		if(n == 0) break;
		for(int i = 0;i < n;i++) 
		{
			scanf("%d",&array[i]);
			if(array[i] >= 0) flag = true;
			if(i == 0) dp[0] = array[i];
			else dp[i] = max(0,dp[i-1])+array[i];
			Max = dp[i] > dp[Max] ? i : Max;
		}
		int min = 0;
		for(int i = Max-1;;i--)
		{
			if(dp[i] <= 0) 
			{
				min = i+1;
				break;
			}
		}
		if(flag) printf("%d %d %d\n",dp[Max],array[min],array[Max]);
		else printf("%d %d %d\n",0,array[0],array[n-1]);
	}
	
	return 0;
}