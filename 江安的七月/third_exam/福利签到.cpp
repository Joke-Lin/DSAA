// Glory非常喜欢玩滑滑梯游戏，下面给出了一个n,m的滑道，其中的数字表示滑道的高度。Glory可以从一个点出发向下滑行，每次只能滑行到相邻的位置(上下左右)中高度严格低于当前高度的地方，不能重复划行已经滑行过的地方，但他希望在这个滑道上滑行尽量远的距离，也即是找一条最长的滑道。

// Input
// 第一行输入两个数n,m代表滑梯范围行n和列m(1 <= n,m <= 100)。下面是n行，每行有m个整数，代表高度h，(0<=h<=20000)

// Output
// 输出一个值，代表Glory能够在滑滑梯上面滑行的最长长度是多少

// Sample Input
// 3 3
// 9 1 2
// 5 6 7
// 8 4 3

// Sample Output
// 4

// Sample Input
// 4 7
// 7 6 5 4 3 2 1
// 1 5 1 1 1 1 1
// 1 4 3 1 1 1 1
// 1 5 6 7 8 1 1

// Sample Output
// 7
//目测DFS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
// #define LOCKAL

using namespace std;
const int maxn = 100+10; 
int n,m;//n行m宽
int map[maxn][maxn];//地图
int used[maxn][maxn];//判断是否用过
int vis[maxn][maxn];//优化 不然RE 记忆话搜索
int direction[4][2] = {
    {-1 , 0},
    {1 , 0},
    {0 , -1},
    {0 , 1}
};

int dfs(int x,int y);

int main()
{
#ifdef LOCKAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    // while(scanf("%d%d",&n,&m)==2)
    scanf("%d%d",&n,&m);
    {
        memset(used,0,sizeof(used));
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++) scanf("%d",&map[i][j]);
        int ans = 1;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                memset(used,0,sizeof(used));
                if(vis[i][j] == 0) vis[i][j] = dfs(i,j);
                ans = max(ans,vis[i][j]);
            }
        }  
        printf("%d\n",ans);
    }
    return 0;
}

int dfs(int x,int y)
{
    if(vis[x][y]) return vis[x][y];
    int ans = 1;
    used[x][y] = 1;
    for(int k = 0;k < 4;k++) //循环四个方向
    {
        int temp = 1;
        int dx = x+direction[k][0];
        int dy = y+direction[k][1];
        if(!used[dx][dy] && 1<=dx && dx<=n && 1<=dy && dy<=m)
        {
            if(map[dx][dy] < map[x][y]) //可以走
            {
                used[dx][dy] = 1;
                vis[dx][dy] = dfs(dx,dy);
                temp += vis[dx][dy];
                used[dx][dy] = 0;//回溯
            }
        }
        ans = max(ans,temp);
    }
    return ans;
}