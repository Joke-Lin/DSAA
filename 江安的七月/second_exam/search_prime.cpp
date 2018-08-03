//POJ2773
//给出m,k找出第K个和m互素的数
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
const int maxn = 1e6+10;

int prime[maxn];//比m小的素数

int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b);
}

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    int m,k;
    while(~scanf("%d%d",&m,&k))
    {
        int index = 0;
        for(int i = 1;i <= m;i++)//必须<=否则RE 注意1的情况 : )
        {
            if(gcd(i,m) == 1) prime[index++] = i;//记录
        }
        //if a和b是互质那么 a+bn也与b互质 上面的就是b = 0时的情况 结果具有周期性
       printf("%d\n",(k-1)/index*m + prime[(k-1)%index]);
    }
    return 0;
}