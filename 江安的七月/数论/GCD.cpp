// 给定整数N，求1<=x,y<=N且Gcd(x,y)为素数的
// 数对(x,y)有多少对.
// Input
// 一个整数N
// Output
// 如题
// Sample Input
// 4
// Sample Output
// 4
// Hint
// 对于样例(2,2),(2,4),(3,3),(4,2)
// 1<=N<=10^7


//我们可以枚举一个质数p，这样就可以求gcd(x/p,y/p)=1的数量，那么筛一个欧拉函数表的前缀和即可 
// 注意到题目中(2,1)与(1,2)不同，要算两次，而gcd(1,1)只用算1次
#include<iostream>
#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn = 1e7+10;

int n,tot;//tot为素数总数
int vis[maxn],prime[maxn];
int phi[maxn];
ll ans,sum[maxn];

int sieve(int n)
{
    int m = (int)sqrt(n+0.5);
    memset(vis,0,sizeof(vis));
    for(int i = 2;i <= m;i++) if(!vis[i])
        for(int j = i*i;j <= n;j += i) vis[j] = 1;
    tot = 0,vis[1]=1;
    for(int i = 1;i <= n;i++)
    {
        if(!vis[i]) prime[tot++] = i;
    }
}

void phi_table(int n)
{
    for(int i = 2;i <= n;i++) phi[i] = 0;
    phi[1] = 1;
    for(int i = 2;i <= n;i++)//枚举素数
    {
        if(!phi[i])//如果没有被初始化过->源素数2*3*7*2 = 82试试
        {
            for(int j = i;j <= n;j += i)
            {
                if(!phi[j]) phi[j] = j;//初始化
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    sieve(n);phi_table(n);
    sum[0] = 0; ans = 0;
    for(int i = 1;i <= n;i++) sum[i] += sum[i-1]+phi[i];
    for(int i = 0;i < tot;i++) ans += sum[n/prime[i]]*2-1;
    printf("%lld",ans);
    system("pause");
    return 0;
}