//:page 66
//特殊的LCS（用LIS求解）因为每个序列的元素是唯一的
#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>

using namespace std;

const int MAXN = 250*250;
const int INF = 1<<30;

int Transform[MAXN];//转换标准数组
int LIS[MAXN];//LIS 的数组
int d[MAXN];//LIS DP数组长度为k的上升子序列的最小末尾元素

int main()
{
	int T; scanf("%d",&T);
	for(int number = 1;number <= T;number++)
	{
		int n,p,q,temp;
		scanf("%d%d%d",&n,&p,&q);//n相当于无用
		memset(Transform,0,sizeof(Transform));
		memset(d,0,sizeof(d));
		for(int i = 1;i <= p+1;i++)
		{
			scanf("%d",&temp);
			Transform[temp] = i;//标准化，i->temp
		}
		int len = 0;
		for(int i = 1;i <= q+1;i++)
		{
			scanf("%d",&temp);
			if(Transform[temp]) //如果在第一个序列出现过的化
			{
				LIS[len++] = Transform[temp];
			}
		}
		
		//LIS 求解过程
		int length = 1;
		d[length] = LIS[0];
		for(int i = 1;i < len;i++)
		{
			if(LIS[i] > d[length]) d[++length] = LIS[i];
			else
			{
				int j = lower_bound(d+1,d+length+1,LIS[i])-d;
				d[j] = LIS[i];
			}
		}
		printf("Case %d: %d\n",number,length);
	}
	
	return 0;
}