#include<iostream>
#include<string>
#include<cstdio> 
#include<sstream>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 1e5+10;

int dp[maxn];//以i结尾的最优解
int number[maxn];

int main()
{
	int T;scanf("%d",&T);
	getchar();
	for(int kase = 1;kase <= T;kase++)
	{
		bool flag = false;
		memset(dp,0,sizeof(dp));
		int n;scanf("%d",&n);
		int ed = 0,st = 0;
		for(int i = 0;i < n;i++) 
		{
			scanf("%d",number+i);
			if(number[i] > 0) {
				flag = true;
			}
		}
		dp[0] = number[0];
		for(int i = 1;i < n;i++)
		{
			dp[i] = max(number[i],dp[i-1]+number[i]);
			ed = dp[i] > dp[ed] ? i : ed;
		}
		for(int i = ed-1;i >= 0;i--)
		{
			if(dp[i] < 0)
			{
				st = i+1;
				break;
			}
		}
		printf("Case %d:\n",kase);
		printf("%d %d %d\n",dp[ed],st+1,ed+1);
		if(kase != T) printf("\n");
	}
	return 0;
}
