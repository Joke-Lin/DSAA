//二分法搜索

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>

const int MAX = 1000000;
int Search(std::vector<int>& ,int);

int main()
{
	int Number;
	srand(unsigned(time(NULL)));
	std::vector<int> Temp;
	for(int i = 0;i < MAX;i++) Temp.push_back(rand());
	sort(Temp.begin(),Temp.end());
//	for(auto temp : Temp) std::cout << temp << '\n';
	while(std::cin >> Number)
	std::cout << Search(Temp,Number)<<"\n";
	return 0;
}

int Search(std::vector<int>& p,int number)
{
	int front = 0,end = p.size()-1;
	while(front <= end)
	{
		int mid = (front+end) / 2;
		if(p[mid] == number) return mid+1;
		if(p[mid] > number) end = mid-1;
		if(p[mid] < number) front = mid+1;
	}
	return false;
}
