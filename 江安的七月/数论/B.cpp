// 要求(A/B)%9973，但由于A很大，我们只给出n(n=A%9973)(我们给定的A必能被B整除，且gcd(B,9973) = 1)。
// Input
// 数据的第一行是一个T，表示有T组数据。 
// 每组数据有两个数n(0 <= n < 9973)和B(1 <= B <= 10^9)。
// Output
// 对应每组数据输出(A/B)%9973。
// Sample Input
// 2
// 1000 53
// 87 123456789
// Sample Output
// 7922
// 6060
// 直接暴力搜没有那么复杂
// (A/B)%9973=k
// A/B = k+t*9973
// A = Bk+tk*9973
// A/9973 = Bk%9973
// n=Bk%9973
// 枚举K

#include<iostream>
#include<cstdio>
#include<cmath>
#include<stdlib.h>

using namespace std;

int main()
{
    long long n,B,T;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&B);
        long long x;
        for(x = 0;x <= 1e9;x++)
        {
            long long temp = B*x;
            if(n == temp%9973)
            {
                printf("%lld\n",x);
                break;
            }
        }
    }
    system("pause");
    return 0;
}