//:算法竞赛入门经典p65
//输入nkm输出最后一个被删的数
//第一次删除m每数k个数就删一次，总数是n
#include<iostream>
#include<cstdio>

//using namespace std;

const int MAX = 10010;
int f[MAX];//先假设最初删除的编号是0，所以f数组存的是相对于此编号的位置

int main()
{
	int n,k,m; 
	while(scanf("%d%d%d",&n,&k,&m)==3)
	{
		if(n==k && k==m && m==n && n==0) break;
		f[1] = 0;//第一个被删的是自己,编号0
		for(int i = 2;i < n;i++) f[i] = (f[i-1]+k)%i;//注意i不是模n
		//上述代码旨在找出原编号下最后删除的那个的相对位置
		//采用递推求解，从后往前的递推
		//对n来说删除了一个之后总体n减少1
		//f[n] 与 f[n-1] 满足一下关系是
		//(f[n-1]+k)%n == f[n]
		//所以从这里可以反推，从0->n
		//得到相对位置之后，因为从m开始删所以加上便宜位置
		//得到：result = ()%n+1;
		printf("%d\n",(f[n-1]+m)%n+1);
	}
	return 0;
}

