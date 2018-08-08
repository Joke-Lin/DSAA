#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define LOCAL

using namespace std;
typedef long long ll;

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int T; scanf("%d",&T);
    while(T--)
    {
        ll n; scanf("%lld",&n);
        if(n == 2) {
            printf("1\n");
            continue;
        }
        ll mid = n >> 1;
        if(n % 2 == 1) 
        {
            printf("%lld\n",mid*(mid+1));//奇数就相邻 肯定互质
        }
        else 
        {
            if(mid % 2 == 0){ printf("%lld\n",(mid-1)*(mid+1));}
            else {printf("%lld\n",(mid-2)*(mid+2));}
        }
    }
    return 0;
}