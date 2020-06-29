#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define LOCAL

using namespace std;
int a,b,c,d,e;
double get(double x)
{
    return a*exp(-x)-b*x+c*log(x)-d*sin(5*x)+e*sqrt(x);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        double minn = 0x3f3f3f3f3f3f3f3f,maxn = -0x3f3f3f3f3f3f3f3f;
        int ans = 0;
        for(double i = 1.00;i <= 100.00;i += 0.001)
        {
            ans++;
            minn = min(minn,get(i));
            maxn = max(maxn,get(i));
        }
        printf("%.2f %.2f\n",minn,maxn);
    }
    scanf("%d",&a);
    return 0;
}