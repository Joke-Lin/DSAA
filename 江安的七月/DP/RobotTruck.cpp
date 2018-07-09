//:page 73 https://www.xuebuyuan.com/2067592.html
// n个垃圾 机器人从（0，0）开始要按照次序捡垃圾 再回到原点 可以带回多个并且重量之和不能大于C
// 思路和代码全部参考书上的 求走过最小的距离
// 两点的距离为abs(x1-x2)+abs(y1-y2)
// dp(i)为捡完第i个垃圾 并且回到原点的最小距离
// dis(i)从原点到第i个垃圾的记录
// dist(i)为从第1个 经过第2个 第三个到第i个垃圾的距离 那么从第j个到第i个垃圾的距离为 dist(i)-dis(j);
// w(i,j)表示第i个到第j个垃圾重量之和
// dp(i) = dp(j) +dis(j+1)+dist(i)-dist(j+1)+dis(i) = dp(j)-dist(j+1)+dis(j+1)+dis(i)+dist(i)  并且w(j+1,i) <= C
// 这样 把有关于i的都提出
// 只需考虑j 求出最小的 dp(j)-dist(j+1)+dis(j+1) 如果枚举j 会超时
// 现在求的是一个j < i满足 dp(j)-dist(j+1)+dis(j+1) 尽量小 并且w(j+1,c) <= C
// 可以用一个单调队列维护最小值
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>		//将使用deque容器来解题，相当于一个可以在前面插入和删除的vector
#include <algorithm>

using namespace std;

const int maxn = 100005;
int C,n;//最大携带质量和行为（垃圾数）
int x[maxn],y[maxn],w[maxn];//坐标和质量
int dp[maxn],w_sum[maxn],dis[maxn],dist[maxn];//C为robot一次最大携带量，w_sum前i个总重量，其他意义如上

int func(int j)//书上的阴影部分 ---滑动窗口
{
	return dp[j]-dist[j+1]+dis[j+1];
}

int solve()
{
	deque<int> Q;//初始化两端队列,Q里面存的都是使func尽量小的值j为后面判断j->i最优做准备
	Q.push_front(0);//原点压入队列
	for(int i = 1;i <= n;i++)//遍历点
	{
		while(!Q.empty() && w_sum[i]-w_sum[Q.front()] > C) Q.pop_front();//只要Q非空并且w_sum[j->i]过大（一次带不走）删除
		dp[i] = func(Q.front())+dis[i]+dist[i];
		while(!Q.empty() && func(i)<=func(Q.back())) Q.pop_back();//i压入队列时将队列后面那些非最优（func大）弹出
		Q.push_back(i);//将i压入队列
	}
	return dp[n];
}

int main(void)
{
	int T; scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp)); //清空上一次的数据
		memset(w_sum,0,sizeof(w_sum));
		memset(dis,0,sizeof(dis));
		memset(dist,0,sizeof(dist));
		
		scanf("%d%d",&C,&n);
		for(int i = 1;i <= n;i++) //这里从一开始比较方便
		{
			scanf("%d%d%d",&x[i],&y[i],&w[i]);
			w_sum[i] = w_sum[i-1]+w[i];
			dis[i] = abs(x[i])+abs(y[i]);
			dist[i] = dist[i-1] + abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]);
		}
		printf("%d\n",solve());
		if(T) printf("\n");
	}
	return 0;
}
