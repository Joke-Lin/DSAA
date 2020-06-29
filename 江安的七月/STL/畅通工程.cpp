//:HCU1863

#include<iostream>
#include<cstdio>
#include<memory.h>

using namespace std;

const int maxn = 1000+10;

int n,m,ans;//城市数目，道路数目,ans:集合个数
int Set[maxn];

int find(int x)//找到x的根节点
{
	return (x == Set[x])? x:(Set[x] = find(Set[x]));
}

void join(int x,int y)//合并集合
{
	int fx = find(x);//找到根节点 注意：Set[x] != find(x)不一定等于的
	int fy = find(y);
	if(fx != fy) 
	{
		Set[fx] = fy;
		ans--;//如果合并说明集合数-1
	}
}

int main()
{
	while(true)
	{
		memset(Set,0,sizeof(Set));
		if(scanf("%d",&n) == 1 && !n) break;
		scanf("%d",&m);
		ans = n;//最初为n个集合
		for(int i = 1;i <= n;i++) Set[i] = i;
		for(int i = 0;i < m;i++)
		{
			int a,b; scanf("%d%d",&a,&b);
			join(a,b);
		}
		printf("%d\n",ans-1);//3条路需要2条来联通
	}
	
	return 0;
}

