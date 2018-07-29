//迪杰斯特拉 样例
//此章节皆为书本原题
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<cstring>
#include<cmath>

const int INF = 0x3f3f3f3f;
const int maxn = 100+10;

using namespace std;

int cost[maxn][maxn];
int V,N;
int dis[maxn];
int used[maxn];

void solusion_1();
void solusion_2();
void solusion_3(int);//n*logn 利用堆的优化

struct cmp{
    bool operator ()(int a,int b)
    {
        return dis[a] > dis[b];
    }
};

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    scanf("%d %d",&N,&V);
    fill(cost[0],cost[0]+maxn*maxn,INF);
    fill(dis,dis+maxn,INF);
    fill(used,used+maxn,0);
    for(int i = 0;i < V;i++)
    {
        int x,y,z; scanf("%d%d%d",&x,&y,&z);
        cost[x][y] = cost[y][x] = z;
    }
    //solusion_1();
    solusion_3(1);
    printf("solution 3:\n");
    for(int i = 1;i<=N;i++) printf("%d ",dis[i]);
    return 0;
}

void solusion_1()
{
    dis[1] = 0;
    for(int i = 0;i < N;i++)
    {
        int u; //最小的哪个的下标
        int MIN = INF;
        for(int j = 1;j <= N;j++)
        {
            if(!used[j] && dis[j] < MIN)
            {
                u = j;
                MIN = dis[j];
            }
        }
        used[u] = 1;
        for(int j = 1;j <= N;j++)
        {
            if(cost[u][j] < INF) dis[j] = min(dis[j],dis[u]+cost[u][j]);
        }
    }
}

void solusion_2()//不用管是不是可以联通 INF就是最大
{
    dis[1] = 0;
    while(true)//其实最多只要N次就可以
    {
        int v = -1;
        for(int i = 1;i <= N;i++)
        {
            if(!used[i] && ((v==-1)||dis[i]<dis[v])) v = i;
        }
        if(v == -1) break;
        used[v] = 1;
        for(int i = 1;i <= N;i++)
            dis[i] = min(dis[i],dis[v]+cost[v][i]);
    }
}

void solusion_3(int t)
{
    dis[t] = 0;
    priority_queue<int,vector<int>,cmp> que;
    que.push(t);//t这个点放入堆
    while(!que.empty())
    {
        int point_min = que.top(); que.pop();
        for(int i = 1;i <= N;i++)
        {
            if(cost[point_min][i]<INF && dis[point_min] + cost[point_min][i] < dis[i])
            {
                dis[i] = dis[point_min] + cost[point_min][i];
                que.push(i);
            }
        }
    }
}