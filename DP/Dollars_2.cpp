//SCUACM 1009
//Algorithm DP

#include<iostream>
#include<cstdio>

int All_Money[5500] = {0};
int Money[] = {5,10,20,50,100,200,500,1000,2000,5000};

int main()
{
	int Number = sizeof(Money)/sizeof(int);
	All_Money[0] = 1;
	for(int i = 0;i < Number;i++)
	{
		int n = Money[i];
		for(int j = n;j < 5300;j++)
		{
			All_Money[j] += All_Money[j-n];
		}
	}
	float a_float;
	while(std::cin >> a_float)
	{
		int a_int = int(a_float * 100);
		//std::cout << All_Money[a_int] << '\n';
		printf("%5.2lf%12ld\n",a_float,All_Money[a_int]);
	}
	return 0;
}
