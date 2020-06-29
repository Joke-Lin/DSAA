//：page107

#include<iostream>
#include<cstdio>

using namespace std;

const int maxn = 1000000+10;

long long number[maxn];//存最大边是i的最多三角形个数

int main()
{
	int n;
	number[3] = 0;
	for(long long i = 4;i <= maxn;i++) number[i] = number[i-1] + ((i-1)*(i-2)/2-(i-1)/2)/2;//不可以是int可能有类型转换
	while(scanf("%d",&n))
	{
		if(n < 3) break;
		// for(int i = 4;i <= n;i++)
		// {
			// number[i] = number[i-1] + ((i-1)*(i-2)/2-(i-1)/2)/2;  //TLE超市
		// }
		printf("%lld\n",number[n]);
	}
	return 0;
}