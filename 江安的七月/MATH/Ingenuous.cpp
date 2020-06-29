//:page332
//Dp+组合数
//https://blog.csdn.net/hsj970319/article/details/61414471
//http://www.cnblogs.com/xiaodanding/archive/2012/11/24/3266923.html

#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;

const int maxn = 10000;
const int kinds = 21; //有21种货币

long long dp[kinds+1][maxn+1];
long long coin_v[25];

void init();

int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF) //~scanf("")
    {
        printf("%lld\n",dp[21][n]);
    }

    return 0;
}

void init()
{
    memset(dp,0,sizeof(dp));
    memset(coin_v,0,sizeof(coin_v));

    for(int i = 1;i <= kinds;i++) coin_v[i] = i*i*i;//面值
    dp[0][0] = 1;
    for(int i = 1;i <= kinds;i++)
    {
        for(int j = 0;j <= maxn;j++)
        {
            if(j>= coin_v[i]) dp[i][j]+=dp[i][j-coin_v[i]];//充分利用之前获得的数据
            dp[i][j]+=dp[i-1][j];//博客里的k在这里从大到小递推
        }
    }
    return;
}