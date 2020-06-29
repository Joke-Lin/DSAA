//:判断一个串最少可以分解为多少个对称串 

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<memory.h>

using namespace std;

const int maxn = 1010;

char str[maxn];
int dp[maxn];//dp[i]：从0到i的最少回文子串

bool judge(int a,int b) //判断是不是回文串 a->b包括a,b
{
	while(a <= b && str[a]==str[b])
	{
		a++;
		b--;
	}
	return a >= b;
}

int main()
{
	
	int T; scanf("%d",&T);
	while(T--)
	{
		memset(str,0,sizeof(str));
		memset(dp,0x3f,sizeof(dp));
		scanf("%s",&str);
		
		//dp[0] = 1;//只有一个字符的时候长度为1
		for(int i = 0;i < strlen(str);i++)
		{
			for(int j = 0;j <= i;j++)
			{
				if(j==0 && judge(j,i)) //对0特别讨论
				{
					dp[i] = 1;
					continue;
				}
				if(judge(j,i)) dp[i] = min(dp[i],dp[j-1]+1); 
			}
		}
		printf("%d\n",dp[strlen(str)-1]);
	}
	
	return 0;
}