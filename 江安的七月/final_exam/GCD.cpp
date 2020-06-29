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
typedef long long ll;


int number[maxn];
int GCD[maxn][30];
int m,n; 

void RMQ_init()
{
    for(int i = 0;i < n;i++) GCD[i][0] = number[i];
    for(int j = 1;(1<<j) <= n;j++)
        for(int i = 0;i + (1<<j) - 1 < n;i++)
            GCD[i][j] = max(GCD[i][j-1],GCD[i+(1<<(j-1))][j-1]);
}

int RMQ(int l,int r)
{
    //int k = int(log(r-l+1.0)/log(2.0));
    int k = 0;
    while((1<<(k+1))<=r-l+1) k++;
    return max(GCD[l][k],GCD[r-(1<<k)+1][k]);
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
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++) scanf("%d",number+i);
        RMQ_init();
        while(m--)
        {
            int l,r; scanf("%d%d",&l,&r);
            l--,r--;
            printf("%d\n",RMQ(l,r));
        }
    }
    return 0;
}