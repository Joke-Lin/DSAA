#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
#include<string>
#define LOCAL
using namespace std;
struct TIME
{
    int st,ed;
    bool operator < (const TIME& b){ return ed < b.ed;}
}Time[10010];

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int T; scanf("%d",&T);
    while(T--)
    {
        int n;scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&Time[i].st,&Time[i].ed);
        }
        sort(Time,Time+n);
        int ans = 0,ed = 0;
        for(int i = 0;i < n;i++)
        {
            if(Time[i].st >= ed) ans++,ed = Time[i].ed;
        }
        printf("%d\n",ans);
    }
    return 0;
}