//POJ2828
//http://hzwer.com/1776.html
#include<iostream>
#include<cstdio>

const int maxn = 2e5+10;

using namespace std;

struct date
{
    int l,r,x;
}tr[maxn*4];//防止溢出开四倍
int ans[maxn];//存序列
int a[maxn],b[maxn],n;

void Add(int k);//将两个节点合并成自己
void build(int k,int l,int r);//搭建树
void update(int k,int x,int y);//更新

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    while(~scanf("%d",&n))
    {
        build(1,1,maxn);
        for(int i = 1;i <= n;i++) {
            scanf("%d%d",a+i,b+i);
            a[i]++;//从1开始编号
        }
        for(int i = n;i >= 1;i--) update(1,a[i],b[i]);
        for(int i = 1;i <= n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}

void add(int k)
{
    tr[k].x = tr[k<<1].x+tr[k<<1|1].x;
}

void build(int k,int l,int r)
{
    tr[k].l = l; tr[k].r = r;
    if(l == r) { tr[k].x = 1; return;}
    int mid = (l+r)>>1;
    build(k<<1,l,mid); build(k<<1|1,mid+1,r);
    add(k);
}

void update(int k,int x,int y)
{
    int l = tr[k].l; int r = tr[k].r;
    if(l == r){ans[l] = y;tr[k].x = 0; return;}
    if(tr[k<<1].x >= x) update(k<<1,x,y);
    else update(k<<1|1,x-tr[k<<1].x,y);
    add(k);
}