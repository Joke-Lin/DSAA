#include<iostream>
#include<vector>
#include<string>

using namespace std;

void getnext(string,vector<int>&);

int main()
{
	string target;
	std::vector<int> next;
	while(cin >> target)
	{
		next.clear();
		getnext(target,next);
		for(auto it = next.begin();it!=next.end();it++) cout << *it << " ";
		cout << endl;
	}
	return 0;
}

void getnext(string target,vector<int>& next)
{
	int len = target.size();
	int i = 0, j = -1;
	next.push_back(-1);
	while(i < len)
	{
		if(j==-1||target[i]==target[j])
		{
			i++; j++;
			next.push_back(j);
		}
		else j = next[j];
	}
}
