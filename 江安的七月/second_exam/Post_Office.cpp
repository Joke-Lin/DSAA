//POJ1160
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
const int maxn = 300+10;

using namespace std;

int pos[maxn];
int sum[maxn][maxn];
int dp[maxn][maxn];//dp[i][j]表示前i个村庄放 j个邮局的最优解

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    memset(dp,0x3f,sizeof(dp));
    int n,m;//n个村 m个加油站
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%d",pos+i);
    for(int i = 1;i <= n;i++)//起点 初始化只有一个邮局的时候该放到哪里
    {
        for(int j = i;j <= n;j++)//终点
        {
            int best = (i+j) >> 1;
            sum[i][j] = 0;
            for(int k = i;k <= j;k++) sum[i][j] += abs(pos[best]-pos[k]);
            if(i == 1) dp[j][1] = sum[i][j];
            // printf("(%d , %d) sum: %d\n",i,j,sum[i][j]);
        }
    }
    //DP开始 目标结果dp[n][m]
    for(int i = 1;i <= n;i++)
    {
        for(int j = 2;j <= m;j++)
        {
            if(j >= i)
            {
                dp[i][j] = 0;
                continue;
            }
            for(int k = 1;k <= i;k++)//新的一个邮局放在哪儿
            {
                dp[i][j] = min(dp[i][j],dp[k][j-1]+sum[k+1][i]);//状态转移
            }
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}