//:poj 3263 基础RMQ
// 有N头牛，给定N头牛的高度，输出给定区间内最高牛的高度与最低牛的高度差
// 输入：第一行两个数N、Q分别代表N头牛，Q个操作区间
// 接下来输入N个数，代表N头牛的高度
// 接下来是Q个操作区间，每一个操作区间输出一个高度差
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 5e5+5;

int d_max[maxn][20],d_min[maxn][20],num[maxn];
int N,Q;

void RMQ_init();//初始化
int RMQ_max(int,int);//最大值
int RMQ_min(int,int);//最小值

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    scanf("%d%d",&N,&Q);
    for(int i = 0;i < N;i++) scanf("%d",num+i);
    RMQ_init();
    for(int i = 0;i < Q ;i++)
    {
        int l,r; scanf("%d%d",&l,&r);
        l--,r--;
        printf("%d\n",RMQ_max(l,r)-RMQ_min(l,r));
    }
    return 0;
}

void RMQ_init()
{
    for(int i = 0;i < N;i++) d_max[i][0] = d_min[i][0] = num[i];
    for(int j = 1;(1<<j) <= N;j++)
    {
        for(int i = 0;i + (1<<j) - 1 < N;i++)
        {
            d_min[i][j] = min(d_min[i][j-1],d_min[i+(1<<(j-1))][j-1]);
            d_max[i][j] = max(d_max[i][j-1],d_max[i+(1<<(j-1))][j-1]);
        }
    }
}

int RMQ_max(int l,int r)
{
    int k = int(log(r-l+1.0)/log(2.0));
    return max(d_max[l][k],d_max[r-(1<<k)+1][k]);
}

int RMQ_min(int l,int r)
{
    int k = int(log(r-l+1.0)/log(2.0));
    return min(d_min[l][k],d_min[r-(1<<k)+1][k]);
}