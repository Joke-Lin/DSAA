//:page 93
// 题意：给一个n个点的无向图，和一个序列L，问最少需要几次修改使得L串的相邻两个数都相同或者对应图中两个相邻结点。
// 思路：dp，dp[i][j]表示状态为长度i最后一个数字为j的情况需要的最少修改次数。那么状态转移方程很好推出为：
// dp[i][k] = min(dp[i][k], dp[i - 1][j] + (l[i] != k))

#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>

using namespace std;

const int maxn = 205;
const int INF = 0x3f3f3f3f;

int dp[maxn][maxn]; //dp[i][j] 表示把A[i]改为j点时，使序列前i项满足题意的最小修改次数--from TK
bool graph[maxn][maxn]; //邻接矩阵
int L[maxn]; //序列

int n,m,k;

int solve()
{
	for(int i = 1;i <= n;i++) dp[1][i] = 1;//从第一个点变为其他点都需要1次
	dp[1][L[1]] = 0; //自己到自己不用换
	
	for(int i = 2;i<= k;i++) //遍历序列
	{
		for(int j = 1;j<=n;j++) //暴力遍历所有可能的点
		{
			dp[i][j] = INF;
			for(int v = 1;v <= n;v++)//遍历所有点---可能与j相邻 的点
			{
				if(graph[v][j])//如果联通有两个选项，1.自己相同，2.与自己不同
				{
					dp[i][j] = min(dp[i][j],dp[i-1][v]+(j!=L[i]));//相同不必改变+0，不同改变+1
				}
			}
		}
	}
	
	int ans = INF;
	for(int i = 1;i <= n;i++) ans = min(ans,dp[k][i]);//找到最小的那个
	return ans;
}

int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		//清空上次的输入
		memset(dp,0,sizeof(dp));
		memset(graph,0,sizeof(graph));
		memset(L,0,sizeof(L));
		//数据输入
		scanf("%d%d",&n,&m);
		for(int i = 0;i < m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			graph[a][b] = graph[b][a] = true; //初始化邻接图
		}
		for(int i = 1;i <= n;i++) graph[i][i] = true;//自己和自己也算相邻
		scanf("%d",&k);
		for(int i = 1;i <= k;i++) scanf("%d",&L[i]);
		printf("%d\n",solve());
	}
	return 0;
}

