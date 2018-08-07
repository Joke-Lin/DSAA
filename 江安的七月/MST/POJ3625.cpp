#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define LOCAL

using namespace std;
const double INF = 0x3f3f3f3f3f3f3f3f;

struct NODE
{
    double x,y;
    NODE(int a = 0,int b = 0):x(a),y(b){}
}nodes[1010];

double cost[1010][1010];

double cal_dis(const NODE& a,const NODE& b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    memset(cost,0,sizeof(cost));
    int n,m; scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%lf%lf",&nodes[i].x,&nodes[i].y);
    for(int i = 1;i <= n;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            cost[i][j] = cost[j][i] = cal_dis(nodes[i],nodes[j]);
        }
    }
    while(m--)
    {
        int x,y; scanf("%d%d",&x,&y);
        cost[x][y] = cost[y][x] = 0;
    }
    //PRIM
    double mincost[1010];
    bool used[1010];
    fill(used,used+n+1,false);
    fill(mincost,mincost+n+1,INF);
    mincost[1] = 0;
    double res = 0;
    while(true)
    {
        int v = -1;
        for(int u = 1;u <= n;u++)
        {
            if(!used[u] && (v == -1 || mincost[u]<mincost[v])) v = u;
        }
        if(v == -1)  break;
        used[v] = true;
        res += mincost[v];
        for(int u = 1; u <= n;u++) mincost[u] = min(mincost[u],cost[v][u]);
    }
    printf("%.2f\n",res);
    return 0;
}