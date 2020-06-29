//给定一个字符串，找出不含有重复字符的 最长子串 的长度。
//
//示例：
//
//给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
//
//给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
//
//给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列 而不是子串。

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string) ;
	int Find(char c,int i,int j,string s)
	{
		for(int a = i;a < j;a++)
		{
			if(c==s[a]) return a;
		}
		return -1;
	}
};

int Solution::lengthOfLongestSubstring(string s)
{
	int MAX  = 0,i = 0,j = 0,len = 0;
	for(j = 0;j < s.size();j++)
	{
		int mid = Find(s[j],i,j,s);
		if(mid == -1) len++;
		else
		{
			i = mid+1;
			len = j-i+1;
		}
		if(MAX < len) MAX = len;
	}
	return MAX;
}

int main()
{
	Solution a;
	string str_1,str_2;
	cin>>str_1;
	cout<<a.lengthOfLongestSubstring(str_1);
	return 0;
}
