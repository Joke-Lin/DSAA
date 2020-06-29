// 问题描述：输入N个数，与给定的K，输出有几种方法

#include<iostream>

int count = 0,sum = 0;

int N,k;
//bool Search(int , int);
void Search(int , int);
int Save[100] = {0};

int main()
{
	std::cin >> N;
	for(int i = 0;i < N;i++)	//数组从1开始
	{
		std::cin >> Save[i];
	}
	std::cin >> k;
	Search(0,0);
	//std::cout << Search(0,0)<< '\n';               //为了与函数匹配，开始为0，SAVE【0】 = 0
	return 0;
}
/*bool Search(int deep,int sum)
{
	if(deep == N) return sum == k;
	if(Search(deep+1,sum))
	{
		std::cout <<deep <<"    "<< sum << '\n';
		return true;
	}
	if(Search(deep+1,sum+Save[deep]))
	{
		std::cout <<deep <<"    "<< sum+Save[deep] << '\n';
		return true;
	}
	std::cout <<deep <<"    "<< sum << '\n';
	return false;
}*/
void Search(int deep,int sum)
{
	if(deep == N)
	{
		std::cout << deep << "	" <<sum<< '\n';
		return;
	}
	{
		Search(deep+1,sum);
		Search(deep+1,sum+Save[deep]);
	}
	//std::cout << deep << "	" <<sum<< '\n';
	return;
}
