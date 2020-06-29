//:page332
//Dp+组合数

#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;

const int maxn = 1000+10;
const int MOD = 10056; //设置取余值，防止溢出

int f[maxn];//用于存储只有n个人的时候的方案数量
int C[maxn][maxn];//组合数数组C(n,i)=n个数选i个数组合

void init();//初始化f数组

int main()
{
    init();
    int T; scanf("%d",&T);
    for(int Case = 1;Case <= T;Case++)
    {
        int n; scanf("%d",&n);
        printf("Case %d: %d\n",Case,f[n]);
    }
    system("pause");
    return 0;
}

void init()
{
    memset(f,0,sizeof(f));
    for(int i = 1;i <= maxn-10;i++)
    {
        C[i][0] = C[i][i] = 1;//边界处理
        for(int j = 1;j < i;j++) C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;//important
    }
    f[0] = f[1] = 1;
    for(int i = 2;i <= maxn-10;i++)//最大就只有1000
    {
        for(int j = 1;j <= i;j++) f[i] = (f[i]+C[i][j]*f[i-j])%MOD;
    }
}