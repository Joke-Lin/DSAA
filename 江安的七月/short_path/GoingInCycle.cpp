//此题可以当作模板题来用书本的 自带类
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<cstring>
#include<cmath>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 50+5;

struct Edge
{
    int from,to;
    double dist; //书本原edge是int但是此题情况下需改成double
};

struct BellmanFord
{
    int n,m;//点和边
    vector<Edge> edges;
    vector<int> G[maxn];//邻接表
    bool inq[maxn];//判断是否在队列中
    double d[maxn];//存储到各个点的距离
    int p[maxn];//最短路的上一条弧
    int cnt[maxn]; //各个节点进队列的次数

    void init(int n)
    {
        this->n = n;
        for(int i = 0;i < n;i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,double dist)
    {
        edges.push_back(Edge{from,to,dist});
        m = edges.size();
        G[from].push_back(m-1);//将在edges里的边对应上
    }

    bool negativeCycle()
    {
        queue<int> Q;
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));
        for(int i = 0;i < n;i++){
            d[i] = 0;
            Q.push(i);
        }
        while(!Q.empty())
        {
            int u = Q.front();Q.pop();
            inq[u] = false;
            for(int i = 0;i < G[u].size();i++)
            {
                Edge &e = edges[G[u][i]];
                if(d[e.to] > d[u]+e.dist)
                {
                    d[e.to] = d[u]+e.dist;
                    p[e.to] = G[u][i];//对此题没啥子意义
                    if(!inq[e.to]) {
                        Q.push(e.to); 
                        inq[e.to] = true;
                        if(++cnt[e.to] > n) return true;
                    }
                }
            }
        }
        return false;
    }
}solver;

bool test(double x) //查找有没有最小值的
{
    for(int i = 0;i < solver.m;i++) solver.edges[i].dist -= x;//修改
    bool ret = solver.negativeCycle();
    for(int i = 0;i < solver.m;i++) solver.edges[i].dist += x;//复原
    return ret;
}

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++)
    {
        int n,m; scanf("%d%d",&n,&m);
        solver.init(n);
        int nb = 0;//最大权
        while(m--){
            int st,ed,dist;
            scanf("%d%d%d",&st,&ed,&dist);
            st--,ed--;//此处节点从0开始
            nb = max(nb,dist);
            solver.AddEdge(st,ed,dist);
        }
        printf("Case #%d: ",kase);
        if(!test(nb+1)) printf("No cycle found.\n");
        else{
            double L = 0,R = nb;
            while(R-L > 1e-3)//精度在三位小数
            {
                double M = (L+R)/2.0;
                if(test(M)) R = M;
                else L = M;
            }
            printf("%.2lf\n",L);
        }
    }
    return 0;
}