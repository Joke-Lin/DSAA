//:page68区间动归

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<memory.h>

using namespace std;

const int MAXN = 110;
const int INF = 1e9;

int sum[MAXN];	//从第一个数到i的和 sum[j] - sum[i-1] = sum[i,j]
int dp[MAXN][MAXN]; //dp数组在i,j序列中先手的最高分

void another_solution(){}//n^2复杂度 书本有介绍，注意循环的方式外循环为递增距离

int main()
{
	int n;
	while(scanf("%d",&n))
	{
		if(n == 0) break;
		
		memset(sum,0,sizeof(sum));
		memset(dp,0,sizeof(dp));
		
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&sum[i]);
			sum[i]+=sum[i-1];
		}
		for(int  i = 1;i <= n;i++) dp[i][i] = sum[i] - sum[i-1];//初始化很重要，DP能初始化的尽量都初始化一下
		for(int i = n;i >= 1;i--) //必须从大到小，保证求dp[1,n]时所需的已经计算过了,目标球dp[1,n]
		{
			for(int j = i+1;j <= n;j++)//i->n的先手最大分数
			{
				int MINN = 0;//表示全部取掉
				for(int k = i;k<j;k++)//后手的选择情况，可以左边也可以右边
				{
					MINN = min(dp[i][k],MINN);		//取左边dp[i][j]表示什么都不取（后手全拿）
					MINN = min(dp[k+1][j],MINN); 	//取右边
				}
				dp[i][j] = sum[j]-sum[i-1] - MINN;
			}
		}
		printf("%d\n",dp[1][n]-(sum[n]-dp[1][n]));
	}
	
	return 0;
}

//比较后手的得分时也可以采取递归式子，就可以降低复杂度