#include<iostream>
#include<string>
#include<stack>
#include<map>
#include<cctype>
#include<conio.h>

using namespace std;

typedef pair<string,double> string_int;

string input();     //输入控制
bool judgec(char);  //判断是否是运算符
string_int transform(string); //转换
void del(int); //对input中的回退功能

int main()
{	
	string a = "abc";
	a.insert(1,1,'d');
	cout << a << endl;
	cout << "Welocme to JOKER_Lin's calculator.....\n\n";
	string src; 
	while(true)
	{
		src = input();
		string_int result = transform(src);
		cout << "the Reverse Polish : "<< result.first << endl;
		cout << "the result is: " << result.second << endl << endl;
	}
	return 0;
}

void del(int a)
{
	if(a) cout << "\b";
	else cout << "\b \b";
	return;
}

bool judgec(char c)   //判断是否是运算符
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
	{
		return true;
	}
	return false;
}

string input()
{
	string src;
	char c,prev,preb;
	int number = 0;
	while(c = getch())
	{
		if(!(judgec(c)||c=='('||c==')'||c=='.'||isdigit(c)|| c == '\r' || c=='\b')) continue; //控制输入符号
		if(src.length()==0) 
		{
			if(isdigit(c) || c=='+' || c=='-' || c=='(')
			{
				cout << c;
				src.append(1,c);
				prev = c;
				continue;
			}
			else continue;
		}
		if(c == '/' || c=='*' && src.length()==1) continue;
		if(c == '\r')
		{
			if(judgec(prev)||prev == '(') continue;
			else 
			{
				cout << endl;
				break;
			}
		}
		else if(c == '\b') 
		{
			del(0);
			if(src.length()!= 0)
			{
				src.erase(src.length()-1,1);
				if(src.length()!= 0) prev = src.at(src.length()-1);
			}
		}
		else
		{
			if((isdigit(prev)||prev==')')&& c=='(')   //对1（） 和）（这种排除
			{
				continue;
			}
			if(judgec(prev) && (judgec(c)|| c==')'))   //对于按下两个运算符只保留后一个
			{
				del(1);
				src.erase(src.length()-1,1);
				prev = c;           //每次记录前一个符号，如果合法
				src.append(1,c);
			}
			else
			{
				prev = c;           //每次记录前一个符号，如果合法
				src.append(1,c);
			}
			cout << c;
		}
		//cout <<"\nsrc:" <<  src << endl;
	}
	return src;
}


string_int transform(string src)
{
	string_int result;
	const string minus = "(#1)*";
	const string plus = "($1)*";
	bool flag = true;
	int sum = 0;
	int change_number[50];
	stack<char> kuohao;
	int kuohao_conflict[10];
	int index = 0;
	//判断是否合法（括号的问题） 使用栈（入栈  ）使出（栈，合法的话最后是空栈
	for(int i = 0;i < src.length();i++)
	{
		if(src[i]=='('&&src[i+1]==')')  //在()里面插入0
		{
			kuohao_conflict[index++] = i+1;
		}
		if(src[i] == '(') kuohao.push(src[i]);
		if(src[i] == ')') kuohao.pop();
	}
	if(!kuohao.empty())
	{
		result.first = "Error!!! the number of () is not right";
		result.second = 0;
		return result;
	}
	//源字符串预处理，处理例如（-（-2+1））这类嵌套有符号 将负号替换为（#1）* 正号变为 （1）*
	flag = true;  //判断负号用#号替代,正号用$代替
	for(int i = 0;i < src.length();i++)
	{
		if(src[i] == ' ') continue;  //空格就下一次
		if(flag && (src[i]=='-'||src[i] == '+'))
		{
			change_number[sum] = i;
			sum++;
			if(src[i] == '-') src[i] = '#';
			else if(src[i] == '+') src[i] = '$';
		}
		else if(src[i]=='(')
		{
			flag = true;
		}
		else flag = false;
	}
	//把￥#替换 从后往前替换，避免长度改变导致i过期index同
	for(int i = sum-1;i >= 0;i--)
	{
		if(src[change_number[i]] == '#') src.replace(change_number[i],1,minus);
		if(src[change_number[i]] == '$') src.replace(change_number[i],1,plus);
	}
	for(int i = index-1;i >= 0;i--)
	{
		src.insert(kuohao_conflict[i],1,'0');
	}
	//判断负号用#号替代,正号用$代替
	// flag = true;
	// for(int i = 0;i < src.length();i++)
	// {
		// if(src[i] == ' ') continue;  //空格就下一次
		// if(flag && (src[i]=='-'||src[i] == '+'))
		// {
			// if(src[i] == '-') src[i] = '#';
			// else if(src[i] == '+') src[i] = '$';
		// }
		// else if(src[i]=='(')
		// {
			// flag = true;
		// }
		// else flag = false;
	// }
	map<char,int> priority;           //设置优先级
	priority['+'] = priority['-'] = 1;
	priority['*'] = priority['/'] = 2;
	priority['('] = 0;
	stack<char> symbol;
	flag  = true;
	//将源字符串改为后缀数字与运算符空格隔开
	for(int i = 0;i < src.length();i++)
	{
		char c = src[i];
		if(c == ' ') continue;
		if(isdigit(c)||c =='.'||c == '#'||c=='$') 
		{
			if(flag) result.first.append(1,c);       //合适的时候隔开数字（在后面输出空格）
			else 
			{
				result.first.append(1,' ');
				result.first.append(1,c);
				flag = true;
			}
		}
		else										//不是数字部分
		{
			if(c != '(' && c != ')')              //遇到运算符置为false
			{
				flag = false;
				while(!symbol.empty() && priority[symbol.top()] >= priority[c]) //将符号载入src运算符与数字隔开方便下面的转换
				{
					result.first.append(1,' ');
					result.first.append(1,symbol.top());
					symbol.pop();
				}
				symbol.push(c);
			}
			else if (c == '(')
			{
				symbol.push(c);
			}
			else if(c == ')')
			{
				while(symbol.top()!='(')
				{
					result.first.append(1,' ');
					result.first.append(1,symbol.top());
					symbol.pop();
				}
				symbol.pop();
			}
		}
	}
	while(!symbol.empty())
	{
		result.first.append(1,' ');
		result.first.append(1,symbol.top());
		symbol.pop();
	}
	//上面以空格隔开，方便判断一段数字
	//calcute the result	
	string number;
	stack<double> numbers;
	for(int i = 0;i < result.first.length();i++)
	{
		char c = result.first[i];
		//if(i == result.first.length()) break;
		if(isdigit(c)||c == '.'|| c == '#' || c=='$')  //正负号处理
		{
			if(c == '#') c = '-';
			else if(c == '$') c = '+';
			number.append(1,c);
		}
		else
		{
			if(c == ' ' )
			{
				if(!number.empty()) numbers.push(atof(number.c_str()));  //内置函数转换
			}
			else
			{
				double num1,num2,num3;
				num1 = numbers.top(); numbers.pop();
				num2 = numbers.top(); numbers.pop();
				switch(c)                             //运算
				{
					case '+':
						num3 = num1+num2;
						break;
					case '-':
						num3 = num2-num1;
						break;
					case '*':
						num3 = num2*num1;
						break;
					case '/':
						num3 = num2/num1;
						if(num1 == 0) 
						{
							result.first = "wrong !!!! over the zero";
							result.second = 0;
							return result;
						}
						break;
				}
				numbers.push(num3);
			}
			number.erase(0,number.length());//将number置为空，准备接受下一个数字
		}
	}
	if(!numbers.empty())result.second = numbers.top();
	//else result.second = atof(number.c_str());
	return result;
}