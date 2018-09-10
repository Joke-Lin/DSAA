#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define LOCAL

using namespace std;
const int maxn = 1e5+10;

int number[maxn];
int d[maxn][30];
int m,n; 

void RMQ_init()
{
    for(int i = 0;i < n;i++) d[i][0] = number[i];
    for(int j = 1;(1<<j) <= n;j++)
        for(int i = 0;i + (1<<j) - 1 < n;i++)
            {
                d[i][j] = min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
            }
}

int RMQ(int l,int r)
{
    int k = int(log(r-l+1.0)/log(2.0));
    return min(d[l][k],d[r-(1<<k)+1][k]);
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int T; scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0;i < n;i++) scanf("%d",number+i);
        RMQ_init();
        long long ans = 0;
        for(int j = 0;(1<<j) <= n;j++)
        {
            for(int i = 0;i + (1<<j) - 1 < n;i++)
            {
                ans += d[i][j];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}