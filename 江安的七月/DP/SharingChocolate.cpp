//:page75
//https://www.cnblogs.com/hlmark/p/4059654.html
//https://blog.csdn.net/accelerator_/article/details/19285265

#include<iostream>
#include<cstdio>
#include<memory.h>

const int maxn = 16;//一共有15种情况
const int maxw = 110;//100+10

int n,A[maxn],sum[1<<maxn],f[1<<maxn][maxn],vis[1<<maxn][maxn];
//sum[1<<maxn] :每个集合中所有元素之和
//f[S][r] :在r行sum(S)/r列能不能切成S
//vis[S][r]:存储状态visit

int bitcount(int x) {return x==0 ? 0: bitcount(x>>1)+(x&1);}//计算x中1的个数，即集合X中的存储数据数

using namespace std;

int dp(int S,int x)
{
	if(vis[S][x]) return f[S][x];//如果是已经遍历过的组合则直接返回
	vis[S][x] = 1;//置为已经访问了
	int& ans = f[S][x];
	if(bitcount(S)==1) return ans = 1;//只有一种情况时 比可以分为x sum[x]/x 块
	int y = sum[S]/x;
	for(int S0 = (S-1)&S;S0;S0 = (S0-1)&S)//遍历S的真子集
	{
		int S1 = S-S0;
		if(sum[S0]%x==0 && dp(S0,min(x,sum[S0]/x)) && dp(S1,min(x,sum[S1]/x))) return ans = 1;
		//如果dp(S0,x) == 1并且他的补集也是1那么他就是可以拆分
		if(sum[S0]%y==0 && dp(S0,min(y,sum[S0]/y)) && dp(S1,min(y,sum[S1]/y))) return ans = 1; //和上同改为y做变量
	} 
	return ans=0;
}

int main()
{
	int kase = 0; int n,x,y;
	while(scanf("%d",&n)==1 && n)//输入组数
	{
		scanf("%d%d",&x,&y);
		for(int i = 0;i < n;i++) scanf("%d",&A[i]);//输入需要的面积
		memset(sum,0,sizeof(sum));
		memset(vis,0,sizeof(vis));
		//每个子集的元素和
		for(int S = 0;S < (1<<n);S++)//遍历所有可能的组合，对n个小面积的不同组合的面积和
		{
			for(int i = 0;i < n;i++)
			{
				if(S & (1<<i)) sum[S] += A[i];
			}
		}
		
		int All = (1<<n) - 1;//最后的那种情况
		int ans;
		if(sum[All] != x*y || sum[All]%x != 0) ans = 0; //提前排除不可能的情况
		else ans = dp(All,min(x,y));
		printf("Case %d: %s\n",++kase,ans?"Yes":"No");
	}
	return 0;
}