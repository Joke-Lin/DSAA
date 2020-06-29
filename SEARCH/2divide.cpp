#include<iostream>
#include<vector>
#include<algorithm>

bool Cmp(int a,int b){return a > b;}
long Search(std::vector<int>&,long);

int main()
{
	long N = 100000000;
	//int N = 6;
	std::cin >> N;
	std::vector<int> Save;
	std::vector<int>& mid = Save;
	for(int i = 0;i < N;i++)
	{
		int mid;
		std::cin >> mid;
		Save.push_back(mid);
	}
	sort(Save.begin(),Save.end(),Cmp);
	for(auto i = Save.begin();i != Save.end();i++)
	{
		std::cout << *i <<"  ";
	}
	std::vector<int>::iterator it = Save.begin();
	//std::cout << *it << *(it+1);
	long number;
	//std::cin >> number;
	//std::cout << Search(mid,number);
	return 0;
}


long Search(std::vector<int>& v,long number)
{
	long Size = v.size();
	int mid = Size;
	














}
