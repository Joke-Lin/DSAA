#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define LOCAL

using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6;

struct EDGE
{
    int st,ed,cost;
    EDGE(int a=0,int b=0,int c=0):st(a),ed(b),cost(c){}
    bool operator < (const EDGE& b){ return cost < b.cost;}
}edges[2*maxn];

int map[1010][1010];
int father[maxn+10];

void init(int n){ for(int i = 0;i <= n+1;i++) father[i] = i;}
int find(int x){ return x==father[x] ? x : father[x] = find(father[x]);}

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++)
    {
        int n,m;scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++) scanf("%d",&map[i][j]);
        int v = 0;
        for(int i = 0;i < n;i++)//给每一个点编号 i*m+j
        {
            for(int j = 0;j < m;j++)
            {
                int it = i*m+j;
                int dre[2][2] = {{0,1},{1,0}};//右下
                for(int k = 0;k < 2;k++)
                {
                    int dx = i + dre[k][0];
                    int dy = j + dre[k][1];
                    if(0<=dx&&dx<n && 0<=dy&&dy<m)
                    {
                        edges[v++] = EDGE(i*m+j,dx*m+dy,abs(map[i][j]-map[dx][dy]));
                    }
                }
            }
        }
        init(n*m);
        sort(edges,edges+v);
        int res = 0;
        int edge = 0;
        for(int i = 0;i < v;i++)
        {
            EDGE e = edges[i];
            int fx = find(e.st);
            int fy = find(e.ed);
            if(fx != fy)
            {
                father[fx] = fy;
                res += e.cost;
                edge++;
            }
            if(edge >= n*m-1) break;
        }
        printf("Case #%d:\n",kase);
        printf("%d\n",res);
    }
    return 0;
}