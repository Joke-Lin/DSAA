#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LOCAL

using namespace std;
const int INF = 0x3f3f3f3f;

struct EDGE
{
    int st,ed,cost;
    EDGE(int a = 0,int b = 0,int c = 0):st(a),ed(b),cost(c){}
    bool operator < (const EDGE& b){ return cost < b.cost;}
};

int father[200];

void init(int n){ for(int i = 1;i <= n+1;i++) father[i]=i;}
int find(int x){ return father[x]==x ? x : father[x] = find(father[x]);}
int karuskal(int);
EDGE edges[20010];
int m,n;


int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    while(~scanf("%d%d",&n,&m),n+m)
    {
        for(int i = 0;i < m;i++)
        {
            int st,ed,cost; scanf("%d%d%d",&st,&ed,&cost);
            edges[i] = EDGE(st,ed,cost);
        }
        sort(edges,edges+m);
        int minn = INF;
        for(int i = 0;i < m;i++)
        {
            minn = min(minn,karuskal(i));
        }
        if(minn != INF) printf("%d\n",minn);
        else printf("-1\n");
    }
    return 0;
}

int karuskal(int k)
{
    init(n);
    if((m-k + 1) < n-1) return INF;
    int number = 0;
    int minn = INF;
    for(int i = k;i < m;i++)
    {
        EDGE e = edges[i];
        int fx = find(e.st);
        int fy = find(e.ed);
        if(fx != fy)
        {
            father[fx] = fy;
            minn = e.cost-edges[k].cost;
            number++;
        }
    }
    return number >= n-1 ? minn : INF;
}