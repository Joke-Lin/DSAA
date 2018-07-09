#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>

typedef unsigned long long ull;

void swap(ull& a,ull& b)
{
	ull c;
	c = a;
	a = b;
	b = c;
}

int main()
{
	ull n,m;
	while(scanf("%lld%lld",&n,&m))
	{
		if(!n && !m) break;
		if(n>m) swap(n,m);//保证n是较小的那个
		ull A,B,C;//A是横的放置，B是竖着放置
		A = n*m*(m-1);
		B = m*n*(n-1);
		C = 2*n*(n-1)*(3*m-n-1)/3;//公式推导，左右对称考虑斜向一边的*2，试验得出结果
		printf("%lld\n",A+B+C);
	}
	
	
	return 0;
}