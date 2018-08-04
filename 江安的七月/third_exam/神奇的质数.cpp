// 数学是一个神奇的学科，数是一个神奇的概念，我们大家都知道这样一个概念“质数”，比如说2，3，5，7，….,inf都是质数，我们将这一串质数按照从小到大排序，定义其为一维的质数序列。哈哈哈，现在我们想求取二维的质数序列，二维的质数序列x1，x2，x3…xinf，其中每一个数不但自己是质数，其各数位上的数字之和也是一个质数，比如2，3，5，7，11，23，29…..
// 现在给定一个范围l，r请给出在[l,r]之间有多少个数是二维的质数

// Input
// 首先输入样例总数t(t<=15000)。
// 接下来有t组输入，每一组给出一个l和一个r(1<=l<=r<=10^6)，代表所需要求取的二维质数个数的序列范围

// Output
// 每组数据，只需要输出满足条件的二维质数的个数，具体输出见样例

// Sample Input
// 5
// 1 3
// 5 7
// 2 29
// 10 31
// 1 1000

// Sample Output
// Case #1: 2
// Case #2: 2
// Case #3: 7
// Case #4: 3
// Case #5: 89
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#define LOCKAL

using namespace std;
const int maxn = 1e6+10;
int prime[maxn];
int prime_2[maxn];
int get_sum(int x);//获取各位数字和

int main()
{
#ifdef LOCKAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    //预处理
    clock_t a = clock();
    int m = (int)sqrt(maxn-5+0.5);
    memset(prime,0,sizeof(prime));
    memset(prime_2,0,sizeof(prime_2));
    for(int i = 2;i <= m;i++) if(!prime[i])
        for(int j = i*i;j <= maxn-5;j += i) prime[j] = 1;//和数
    prime[1] = 1;
    prime_2[1] = 0;
    for(int i = 2;i <= maxn-5;i++) 
    {
        if(!prime[i] && !prime[get_sum(i)])
        {
            prime_2[i] = prime_2[i-1]+1;
        }
        else prime_2[i] = prime_2[i-1];
    }
    clock_t b = clock();
    cout << b-a << endl;
    int T; scanf("%d",&T);
    for(int kase = 1; kase<= T;kase++)
    {
        int ans = 0;
        int l,r; scanf("%d%d",&l,&r);
        printf("Case #%d: %d\n",kase,prime_2[r]-prime_2[l-1]);
    }
    return 0;
}

int get_sum(int x)
{
    int ans = 0;
    while(x)
    {
        ans += x%10;
        x /= 10;
    }
    return ans;
}