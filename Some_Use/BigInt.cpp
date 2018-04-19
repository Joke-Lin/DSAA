#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class BigINT
{
public:
	BigINT operator = (const string& str);
	static const int Weight = 4;
	static const int MAX = 10000;
	BigINT operator + (const BigINT num_2);
	BigINT operator * (const BigINT num_2);
	friend ostream& operator << (ostream& out,const BigINT& num_2);
	friend istream& operator >> (istream& in,BigINT& num_2);
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

int main()
{
	BigINT a,b;
	// while(n--)
	// 	{
	// 		cin >> a >> b;
	// 		cout << a*b << endl;
	// 	}
	cin >> a >> b;
	cout << a*b ;
	return 0;
}
