//HDU4970
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LOCKAL

typedef long long ll;

using namespace std;
const int maxn = 110000+10;

ll change[maxn]; //注意存的是数据改变量change[i]意味着后面和前面的相差了change[i]
//change_sum[i - n]就是每次的改变量
ll sum[maxn];


int main()
{
#ifdef LOCKAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int n;
    while(scanf("%d",&n),n)
    {
        memset(change,0,sizeof(change));
        memset(sum,0,sizeof(sum));
        int m; scanf("%d",&m);
        for(int i = 0;i < m;i++)
        {
            int l,r,cost;
            scanf("%d%d%d",&l,&r,&cost);
            change[r] += cost; //表示此后的都要加上这个数
            change[l-1] -= cost;//还原
        }
        ll get = 0;
        for(int i = n;i >= 1;i--)
        {
            get += change[i];
            sum[i] = sum[i+1] + get;
        }
        int ans = 0;
        int x; scanf("%d",&x);
        while(x--)
        {
            ll hp,st; scanf("%lld%lld",&hp,&st);
            if(hp > sum[st]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}