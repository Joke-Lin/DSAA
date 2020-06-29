// http://www.hankcs.com/program/aoj-0558-cheese-challenge-programming-contest-2nd-edition-exercises-answers.html
//从小到大走就可以
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;
typedef pair<int,int> P;
char map[1010][1010];
int factory[10][2];
int d[1010][1010];
int dre[4][2] = 
{
    {-1 , 0},
    {1 , 0},
    {0 , -1},
    {0 , 1}
};

int h,w,n;

int BFS(int begin_x,int begin_y,int end_x,int end_y);//返回两个点之间的最短路

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    while(cin >> h >> w >>n)
    {
        for(int i = 0;i < h;i++)
        {
            for(int j = 0;j < w;j++)
            {
                cin >> map[i][j];
                if(map[i][j] == 'S')
                {
                    factory[0][0] = i; //老鼠自己也算工厂
                    factory[0][1] = j;
                    map[i][j] = '.';
                }
                else if(isdigit(map[i][j]))
                {
                    factory[map[i][j]-'0'][0] = i;
                    factory[map[i][j]-'0'][1] = j;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i++) ans += BFS(factory[i][0],factory[i][1],factory[i+1][0],factory[i+1][1]);
        printf("%d\n",ans);
    }
    return 0;
}

int BFS(int begin_x,int begin_y,int end_x,int end_y)
{
    for(int i = 0;i < h;i++)
        for(int j = 0;j < w;j++) d[i][j] = -1;
    queue<P> que;
    que.push(P(begin_x,begin_y));
    d[begin_x][begin_y] = 0;
    while(!que.empty())
    {
        P now = que.front(); que.pop();
        if(now.first == end_x && now.second == end_y) break;
        for(int i = 0;i < 4;i++)//四个方向
        {
            int nx = now.first + dre[i][0];
            int ny = now.second + dre[i][1];
            if(0 <= nx && nx < h && 0 <= ny && ny < w && map[nx][ny] != 'X' && d[nx][ny] == -1)
            {
                que.push(P(nx,ny));
                d[nx][ny] = d[now.first][now.second]+1;
            }
        }
    }
    return d[end_x][end_y];
}