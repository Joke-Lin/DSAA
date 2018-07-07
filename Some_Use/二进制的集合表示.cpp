//:文章见https://blog.csdn.net/liyanfeng1996/article/details/52782220
// 一些不大的数的集合，可以用二进制的形式来表示，注意这里的集合没有重复元素。
// 集合的存储:

// 方法是用一串二进制的数存，第i位表示i这个数是否在集合中。设集合中最大的数不超过（1<<n），
// 令s=1<<n，假如i在集合中，让s=s|（1<<i），就将i存在了s中。

// 集合的运算:

// 因为是二进制表示，A|B、A&B、A^B、分别对应集合的并，交和对称差。
#include<iostream>
#include<cstdio>

using namespace std;

const int N = 21;//存储0->20的数
int S = 1<<N;

void print_element(int n,int s)//从1到n枚举在集合S中就输出
{
	for(int i = 0;i < n;i++)
	{
		if(s&(1<<i)) printf("%d ",i);
	}
}

void add_element(int i,int &s)
{
	if(i >= N) 
	{
		printf("too big number\n");
		return;
	}
	s |= (1<<i);
}

void delete_element(int i,int &s)//从s中删除i
{
	if(!(s&(1<<i)))
	{
		printf("not find\n");
		return;
	}
	s &= (~(1 << i));
}

void print_ziji(int s)//输出s的子集
{
	if(s == 1<<N) printf("it is empty\n");
	else
	{
		for(int s0 = s;s0;s0 = (s0-1)&s)//注意还要和s相与
		{
			print_element(N,s0);
			printf("\n");
		}
	}
}

int main()
{
	int x;
	for(int i = 0;i < 3;i++)
	{
		scanf("%d",&x);
		add_element(x,S);
	}
	print_element(N,S);
	printf("\n");
	for(int i = 0;i < 2;i++)
	{
		scanf("%d",&x);
		delete_element(x,S);
	}
	print_element(N,S);	
	return 0;
}