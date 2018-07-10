//:page193

#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<cstring>

using namespace std;

const int maxn = 20000+10;
int dis[maxn],father[maxn];

int find(int);

int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        int n = 100; char cmd;
        memset(dis,0,sizeof(dis));//开始距离都为0
        memset(father,0,sizeof(father));
        for(int i = 0;i<=maxn;i++) father[i] = i;
        scanf("%d",&n); getchar();
        while(scanf("%c",&cmd))
        {
            if(cmd == 'O') break;
            switch(cmd)
            {
                case 'I':
                    int u,v; scanf("%d%d",&u,&v);
                    father[u] = v;
                    dis[u] = abs(u-v)%1000;
                    break;
                case 'E':
                    int a; scanf("%d",&a);
                    find(a);
                    printf("%d\n",dis[a]);
                    break;
            }
        }
    }
    //system("pause");
    return 0;
}

int find(int x){
    if(x != father[x])
    {
        int fx = find(father[x]);
        dis[x] += dis[father[x]];
        return father[x] = fx;
    }
    else return x;
}