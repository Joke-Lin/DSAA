// 给定一个载重量为m，n个物品，其重量为wi，价值为vi，1<=i<=n，
//要求:把物品装入背包，并使包内物品价值最大
// data
// 10 5
// 2 6
// 2 3
// 6 5
// 5 4
// 4 6
#include<iostream>
//#include<algorithm>

using namespace std;

int Big_Val[100][100];
int Big_Val_one[100];

struct good
{
	int wei;
	int val;
}goods[100];

int Dpbag_1(int,int);
int Dpbag_2(int,int);
int Dpbag_one_index1(int,int);
int Dpbag_one_index2(int,int);

int main()
{
	int Weigt,N;
	cin >> Weigt >> N;
	for(int i = 0;i < N;i++) cin >> goods[i].wei >> goods[i].val;
	std::cout << Dpbag_1(Weigt,N) << '\n';
	cout << Dpbag_one_index2(Weigt,N);
	return 0;
}

int Dpbag_1(int Weigt,int N)
{
	for(int i = 0;i < N;i++)
	{
		for(int j = 1;j <= Weigt;j++)
		{
			Big_Val[i][j] = Big_Val[i-1][j];
			if(goods[j].wei <= j)
			{
				if(Big_Val[i-1][j-goods[i].wei]+goods[i].val > Big_Val[i-1][j])
				{
					Big_Val[i][j] = Big_Val[i-1][j-goods[i].wei]+goods[i].val;
				}
			}
		}
	}
	return Big_Val[N-1][Weigt];
}

int Dpbag_2(int Weigt,int N)
{
	for(int j = 1;j <= Weigt;j++)
	{
		for(int i = 0;i < N;i++)
		{
			Big_Val[i][j] = Big_Val[i-1][j];
			if(goods[j].wei <= j)
			{
				if(Big_Val[i-1][j-goods[i].wei]+goods[i].val > Big_Val[i-1][j])
				{
					Big_Val[i][j] = Big_Val[i-1][j-goods[i].wei]+goods[i].val;
				}
			}
		}
	}
	return Big_Val[N-1][Weigt];
}

int Dpbag_one_index1(int Weight,int N)
{
	for(int i = 0;i < N;i++)
	{
		for(int j = Weight;j >=goods[i].wei;j--)
		{
			Big_Val_one[j] = max(Big_Val_one[j],Big_Val_one[j-goods[i].wei]+goods[i].val);
		}
	}
	return Big_Val_one[Weight];
}

int Dpbag_one_index2(int Weight,int N) //error
{
	for(int i = 1;i <= Weight;i++)
	{
		for(int j = N-1;j>=0;j--)
		{
			if(goods[j].wei <= i)
			{
				Big_Val_one[i] = max(Big_Val_one[i],Big_Val_one[i-goods[j].wei]+goods[j].val);
			}
		}
	}
	return Big_Val_one[Weight];
}
