//page275
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 1000+5;
const int INF = 0x3f3f3f3f;

struct LAMP{
    int V,K,C,L;
    bool operator < (const LAMP& rhs){return V<rhs.V;}
}a[maxn];

int n,sum[maxn],dp[maxn];

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    while(scanf("%d",&n),n)
    {
        sum[0] = 0;
        for(int i = 1;i <= n;i++) scanf("%d%d%d%d",&a[i].V,&a[i].K,&a[i].C,&a[i].L);
        sort(a+1,a+n+1);
        for(int i = 1;i <= n;i++) sum[i] = sum[i-1]+a[i].L;
        dp[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            dp[i] = INF;
            for(int j = 0;j < i;j++)
            {
                dp[i] = min(dp[i],dp[j]+(sum[i]-sum[j])*a[i].C+a[i].K);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}