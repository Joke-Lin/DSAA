// Problem Description
// 在一个国家仅有1分，2分，3分硬币，将钱N兑换成硬币有很多种兑法。请你编程序计算出共有多少种兑法。
//
//
// Input
// 每行只有一个正整数N，N小于32768。
//
//
// Output
// 对应每个输入，输出兑换方法数。
//
//
// Sample Input
// 2934 12553
//
//
// Sample Output
// 718831 13137761

#include<iostream>

int All_Money[40000] = {0};
int Money[] = {1, 2 , 3};

int main()
{
	int Number = sizeof(Money)/sizeof(int);
	All_Money[0] = 1;
	for(int i = 0;i < Number;i++)
	{
		int n = Money[i];
		for(int j = n;j < 40000;j++)
		{
			All_Money[j] += All_Money[j-n];
		}
	}
	int Search;
	std::cin >> Search;
	std::cout << All_Money[Search] << '\n';
	return 0;
}
