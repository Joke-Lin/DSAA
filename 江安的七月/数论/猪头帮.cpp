// 新年快到了，“猪头帮协会”准备搞一个聚会，已经知道现有会员N人，把会员从1到N编号，其中会长的号码是N号，凡是和会长是老朋友的，那么该会员的号码肯定和N有大于1的公约数，否则都是新朋友，现在会长想知道究竟有几个新朋友？请你编程序帮会长计算出来。
// Input
// 第一行是测试数据的组数CN（Case number，1<CN<10000），接着有CN行正整数N（1<n<32768），表示会员人数。
// Output
// 对于每一个N，输出一行新朋友的人数，这样共有CN行输出。 
// Sample Input
// 2
// 25608
// 24027
// Sample Output
// 7680
// 16016
//欧拉函数
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
const int maxn = 32768+10;

int phi[maxn];

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
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    phi_table(maxn);
    int T;scanf("%d",&T);
    while(T--)
    {
        int n;scanf("%d",&n);
        printf("%d\n",phi[n]);
    }

    return 0;
}