//https://www.cnblogs.com/lidaxin/p/4914450.html
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<cstring>
#include<cmath>
#define FOR(a,b,c) for(int a=(b);a<=(c);a++)

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 100+10,maxm = 1000+10;

struct Edge{
    int u,v,w,next;
};
struct SPFA
{
    int n;
    Edge e[2*maxm];
    int en,front[maxn];//en等于当前的边数
    int inq[maxn],d[maxn];
    int p[maxn];//前缀
    queue<int> q;

    void init(int n){
        this->n = n;
        en = -1;
        memset(front,-1,sizeof(front));
    }

    void AddEdge(int u,int v,int w){
        en++;
        e[en].u = u;
        e[en].v = v;
        e[en].w = w;
        e[en].next = front[u];
        front[u] = en;
    }

    void solve(int s)//点s的最短路
    {
        memset(inq,0,sizeof(inq));
        memset(p,0,sizeof(p));
        for(int i = 1;i <= n;i++) d[i] = INF;
        d[s] = 0;
        inq[s] = 1;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();q.pop();inq[u] = 0;
            for(int i = front[u];i>=0;i = e[i].next)
            {
                int v = e[i].v,w = e[i].w;
                if(w>0 &&d[v]>d[u]+w)//w= 0 表示此边已断
                {
                    d[v] = d[u] + w;
                    p[v] = i;
                    if(!inq[v])
                    {
                        inq[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }
}spfa;

int n,m,L;
vector<int> gr[maxn][maxn];  //保存ij之间所有的边  为了更好的处理重边的情况
int idx[maxn][maxn];         //边ij在SPFA中对应的编号 
int used[maxn][maxn][maxn];  //used[scr][u][v]表示在scr为根的最短路树上边uv是否出现 
int sum_single[maxn];        //scr的最短路树的d[]之和

int CALC_C() {
    int ans=0;
    memset(used,0,sizeof(used));
    FOR(scr,1,n) 
    {
        spfa.solve(scr);
        sum_single[scr]=0;
        FOR(v,1,n)
        {
           if(v!=scr) {
                   int u=spfa.e[spfa.p[v]].u;
                   used[scr][u][v]=used[scr][v][u]=1;
           }
           sum_single[scr] += spfa.d[v]==INF? L : spfa.d[v];
        }
        ans += sum_single[scr];
    }
    return ans;
}
int CALC_C2(int a,int b) {
    int ans=0;
    FOR(scr,1,n)
    {
          if(!used[scr][a][b]) ans+=sum_single[scr];  
          //如果边ij没有出现在i的最短路树上则无须重新计算 
          else
          {
                spfa.solve(scr);
                FOR(v,1,n) ans += spfa.d[v]==INF?L: spfa.d[v];
          }
    }
    return ans;
}


int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    while(scanf("%d%d%d",&n,&m,&L)==3)  //==3 否则会TLE 
    {
        int u,v,w;
        spfa.init(n);
        FOR(i,1,n) FOR(j,1,n) gr[i][j].clear();
        while(m--) {
            scanf("%d%d%d",&u,&v,&w);
            gr[u][v].push_back(w);
            gr[v][u].push_back(w);
        }
        FOR(i,1,n) FOR(j,i+1,n) if(!gr[i][j].empty()){
            sort(gr[i][j].begin(),gr[i][j].end());
            spfa.AddEdge(i,j,gr[i][j][0]);
            idx[i][j]=spfa.en;
            spfa.AddEdge(j,i,gr[i][j][0]);
            idx[j][i]=spfa.en;
        }
        int c=CALC_C(),c2=-1;
        FOR(i,1,n) FOR(j,i+1,n) if(!gr[i][j].empty()){
            int& e1=spfa.e[idx[i][j]].w;
            int& e2=spfa.e[idx[j][i]].w;
            if(gr[i][j].size()==1) e1=e2=-1;
            else e1=e2=gr[i][j][1];          //用次短边代替 
            c2=max(c2,CALC_C2(i,j));         //"删除" ij之间的边之后计算c2
            e1=e2=gr[i][j][0];
        }
        printf("%d %d\n",c,c2);
    }
    return 0;

}