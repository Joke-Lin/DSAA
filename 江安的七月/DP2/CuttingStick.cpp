//page278
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 1010;
const int INF = 0x3f3f3f3f;

int dp[maxn][maxn],cut[maxn];//dp[i][j]代表从i->j闭区间的最小花费

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int n,L;
    while(scanf("%d",&L)==1,L)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i ++) scanf("%d",cut+i);
        cut[0] = 0,cut[n+1] =  L;
        memset(dp,0,sizeof(dp));//初始化为最大值
        for(int len = 1;len <= n+1;len++)//区间长度 以切点划分
        {
            for(int i = 0; i <= n+1;i++)//起点
            {
                if(len == 1) continue;//len = 1时 不用切
                int j = i+len;//有端点
                dp[i][j] = INF;
                for(int k = i+1;k < j;k++)
                {
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+cut[j]-cut[i]);
                }
            }
        }
        printf("The minimum cutting is %d.\n",dp[0][n+1]);
    }
    return 0;
}