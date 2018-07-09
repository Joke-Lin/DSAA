//：page107
//把题目改为
//总的方案数-AUBUCUD
//ABCD:代表有一行或一列（指定）不放石头的情况
#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<cstring>

using namespace std;

const int MOD =1000007;
const int maxn = 500;
int C[maxn+10][maxn+10];//存储组合数，计算需要

int main()
{
	//预处理，计算C
	memset(C,0,sizeof(C));
	for(int i = 0;i <= maxn;i++)
	{
		C[i][0] = C[i][i] = 1;//边界处理
		for(int j = 1;j < i;j++) C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;//C[i][j] = (C[i][j-1]*(i-j+1)/j)%MOD;可能会溢出
	}
	int T; scanf("%d",&T);
	for(int Case = 1;Case <= T;Case++)
	{
		int sum = 0;
		int n,m,k; scanf("%d%d%d",&n,&m,&k);
		for(int i = 0;i < 16;i++) //二进制表示，总共有16种组合，二进制的1表示有
		{
			int r = n,c = m;
			int b = 0; //记录组合数，偶家加奇减
			if(i&1) {r--; b++;} // A
			if(i&2) {r--; b++;} // B
			if(i&4) {c--; b++;} // C
			if(i&8) {c--; b++;} // D
			if(b&1) sum = (sum+MOD-C[r*c][k])%MOD;//避免出现负数所以加MOD
			else sum = (sum+C[r*c][k])%MOD;
		}
		printf("Case %d: %d\n",Case,sum);
	}
	return 0;
}

