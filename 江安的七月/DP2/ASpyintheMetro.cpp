//Uva1025
//紫书page268
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;
const int INF = 0x3f3f3f3f;

int n,T;
int t[60];//从i->j所需的时间t[2]表示从2->3的时间
int M1,M2;
int dp[250][60];//dp[i][j]在时刻i车站j最少还要多少等待时间
int has_train[450][60][2];//0右1左

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int kase = 0;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&T);
        for(int i = 1;i < n;i++) scanf("%d",t+i);
        memset(has_train,0,sizeof(has_train));
        scanf("%d",&M1);
        for(int i = 0; i < M1;i++)
        {
            int st; scanf("%d",&st);
            has_train[st][1][0] = 1;
            for(int j = 1;j < n;j++)
            {
                has_train[st+t[j]][j+1][0] = 1;
                st += t[j];//不要忘记累加
            }
        }
        scanf("%d",&M2);
        for(int i = 0;i < M2;i++)
        {
            int ed; scanf("%d",&ed);
            has_train[ed][n][1] = 1;
            for(int j = n;j > 1;j--) 
            {
                has_train[ed+t[j-1]][j-1][1] = 1;
                ed += t[j-1];
            }
        }
        for(int i = 1;i <= n-1;i++) dp[T][i] = INF;
        dp[T][n] = 0;
        for(int i = T-1;i >= 0;i--)
        {
            for(int j = 1;j <= n;j++)//遍历车站
            {
                dp[i][j] = dp[i+1][j] + 1;//不走等一会
                if(j < n && has_train[i][j][0] && i+t[j] <= T) //右
                    dp[i][j] = min(dp[i][j],dp[i+t[j]][j+1]);
                if(j > 1 && has_train[i][j][1] && i+t[j-1] <= T)//左
                    dp[i][j] = min(dp[i][j],dp[i+t[j-1]][j-1]);
            }
        } 
        printf("Case Number %d: ",++kase);
        if(dp[0][1] >= INF) printf("impossible\n");
        else printf("%d\n",dp[0][1]);
    }    
    return 0;
}