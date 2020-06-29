#include<iostream>
#include<vector>
#include<string>

using namespace std;

void getnext(string,vector<int>&);//next数组存放指定位置前的最长相同前后缀，不包括自己本身
int KMP(string ,string,vector<int>);

int main()
{
	string target,object;
	std::vector<int> next;
	while(true)
	{
		getline(cin,object);
		getline(cin,target);
		next.clear();
		getnext(target,next);
		cout << KMP(object,target,next)<<endl;
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
		if(j==-1||target[i]==target[j])  //如果满足条件则都向后移动一位
		{
			i++; j++;
			next.push_back(j);
		}
		else j = -1;    //否则J重新从头开始
	}
}

int KMP(string object,string target,vector<int> it)
{
	int i = 0,j = 0;
	int len1 = object.size();
	int len2 = target.size();
	while(i < len1 && j <len2)
	{
		if(j==-1 || object[i]==target[j])
		{
			i++;j++;
		}
		else j = it[j];
	}
	if(j==len2)
	{
		return i-j;
	}
	else return -1;
}
