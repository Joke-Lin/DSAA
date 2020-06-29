#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn = 1010;
const int INF = 0x3f3f3f3f;
int map[maxn][maxn];
int dis[maxn];
int dp[maxn];
int used[maxn];

int n,m;//点，边

void dijkstra()
{
    dis[2] = 0;
    while(true)//其实最多只要N次就可以
    {
        int v = -1;
        for(int i = 1;i <= n;i++)
        {
            if(!used[i] && ((v==-1)||dis[i]<dis[v])) v = i;
        }
        if(v == -1) break;
        used[v] = 1;
        for(int i = 1;i <= n;i++)
            dis[i] = min(dis[i],dis[v]+map[v][i]);
    }
}

int dfs(int v)
{
    int sum=0;
    if(dp[v] != -1) return dp[v];//搜到第v个结点的时候直接拿过来用就行了 记忆话搜索
    if(v==2) return 1;
    for(int i=1;i<=n;i++){
        if(map[v][i]!=INF&&dis[v]>dis[i])
            sum+=dfs(i);
    }
    dp[v]=sum;
    return dp[v];
}

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        memset(dp,-1,sizeof(dp));
        memset(used,0,sizeof(used));
        fill(map[0],map[0]+maxn*maxn,INF);
        fill(dis,dis+maxn,INF);
        for(int i = 0;i < m;i++){
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            map[x][y] = map[y][x] = d;
        }
        dijkstra();
        // for(int i = 1;i <= n;i++) printf("%d ",dis[i]);
        printf("%d\n",dfs(1));
    }

    return 0;
}