//此章节皆为书本原题
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<cstring>

const int INF = 0x3f3f3f3f;
const int maxn = 1000+10;

using namespace std;

struct P{
    int st,ed,cost;
    P(int a = -1,int b = -1,int c=-1):st(a),ed(b),cost(c){}
};

int cost_1[maxn][maxn];//经济路线的花费
P cost_2[maxn];//商业线的花费  
int N,S,E,M,K;
int prev[maxn];//当前节点最短路的前缀节点 -->用于找到最短路径
int ans;//时间花费

void dijkstra(int st);//从 st 开始到其他各个经济线的点

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    while(cin >> N >> S >> E)
    {
        scanf("%d",&M);
        fill(cost_1[0],cost_1[0]+maxn*maxn,INF);  
        for(int i = 0;i < M;i++)
        {
            int st,ed,cost; scanf("%d%d%d",&st,&ed,&cost);
            cost_1[st][ed] = cost_1[ed][st] = cost;
        }
        scanf("%d",&K);
        for(int i = 0;i < K;i++)
        {
            int st,ed,cost; scanf("%d%d%d",&st,&ed,&cost);
            cost_2[i] = P(st,ed,cost);
            printf("商业 %d :%d %d %d\n",i,cost_2[i].st,cost_2[i].ed,cost_2[i].cost);
        }
    }
    return 0;
}