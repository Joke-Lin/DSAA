//HDU1595
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
const int maxn = 1000+10;
const int INF = 0x3f3f3f3f;
int used[maxn];
int dis[maxn][maxn];
int Prev[maxn];
int d[maxn];
int N,V;

void dijkstra(int st,int flag)
{
    fill(Prev,Prev+maxn,-1);
    fill(used,used+maxn,0);
    fill(d,d+maxn,INF);
    d[1] = 0;
    while(true)//其实最多只要N次就可以
    {
        int v = -1;
        for(int i = 1;i <= N;i++)
        {
            if(!used[i] && ((v==-1)||d[i]<d[v])) v = i;
        }
        if(v == -1) break;
        used[v] = 1;
        for(int u = 1;u <= N;u++)
        {
            if(dis[v][u]!=INF && d[u] > d[v]+dis[v][u])
            {
                d[u] = d[v]+dis[v][u];
                if(flag) Prev[u] = v;
            }
        }
    }
}

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    while(~scanf("%d%d",&N,&V))
    {
        fill(dis[0],dis[0]+maxn*maxn,INF);
        for(int i = 0;i < V;i++)
        {
            int st,ed,cost; scanf("%d%d%d",&st,&ed,&cost);
            dis[st][ed] = dis[ed][st] = cost;
        }
        dijkstra(1,1);
        vector<int> path;
        for(int t = N;t != -1;t = Prev[t]) path.push_back(t);
        reverse(path.begin(),path.end());
        int ans = d[N];
        for(int i = 0;i < path.size()-1;i++)
        {
            int a = path[i],b = path[i+1];
            int temp = dis[a][b];
            dis[a][b] = dis[b][a] = INF;
            dijkstra(1,0);
            if(d[N]!=INF) ans = max(ans,d[N]);
            dis[a][b] = dis[b][a] =  temp;
        }
        printf("%d\n",ans);
    }
    return 0;
}