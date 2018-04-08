// 给定一个载重量为m，n个物品，其重量为wi，价值为vi，1<=i<=n，
//要求:把物品装入背包，并使包内物品价值最大
//data
// 10 5
// 2 6
// 2 3
// 6 5
// 5 4
// 4 6
#include<iostream>

using namespace std;

int Big_Val[100][100];

struct good
{
	int wei;
	int val;
}goods[100];

int Dpbag(int,int);

int main()
{
	int Weigt,N;
	cin >> Weigt >> N;
	for(int i = 0;i < N;i++) cin >> goods[i].wei >> goods[i].val;
	cout << Dpbag(Weigt,N);
	return 0;
}

int Dpbag(int Weigt,int N)
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
