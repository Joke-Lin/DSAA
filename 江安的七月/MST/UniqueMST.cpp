//http://poj.org/showmessage?message_id=344513  
//POJ1679
//好的数据检测
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define LOCKAL

using namespace std;
const int INF = 0x3f3f3f3f;

struct edge
{
    int st,ed,cost;
    bool operator < (const edge& another)
    {
        return cost < another.cost;
    }
}edges[1000000];//范围都不给。。。。

int father[1000];
int min_edge[1000000];
int n,v,min_edge_sum;

int find(int x)
{
    return x==father[x] ? x : father[x] = find(father[x]);
}
bool Uion(int x,int y)
{
    int f1 = find(x);
    int f2 = find(y);
    if(f1 != f2) {
        father[f1] = f2;
        return true;
    }
    return false;
}
int karuskal(int flag);

int main()
{
#ifdef LOCKAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int T;scanf("%d",&T);
    while(T--)
    {
        min_edge_sum = 0;
        scanf("%d%d",&n,&v);
        if(n==1) {
            printf("0\n");
            continue;
        }
        for(int i = 0;i < v;i++)
        {
            int st,ed,cost; scanf("%d%d%d",&st,&ed,&cost);
            edges[i].st = st;
            edges[i].ed = ed;
            edges[i].cost = cost;
        }
        int MST = karuskal(1);
        bool flag = true;
        for(int i = 0;i < min_edge_sum ;i++)
        {
            int temp = edges[min_edge[i]].cost;
            edges[min_edge[i]].cost = INF;
            if(karuskal(0) == MST)
            {
                flag = false;
                break;
            }
            edges[min_edge[i]].cost = temp;
        }
        if(flag) printf("%d\n",MST);
        else printf("Not Unique!\n");

    }
    return 0;
}

int karuskal(int flag)
{
    int judge_edge = 0;//判断是否联通 不连通直接放弃
    if(flag==1) sort(edges,edges+v);
    for(int i = 1;i <= 100;i++) father[i] = i;
    int res = 0;
    for(int i = 0;i < v;i++)
    {
        edge e = edges[i];
        if(e.cost!= INF && Uion(e.st,e.ed) == true) 
        {
            judge_edge++;
            res += e.cost;
            if(flag == 1)  min_edge[min_edge_sum++] = i;
        }
    }
    if(judge_edge != n-1) return -1;
    return res;
}