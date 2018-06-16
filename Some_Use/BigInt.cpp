#include <iostream>
#include <cstring>
#include<string.h>
#include <vector>
#include <string>

using namespace std;

char str1[100000];
char str2[100000];

class BigINT
{
public:
	BigINT operator = (const string&);
	static const int Weight = 4;
	static const int MAX = 10000;
	bool operator > (const BigINT);
	bool operator == (const BigINT);
	bool operator < (const BigINT);
	BigINT operator + (const BigINT);
	BigINT operator * (const BigINT);
	BigINT operator - (const BigINT);
	BigINT operator / (const BigINT);
	BigINT operator % (const BigINT);
	friend ostream& operator << (ostream& out,const BigINT&);
	friend istream& operator >> (istream& in,BigINT&);
private:
	vector<int> num;
};

BigINT BigINT:: operator = (const string& str)
{
	num.clear();
	int number;
	int lenth = (str.size()-1)/Weight+1; //8位数应该是0+1不减1就错了
	//std::cout << lenth << '\n';
	for(int i = 0;i < lenth;i++)
	{
		int end = str.size()-Weight*i;
		int front = max(0,end - Weight);
		sscanf(str.substr(front,end-front).c_str(),"%d",&number);//注意是end - front 还有substr的越界
		num.push_back(number);
	}
	return *this;
}

ostream& operator << (ostream& out,const BigINT& num_2)
{
	int SIZE = num_2.num.size()-1;
	cout << num_2.num[SIZE];           //1避免输出00000000001这样
	for(int i = SIZE-1;i >= 0;i--)
	{
		out.width(BigINT::Weight);
		out.fill('0');
		out << num_2.num[i];       //100000009这样的数字存为1，9，输出要前补零
	}
	return out;
}

istream& operator >> (istream &in, BigINT& num_2)
{
	string s;
	if(!(in >> s))
	{
	  return in;      //排除输入错误
	  cout << "cout error\n";
	}
	num_2 = s;
	return in;
}

bool BigINT::operator > (const BigINT num_2)
{
	int len1 = num.size();
	int len2 = num_2.num.size();
	if(len1 > len2) return true;
	else if(len1 < len2) return false;
	else
	{
		for(int i = len1-1;i >= 0;i--)
		{
			if(num[i] > num_2.num[i]) return true;
			else if(num[i] < num_2.num[i]) return false;
		}
	}
	return false;
}

bool BigINT:: operator == (const BigINT num_2)
{
	int len1 = num.size();
	int len2 = num_2.num.size();
	if(len1 != len2) return false;
	else
	{
		for(int i = 0;i < len1;i++)
		{
			if(num[i] != num_2.num[i]) return false;
		}
	}
	return true;
}

bool BigINT::operator < (const BigINT num_2)
{
	if(*this > num_2 || *this == num_2) return false;
	else return true;
}

BigINT BigINT::operator + (const BigINT num_2)
{
	BigINT temp;
	temp.num.clear();    //保险
	int i = 0,get = 0; //get 存进位
	int len_1 = num.size()-1;
	int len_2 = num_2.num.size()-1;
	//cout << "len 1=" << len_1 <<"len_2 = "<< len_2 << endl;
	while(true)
	{
		int mid = get;
		if(i > len_1&&i > len_2 && get==0) break; //确保考虑到最后一位的进位处理
		if(i <= len_1) mid += num[i];
		if(i <= len_2) mid += num_2.num[i];
		temp.num.push_back(mid%MAX);
		get = mid/MAX;
		i++;
	}
	return temp;
}

BigINT BigINT:: operator - (const BigINT num_2)  //目前未考虑符号所以即使小于还是返回0
{
	BigINT temp; temp.num.clear();
	if(*this < num_2 || *this == num_2)
	{
		temp.num.push_back(0);
		return temp;
	}
	else
	{
		int len1 = num.size();
		int len2 = num_2.num.size();
		int give = 0, i = len1;
		for(i = 0;i < len1;i++)
		{
			int mid = 0,result = 0;
			num[i]+=give;
			if(i < len2)
			{
				if( num[i] < num_2.num[i])
				{
					give = -1;
					num[i] += MAX;
				}
				else give = 0;
				mid = num_2.num[i];
			}
			result = num[i] - mid;
			if(i==len1-1&&result == 0) return temp;
			temp.num.push_back(result);
		}
	}
	return temp;
}

BigINT BigINT::operator * (const BigINT num_2)
{
	BigINT temp_1,temp_2; //temp1用来存每一位2来存结果
	temp_1.num.clear(); temp_2.num.clear(); temp_2.num.push_back(0);
	int i = 0,get = 0,j = 0;
	int len_1 = num.size()-1;
	int len_2 = num_2.num.size()-1;
	//cout << "len1 = "<<len_1 <<" len2 = " << len_2 << endl;
	for(int i = 0;i <= len_2;i++)
	{
		temp_1.num.clear();
		//vector<int>().swap(temp_1.num);
		get = 0;  j = 0;
		while(true)
		{
			int mid = 0;
			if(j > len_1 && get == 0) break;
			if(j <= len_1) mid = num_2.num[i]*num[j];
			mid += get;
			temp_1.num.push_back(mid%MAX);
			get = mid/MAX;
			j++;
		}
		temp_1.num.insert(temp_1.num.begin(),i,0);
		//cout << i <<"is " << temp_1 << endl;
		temp_2 = temp_2 + temp_1;
	}
	return temp_2;
}

BigINT BigINT::operator / (const BigINT num_2)
{
	std::vector<int> value;
	BigINT result; result.num.clear();
	BigINT num1 = *this;
	BigINT num2 = num_2;
	if (num1 < num2)
	{
		result.num.push_back(0);
		return result;
	}
	int len1 = num1.num.size();
	int len2 = num2.num.size();
	int lenth = len1 - len2;
	for(int i = 0;i < lenth;i++)
	{
		num2.num.insert(num2.num.begin(),0);
	}
	while(true)
	{
		if(lenth < 0) break;
		int node = 0,flag = 0;
		while(num1 > num2 || num1 == num2)
		{
			flag = 1;
			node++;
			if(node > 9999) break;
			num1 = num1 - num2;
		}
		// cout << "node = " << node << "\n";
		if(flag) value.push_back(node);
		lenth--;
		num2.num.erase(num2.num.begin());
		// cout << "num1 = " << num1 << endl;
		// cout << "num2 = " << num2 << endl;
	}
	for(int i = value.size()-1;i >= 0;i--) result.num.push_back(value[i]);
	return result;
}
int main()
{
	BigINT a,b;
	while(scanf("%s %s",str1,str2))
	{
		a = str1;
		b = str2;
		std::cout << a/b << '\n';
	}
	return 0;
}
