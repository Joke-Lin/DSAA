// https://vjudge.net/contest/245338#problem/A
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define LOCAL

using namespace std;
const int maxn = 1000+10;
const int INF = 0x3f3f3f3f;

struct edge{
    int to,cap,rev;
    edge(int a = 0,int b = 0,int c = 0):to(a),cap(b),rev(c){}
};//终点 容量 反向边

vector<edge> G[maxn];
bool used[maxn];

void add_edge(int from,int to,int cap)//妙
{
    G[from].push_back(edge(to,cap,G[to].size()));//反向边就是下面的
    G[to].push_back(edge(from,0,G[from].size()-1));//上面的那个
}

//DFS寻路
int dfs(int v,int t,int f) //st ed 最大流量
{
    if(v == t) return f;
    used[v] = true;
    for(int i = 0;i < G[v].size();i++) //遍历每一个子边
    {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0)//没有走过并且可以通过
        {
            int d = dfs(e.to,t,min(f,e.cap));//流量以最小的为主 d为下个节点通过最大流量
            if(d > 0)
            {
                e.cap -= d;//残量 最小为0
                G[e.to][e.rev].cap += d;//反向加上去
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s,int t)
{
    int flow = 0;
    while(true)
    {
        memset(used,0,sizeof(used));
        int f = dfs(s,t,INF);
        if(f == 0) return flow;
        flow += f;
    }
}


int main()
{
#ifdef LOCAL
    freopen("../string/in.txt","r",stdin);
    freopen("../string/out.txt","w",stdout);
#endif
    int T;scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++)
    {
        int n,m;scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++) G[i].clear();
        for(int i = 0;i < m;i++)
        {
            int s,t,cap;
            scanf("%d%d%d",&s,&t,&cap);
            add_edge(s,t,cap);
        }
        printf("Case %d: %d\n",kase,max_flow(1,n));
    }
    return 0;
}
