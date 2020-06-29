//https://blog.csdn.net/rollchuchy/article/details/50733771
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

int MOVE[4] = {1,-1,4,-4};
map<string,int> DP;

void BFS()
{
    queue<string> que;
    que.push("01234567");
    DP["01234567"] = 0;
    while(!que.empty())
    {
        string now = que.front();//获取一个值
        que.pop();//弹出
        int pos;
        for(int i = 0;i < 8;i++)
        {
            if(now[i] == '0') pos = i;
        }
        for(int i = 0;i < 4;i++)
        {
            int n_pos = pos+MOVE[i];
            if(n_pos >= 0 && n_pos < 8 && !(pos == 3 && i== 0) && !(pos == 4 && i == 1))
            {
                string next = now;
                swap(next[pos],next[n_pos]);
                if(DP.find(next) == DP.end())//如果未找到的
                {
                    DP[next] = DP[now]+1;
                    que.push(next);
                }
            }
        }
    }
}

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    BFS();
    string str;
    while(getline(cin,str))
    {
        str.erase(remove(str.begin(),str.end(),' '),str.end());//删除所有的空格
        printf("%d\n",DP[str]);
    }


    return 0;
}