// https://www.cnblogs.com/kuangbin/archive/2012/09/20/2696052.html
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define CLS(x) memset(x,0,sizeof(x))
using namespace std;

const int maxn = 100000+10;

int a[maxn];//存数组
int b[maxn];//存当前出现的个数，从后往前
int dp[maxn][20];//从i开始到1<<j的最值ＲＭＱ

void RMQ_init(int,int []);
int rmq(int,int);
int bit_search(int,int);

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    int n,q;
    int s,t;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&q);
        for(int i = 0;i < n;i++) scanf("%d",a+i);
        int count = 1;
        for(int i = n-1;i >= 0;i--)
        {
            if(i != n-1)
            {
                if(a[i] == a[i+1]) count++;
                else count = 1;
            }
            b[i] = count;
        }
        RMQ_init(n,b);
        //for(int i = 0;i < n;i++) printf("i= %d %d\n",i,b[i]);
        while(q--)
        {
            scanf("%d%d",&s,&t);
            s--,t--;//从0开始的数组
            int temp = bit_search(s,t);//与最右边值相同的下标，与上边从后往前取值相呼应
            int ans = t-temp+1;//与最右边相同的个数
            t = temp-1;//更新t t为左边的值（排除右边相同部分）
            if(s > t) printf("%d\n",ans); //都是相同的值
            else printf("%d\n",max(ans,rmq(s,t)));
        }
    }
    return 0;
}

void RMQ_init(int n,int b[])
{
    //CLS(b);
    for(int i = 0;i < n;i++) dp[i][0] = b[i];
    for(int j = 1;(1<<j) <= n;j++){
        for(int i = 0;i+(1<<j)-1 < n;i++){
            dp[i][j] = max(dp[i][j-1],dp[i + (1<<j-1)][j-1]);
        }
    }
}

int rmq(int l,int r)
{
    int k = (int)(log(r-l+1.0)/log(2.0));
    return max(dp[l][k],dp[r-(1<<k)+1][k]);
}

int bit_search(int l,int r)
{
    int temp = a[r];
    int mid;
    while(l < r)
    {
        mid = (l+r)>>1;
        if(a[mid] >= temp) r = mid;
        else l = mid+1;
    }
    return r;
}