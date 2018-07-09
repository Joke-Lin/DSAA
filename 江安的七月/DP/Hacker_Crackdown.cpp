//:page69
//https://blog.csdn.net/sinat_30062549/article/details/51292353

#include<iostream>
#include<cstdio>
#include<memory.h>

using namespace std;

const int MAXN = 16; //最大为16个
int s[MAXN]; //编号为i的电脑的链接电脑的集合,二进制表示
int cover[1<<MAXN];//2^MAXN种组合，表示：每一种分组包含的电脑的个数，cover[i] = j
//eg. cover[3] = 3,表示第0台和第1台电脑组成的组包含第0和第1台电脑，cover[5] = 15,第0和第2台电脑组成的组包含第0,1,2,3台电脑
int dp[1<<MAXN];//dp（S）所需表示子集S最多可以分成多少组

int main()
{
	int n;
	int Case = 1;
	while(scanf("%d",&n)&&n)
	{
		memset(s,0,sizeof(s));
		memset(cover,0,sizeof(cover));
		memset(dp,0,sizeof(dp));
		
		for(int i = 0;i < n;i++)
		{
			int m;	scanf("%d",&m);
			s[i] = 1<<i;//将自己加入
			while(m--)
			{
				int k;	scanf("%d",&k);
				s[i] |= (1<<k);//讲k电脑加入集合
			}
		}
		//获得不同组合搭配下的包含电脑
		for(int i = 0;i < (1<<n);i++) //遍历所有组合类型
		{
			for(int j = 0;j < n;j++)//遍历j号电脑的集合S
			{
				if((1<<j)&i)//如果此电脑在i种组合中
				{
					cover[i] |= s[j];
				}
			}
		}
		
		for(int i = 0;i < (1<<n);i++)
		{
			for(int s0 = i;s0;s0 = (s0-1)&i)//遍历子集
			{
				if(cover[s0] == (1<<n)-1)//如果该组合包含所有组合
				{
					dp[i] = max(dp[i],dp[s0^i]+1);//取i和不取i的最大一个
				}
			}
		}
		printf("Case %d: %d\n",Case++,dp[(1<<n)-1]);
	}
	
	return 0;
}