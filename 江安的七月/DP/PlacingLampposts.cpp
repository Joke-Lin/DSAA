//:page70
//树形递归
//https://blog.csdn.net/keshuai19940722/article/details/19363649

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<memory.h>

using namespace std;

const int M = 2000;//每开一个灯就加M
const int N = 1010;

int n,m;//点数和m行数据
int v[N];
int dp[N][2];//dp[i][j]以i为根节点的状态是j的最小X j=0 or 1(on/off)
vector<int> g[N];//邻接矩阵

void init()		//数据初始化
{
	scanf("%d%d",&n,&m);
	
	for(int i = 0;i < n;i++) g[i].clear(); //清空数据，每次重新输入后
	memset(v,0,sizeof(v));
	memset(dp,0,sizeof(dp));
	
	for(int i = 0;i < m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);//无向图 初始化邻接表
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

void dfs(int x)//深搜遍历整棵树 以x为顶点  0<x<n-1 
{
	//根节点预处理
	v[x] = 1;  //表明这个点已经遍历过
	dp[x][0] = 0;//顶点不开灯为0
	dp[x][1] = M;//开灯为M
	//子节点
	for(int i = 0;i < g[x].size();i++)//遍历邻接表
	{
		int u =g[x][i];//与X相邻的点
		if(v[u]) continue; //防止重复遍历
		dfs(u);//深搜继续遍历下一个
		dp[x][0] += dp[u][1] + 1;//父节点不放灯的情况，子节点放灯
		if(dp[u][1] > dp[u][0]) dp[x][1] += dp[u][0]+1;//父节点放灯，并且子节点不放灯
		else dp[x][1] += dp[u][1];//两个都放灯
	}
}

void solve()
{
	int ans = 0;
	for(int i = 0;i < n;i++)//遍历节点
	{
		if(!v[i])//如果是没有遍历过的点，因为每次DFS都会把其子点遍历，这些点就没有必要了
		{
			dfs(i);
			ans += min(dp[i][0],dp[i][1]);//选择较小的
		}
	}
	printf("%d %d %d\n",ans/M,m-ans%M,ans%M);
}

int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		init();
		solve();
	}
	return 0;
}

