//page140

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int maxn = 1000+10;
double f[maxn];//1只麻球在maxn天死的概率
double p[maxn];//存生i只麻球的概率

int main()
{
	
	int T; scanf("%d",&T);
	for(int Case = 1;Case <= T;Case++)
	{
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(p));
		int n,k,m; scanf("%d%d%d",&n,&k,&m);//n个概率，k只麻球，m天后
		for(int i = 0;i < n;i++) scanf("%lf",&p[i]);
		//先计算一直麻球死的概率，然后f^m即可
		f[0] = 0; f[1] = p[0];//初始化值
		for(int i = 2;i <= m;i++)
		{
			double temp = 0;
			for(int j = 0;j < n;j++)
			{
				temp += p[j]*pow(f[i-1],j);
			}
			f[i]+=temp;
		}
		printf("Case #%d: %.7lf\n",Case,pow(f[m],k));
	}
	
	return 0;
}