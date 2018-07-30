//UVA 10537
//https://blog.csdn.net/ancientone/article/details/80928917

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

const ll INF = 1LL<<60;
char s1[2],s2[2];//存字母 用str避免回车这类的读错
vector<int> map[210];
ll dis[210];
bool used[210];
int path[210];//路径前缀
ll sum;//最后的货物

ll calc(char x)//计算经过这个点要之前至少要准备多少货物
{
    if(islower(x)) return dis[x]+1;
    else return ceil(dis[x]*20.0/19);
}

void dijkstra(int st,int ed)
{
    for(int i = 0;i < 210;i++) dis[i]=INF,used[i]=0,path[i]=-1;
    dis[st] = sum;
    used[st] = 1;
    for(int i = 0;i < map[st].size();i++)
    {
        dis[map[st][i]]=calc(st);
        path[map[st][i]]=st;
    }
    for(int i = 0;i < 200;i++)
    {
        ll Min = INF;
        int t = -1;
        for(int j = 1;j <= 200;j++)
        {
            if(!used[j]&&dis[j]<Min){
                Min = dis[j];
                t = j;
            }
        }
        if(t!=-1)
        {
            used[t] = 1;
            ll cost = calc(t);
            for(int j = 0;j < map[t].size();j++)
            {
                if(!used[map[t][j]]&&dis[map[t][j]]>cost)
                {
                    path[map[t][j]] = t;
                    dis[map[t][j]] = cost;
                }
            }
        }
    }
}

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int Kase = 0;
    int n;
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        for(int i = 'A';i<='Z';i++) map[i].clear();
        for(int i = 'a';i <= 'z';i++) map[i].clear();
        for(int i = 0;i < n;i++)
        {
            scanf("%s %s",s1,s2);
            map[s1[0]].push_back(s2[0]);
            map[s2[0]].push_back(s1[0]);
        }
        scanf("%d %s %s",&sum,s1,s2);
        dijkstra(s2[0],s1[0]);
        printf("Case %d:\n",++Kase);
        printf("%lld\n",dis[s1[0]]);
        printf("%c",s1[0]);
        int u = s1[0];
        while(path[u] != -1)
        {
            u = path[u];
            printf("-%c",u);
        }
        printf("\n");
    }
    return 0;
}