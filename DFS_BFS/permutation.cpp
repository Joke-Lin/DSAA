//特殊状态的枚举，C语言和C++的不同实现全排列
//生成{0，1，2...n-1}的n！种排列
//原理就是判断这个数字之前有没有用到过；

#include<iostream>
#include<algorithm>

using namespace std;

bool used[100];
int number[100];
int POS,N;

void permutation1(int pos,int n) //language C 从pos位置到n-1开始全排列
{
	if(pos == n)
	{
		for(int i = POS;i < n;i++) cout << number[i] <<" ";
		cout<<endl;
		return;
	}
	for(int i = POS;i < n;i++)
	{
		if(used[i] == false)
		{
			number[pos] = i;
			used[i] = true;
			permutation1(pos+1,n);
			used[i] = false;    //标志复位
		}
	}
}

void permutation2(int pos,int n)
{
	for(int i = pos;i < n;i++) number[i] = i;
	do {
		for(int i = pos;i < n;i++) cout << number[i] <<" ";
		cout<<endl;
	} while(next_permutation(number+pos,number+n));
}

int main()
{
	number[0] = 1,number[1] = 2,number[2] = 3;
	permutation1(0,3);
	return 0;
}
