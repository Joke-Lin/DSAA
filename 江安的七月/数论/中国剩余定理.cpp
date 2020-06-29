// https://www.cnblogs.com/freinds/p/6388992.html
// https://www.cnblogs.com/MashiroSky/p/5918158.html

#include<cstdio>
#include<cstring>
#include<cmath>

typedef long long ll;

using namespace std;
const int maxn = 10;
int n,a[maxn],m[maxn];

void gcd(ll a,ll b,ll&d,ll& x,ll&y)
{
    if(!b){ d = a;x = 1;y = 0;}
    else { gcd(b,a%b,d,y,x); y-= x*(a/b);}
}

ll China(int n,int *a,int *m)
{
    ll M = 1,d,y,x=0;
    for(int i = 0;i < n;i++) M *= m[i];
    for(int i = 0;i < n;i++)
    {
        ll w = M/m[i];
        gcd(m[i],w,d,d,y);
        x = (x+y*w*a[i]) % M;
    }
    return (x+M)%M;
}

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d%d",m+i,a+i);
    printf("%lld",China(n,a,m));
    return 0 ;
}