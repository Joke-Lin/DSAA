//page282
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

const int maxn = 1e5+10;

vector<int> sons[maxn];//儿子集合
int n,T;

int dp(int boss);

int main()
{
   // freopen("./in.txt","r",stdin);
   // freopen("./out.txt","w",stdout);
    while(scanf("%d%d",&n,&T)==2,n+T)
    {
        for(int i = 0;i <= n;i++) sons[i].clear();
        for(int i = 1;i <= n;i++)
        {
            int boss; scanf("%d",&boss);
            sons[boss].push_back(i); 
        }
        printf("%d\n",dp(0));
    }
    return 0;
}

int dp(int boss)
{
    if(sons[boss].empty()) return 1; //单杆司令自己签 return 1
    int k = sons[boss].size();
    vector<int> d;
    for(int i = 0;i < k;i++) d.push_back(dp(sons[boss][i]));
    sort(d.begin(),d.end());
    int c = (k*T-1)/100+1;
    int ans = 0;
    for(int i = 0;i < c;i++) ans += d[i];
    return ans;
}