//https://www.2cto.com/kf/201404/296684.html
//此章节皆为书本原题 TLE
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
    P(int a = 0,int b = 0,int c = 0):st(a),ed(b),cost(c){}
};

int dis_st[maxn];//开始点
int dis_ed[maxn];//结束点

struct cmp_st{
    bool operator ()(int a,int b)
    {
        return dis_st[a] > dis_st[b];
    }
};

struct cmp_ed{
    bool operator ()(int a,int b)
    {
        return dis_ed[a] > dis_ed[b];
    }
};

int cost_1[maxn][maxn];//经济路线的花费
priority_queue<int,vector<int>,cmp_st> que_st;
priority_queue<int,vector<int>,cmp_ed> que_ed;
int path_st[maxn];//记录从开始位置到其他点的最短路径的前缀节点
int path_ed[maxn];//从结束点开始
P cost_2[maxn];//商业线的花费  
int used[maxn];//判断点是否用过
int N,S,E,M,K;
int ans;//时间花费
int point;//商业节点
int INDEX;//存下标 P_cost_2
int judgeIdReverse;

vector<int> path;

void dijkstra(int st,int *dis,int *path,int flag);//从 st 开始到其他各个经济线的点 结果存于dis数组
void SearchCommerPoint();
void get_path();//获取路径

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    int k = 0;
    while(scanf("%d%d%d",&N,&S,&E) != EOF)
    {
        if(k!=0) printf("\n"); k++;
        point = 0;
        ans = INF;
        path.clear();
        while(!que_ed.empty()) que_ed.pop();
        while(!que_st.empty()) que_st.pop();
        int st,ed,cost; 
        scanf("%d",&M);
        fill(cost_1[0],cost_1[0]+maxn*maxn,INF);  //预处理成最大
        fill(dis_st,dis_st+maxn,INF);
        fill(dis_ed,dis_ed+maxn,INF);
        for(int i = 0;i < M;i++)
        {
            scanf("%d%d%d",&st,&ed,&cost);
            cost_1[st][ed] = cost_1[ed][st] = cost;
        }
        scanf("%d",&K);
        for(int i = 0;i < K;i++)
        {
            scanf("%d%d%d",&st,&ed,&cost);
            cost_2[i] = P(st,ed,cost);
        }
        dijkstra(S,dis_st,path_st,1); dijkstra(E,dis_ed,path_ed,2);
        //for(int i = 1;i <= N;i++) printf("%d %d\n",dis_st[i],dis_ed[i]);
        SearchCommerPoint();
        get_path();
        if(point) printf("%d\n",point);
        else printf("Ticket Not Used\n");
        printf("%d\n",ans);
    }
    return 0;
}

void dijkstra(int s,int* dis,int *path,int flag)
{
    memset(used,0,sizeof(used));
    memset(path,0,sizeof(path));
    dis[s] = 0;
    if(flag == 1)
    {
        que_st.push(s);//t这个点放入堆
        while(!que_st.empty())
        {
            int point_min = que_st.top(); que_st.pop();
            for(int i = 1;i <= N;i++)
            {
                if(cost_1[point_min][i]<INF && dis[point_min] + cost_1[point_min][i] < dis[i])
                {
                    dis[i] = dis[point_min] + cost_1[point_min][i];
                    que_st.push(i);
                    path[i] = point_min;
                }
            }
        }
    }
    else{
        que_ed.push(s);//t这个点放入堆
        while(!que_ed.empty())
        {
            int point_min = que_ed.top(); que_ed.pop();
            for(int i = 1;i <= N;i++)
            {
                if(cost_1[point_min][i]<INF && dis[point_min] + cost_1[point_min][i] < dis[i])
                {
                    dis[i] = dis[point_min] + cost_1[point_min][i];
                    que_ed.push(i);
                    path[i] = point_min;
                }
            }
        }
    }
}

void SearchCommerPoint()
{
    ans = dis_st[E];
    for(int i = 0;i < K;i++)
    {
        int a = cost_2[i].st;
        int b = cost_2[i].ed;
        int cost = cost_2[i].cost;
        int commer_dis = dis_st[a]+dis_ed[b] + cost;
        if(commer_dis < ans)
        {
            ans = commer_dis;
            point = a;
            INDEX = i;
            judgeIdReverse = 0;
        }
        swap(a,b);
        commer_dis = dis_st[a]+dis_ed[b] + cost;
        if(commer_dis < ans)
        {
            ans = commer_dis;
            point = a;
            INDEX = i;
            judgeIdReverse = 1;
        }
    }
}

void get_path()
{
    int st = S,ed = E,a = cost_2[INDEX].st,b = cost_2[INDEX].ed;
    if(judgeIdReverse == 1) swap(a,b);
    if(point == 0)
    {
        for(;ed != 0;ed = path_st[ed]) path.push_back(ed);
        reverse(path.begin(),path.end());
    }
    else{
        for(;a != 0;a = path_st[a]) path.push_back(a);
        reverse(path.begin(),path.end());
        for(;b != 0;b = path_ed[b]) path.push_back(b);
    }
    for(vector<int>::iterator it = path.begin();it != path.end();it++) printf("%d ",*it);
    printf("\n");
}