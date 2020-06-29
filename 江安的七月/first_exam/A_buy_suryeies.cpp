// 当寒假来临时，很多人都会去旅行。一般来说，有很多纪念品出售，有时候旅行者会很高兴地买一些。
// 他们不仅可以把纪念品送给朋友和家人作为礼物，还可以回味这些纪念品。总而言之，纪念品的价格并不十分昂贵
// ，也令人喜爱和有趣。但是人们的预算是有限的，他们不能买太多。他们在欣赏了所有的纪念品之后，决定购买某些纪念品，
// 购买时不能购买超过 1 件的同品种纪念品 (即对于同一个品种，要么购买 1 件，要么不购买)。

// 例如：

// 产品 A，价格 1 元
// 产品 B，价格 2 元
// 产品 C，价格 3 元
// 产品 D，价格 4 元
// 如果你只有 7 元钱，则最多可以选择 3 种纪念品的组合，这 3 种纪念品的组合有 ABC (6), ABD (7) 共 2 种方案。
// 如果你有 8 元钱的话，选择最多种类的纪念品有 ABC (6), ABD (7), ACD (8) 共 3 种方案。
// 如果你有 10 元人民币，选择品种最多的纪念品只有 ABCD (10) 这 1 种方案。

// 输入
// 输入首先包含一个整数 T，表示测试数据的组数。

// 对于每组测试数据，在第一行中有两个整数 n, m，其中 n 是纪念品的数量，m 是拥有的预算资金。第二行包含 n 个整数，
//每个整数描述一种纪念品的价格。

// 所有的输入数据和输出结果都在 32 位整数的范围内，0 ≤ m ≤ 500, 0 <n ≤ 30, t ≤ 500，
//价格都是正整数。两组测试数据之间有一个空行。

// 输出
// 如果你可以买一些纪念品，则打印如下格式的结果：“You have S selection(s) to buy with K kind(s) of souvenirs.” (不含引号)，
//其中 K 代表你可以买到的品种最多的纪念品， S 表示可以 K 种纪念品对应的的组合数量。

// 如果你带的钱不够 (无法购买任何纪念品)，则打印结果“Sorry, you can't buy anything.” (不含引号)。
// 示例输入
// 2
// 4 7
// 1 2 3 4

// 4 0
// 1 2 3 4

// 示例输出
// You have 2 selection(s) to buy with 3 kind(s) of souvenirs.
// Sorry, you can't buy anything.

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

using namespace std;

int main()
{
	int n; scanf("%d",&n);
	while(n--)
	{
		int  numbers,Weight;
		scanf("%d%d",&numbers,&Weight);
		int sum = 0;
		int goods[510];
		int best[510][510];//g[i][j]表示在有i元的情况下，选j个种类的时候的方案数，且g[i][j] = g[i-weight][j-1]+self
		memset(best,0,sizeof(best));
		for(int i = 0;i < numbers;i++)	scanf("%d",&goods[i]);//输入数据
		for(int i = 0;i <= Weight;i++)	best[i][0] = 1;//为第72行做准备k=1时必有一个，i需要从0开始j-weight可能为0
		//sort(goods,goods+numbers);
		for(int i = 1;i <= numbers;i++)//对每一个种类遍历
		{
			int weight = goods[i-1];
			for(int j = Weight;j >= weight;j--)
			{
				for(int k = i;k >= 1;k--)
				{
					best[j][k] = best[j-weight][k-1]+best[j][k];
				}
			}
		}
		int flag = 0,i;
		for(i = numbers;i >= 1;i--)
		{
			if(best[Weight][i] > 0) 
			{
				flag = 1;
				break;
			}
		}
		if(flag) printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",best[Weight][i],i);
		else printf("Sorry, you can't buy anything.\n");
	}
	
	return 0;
}