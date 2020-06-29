#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define LOCAL

using namespace std;
const int maxn = 100+10;

struct EDGE
{
    int st,ed,cost;
    EDGE(int a=0,int b=0,int c=0):st(a),ed(b),cost(c){}
    bool operator < (const EDGE& b){ return cost < b.cost;}
}edges[50*maxn];

int father[maxn];
int map[maxn][maxn];
int n,m;

void init(int n){ for(int i = 0;i <= n+1;i++) father[i] = i;}
int find(int x){ return x==father[x] ? x : father[x] = find(father[x]);}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++) scanf("%d",&map[i][j]);
    scanf("%d",&m);
    for(int i = 0;i < m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        map[x-1][y-1] = map[y-1][x-1] = 0;
    }
    int v = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = i+1;j < n;j++)
        {
            edges[v++] = EDGE(i,j,map[i][j]);
        }
    }
    init(n);
    sort(edges,edges+v);
    int res = 0;
    for(int i = 0;i < v;i++)
    {
        EDGE e = edges[i];
        int fx = find(e.st);
        int fy = find(e.ed);
        if(fx != fy)
        {
            father[fx] = fy;
            res += e.cost;
        }
    }
    printf("%d",res);
    return 0;
}