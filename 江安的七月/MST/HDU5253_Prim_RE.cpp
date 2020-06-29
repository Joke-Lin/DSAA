#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#define LOCAL

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1010;

int cost[1000000+10][4];//一个点到它四个方向的距离 逆时针记录
int map[maxn][maxn];

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++)
    {
        memset(cost,0x3f,sizeof(cost));
        int n,m;scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++) scanf("%d",&map[i][j]);
        for(int i = 0;i < n;i++)//给每一个点编号 i*m+j
        {
            for(int j = 0;j < m;j++)
            {
                int it = i*m+j;
                int index[4] = {it-m,it+1,it+m,it-1};//逆时针
                for(int k = 0;k < 4;k++)
                {
                    if(index[k]<0 || index[k] >= n*m) continue;
                    if((it % m == 0 && k == 3) || (it+1)%m == 0 && k==1) {
                        //cost[it][k] = INF;
                        continue;
                    }
                    cost[it][k] = abs(map[i][j] - map[index[k]/m][index[k]%m]);
                    // printf("%d %d %d\n",it,k,cost[it][k]);
                }
            }
        }
        int V = n*m;
        int mincost[maxn];
        bool used[maxn];
        for(int i = 0;i < V;i++)
        {
            mincost[i] = INF;
            used[i] = false;
        }
        mincost[0] = 0;
        int res = 0;
        while(true)
        {
            int v = -1;
            for(int i = 0;i < V;i++)
            {
                if(!used[i] && (v==-1 || mincost[i]<mincost[v])) v = i;
            }
            if(v == -1)  break;
            used[v] = true;
            res += mincost[v];
            int index[4] = {v-m,v+1,v+m,v-1};//逆时针
            for(int u = 0;u < 4;u++)
            {
                mincost[index[u]] = min(mincost[index[u]],cost[v][u]);
            }
        }
        printf("Case #%d:\n",kase);
        printf("%d\n",res);
    }
    return 0;
}