//HDU5606
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 1e5+10;

int root[maxn],num[maxn];

int find(int x)
{
    return x==root[x]? x : root[x] = find(root[x]);
}

void Uion(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy)
    {
        root[fx] = fy;
        num[fy] += num[fx];
    }
}

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) root[i] = i,num[i] = 1;
        for(int i = 0;i < n-1;i++)
        {
            int x,y,flag;
            scanf("%d%d%d",&x,&y,&flag);
            if(!flag) Uion(x,y);
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            int f = find(i);
            ans ^= num[f];
        }
        printf("%d\n",ans);
    }
    return 0; 
}