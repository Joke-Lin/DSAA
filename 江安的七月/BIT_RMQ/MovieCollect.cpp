// 给你一叠DV，编号1到n，1在最上面，n在最下面。然后现在给你m个操作，每次都指定一张CD，
// 问要拿走这个CD需要挪走上面多少张CD，并且这个要拿走的CD放在这个叠CD的顶端。
// 解题思路：将这些CD的上面有多少张CD用数状数组来存储，但是每次要移动的话就有点难办，
// 所以每次移动就将这张CD的pos更新一下，将之前的pos作废，以后查询也是用之后的pos。
// 题意：给你n盘歌碟按照（1....n）从上到下放，接着m个询问，每一次拿出x碟，输出x上方有多少碟并将此碟放到开头
// 直接想其实就是一线段的区间更新，单点求值，但是根据题意我们可以这样想
// 首先我们倒着存  n--1，接着每次询问时把放碟子放到最后，这样我们要开一个映射数组映射每个碟子在哪个位置
// 其中我们需要使用树状数组维护每个绝对位置是否有碟子（有些碟子已经放到了后面了），再使用区间求和就好了
#include<iostream>
#include<cstdio>
#include<cstring>
#define lowbit(x) (x&(-x))

using namespace std;

const int maxn = 1e5+5;

int pos[maxn],C[2*maxn];//pos编号i的位置

void add(int x,int d)
{
    while(x < 2*maxn)
    {
        C[x] += d; x += lowbit(x);
    }
}

int sum(int x)
{
    int ans = 0;
    while(x)
    {
        ans += C[x]; x -= lowbit(x);
    }
    return ans;
}

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    int n,m,Case;
    scanf("%d",&Case);
    while(Case--)
    {
        scanf("%d%d",&n,&m);
        int Sum = n;
        memset(C,0,sizeof(C));
        for(int i = 1;i <= n;i++)//顶在右所以可以用完了放到最顶
        {
            pos[i] = n-i+1;
            add(pos[i],1);
        }
        for(int i = 1;i <= m;i++)
        {
            int x;
            scanf("%d",&x);
            printf("%d%c",n-sum(pos[x]),i==m?'\n':' ');
            add(pos[x],-1);
            pos[x] = ++Sum;
            add(pos[x],1);
        }
    }
    return 0;
}