#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
// #define LOCAL

const int maxn = 1e6+10;

int vis[maxn];
int dp[maxn];
void sieve()
{
    int m = (int)sqrt(maxn+0.5);
    memset(vis,0,sizeof(vis));
    for(int i = 2;i <= maxn;i++)
        for(int j = i;j <= maxn;j+=i) 
        {
            vis[j]++;
        }
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    sieve();
    memset(dp,0,sizeof(dp));
    dp[6] = 1;
    for(int i = 7;i < maxn;i++) vis[i]==3 ? dp[i] = dp[i-1]+1 : dp[i]=dp[i-1];
    int T;scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    system("pause");
    return 0;
}