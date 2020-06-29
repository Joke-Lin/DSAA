//:POJ3009
//https://www.cnblogs.com/Ash-ly/p/5728439.html    DFS
//https://www.cnblogs.com/Lyush/archive/2012/10/18/2730205.html   BFS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 25;

int map[maxn][maxn];
int dre[4][2] = //四个方向
{
    {-1 , 0},
    {1 , 0},
    {0 , -1},
    {0 , 1}
};
int ans,w,h;
int st_x,st_y,ed_x,ed_y;

int check(int x,int y);//判断此点是否可通
void DFS(int x,int y,int t);

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    while(scanf("%d%d",&w,&h),w||h)
    {
        memset(map,-1,sizeof(map));
        for(int i = 1;i <= h;i++){
            for(int j = 1;j <= w;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j] == 2) st_x = i,st_y = j;
                if(map[i][j] == 3) ed_x = i,ed_y = j;
            }
        }
        ans = maxn;
        DFS(st_x,st_y,0);
        printf("%d\n",ans>10?-1:ans);
    }
    return 0;
}

int check(int x,int y)
{
    if(map[x][y] == 0 || map[x][y] == 2) return 1;
    else if(map[x][y] == -1 || map[x][y] == 1) return 2;
    else return 3;
}

void DFS(int x,int y,int t)
{
    if(x == ed_x && y == ed_y || t > 10)//要找最短的步数
    {
        ans = (t>ans?ans:t);
    }
    else
    {
        for(int i = 0;i < 4;i++)//遍历四个方向
        {
            int now_x = x,now_y = y;
            if(check(now_x+dre[i][0],now_y+dre[i][1]) != 2)//可以继续走
            {
                while(check(now_x+dre[i][0],now_y+dre[i][1])==1) now_x += dre[i][0],now_y += dre[i][1];
                if(map[now_x+dre[i][0]][now_y+dre[i][1]] == 1) //有障碍物
                {
                    map[now_x+dre[i][0]][now_y+dre[i][1]] = 0;//击碎
                    t++;//说明开启新一轮滚动
                    DFS(now_x,now_y,t);//之后需要回溯
                    --t;
                    map[now_x+dre[i][0]][now_y+dre[i][1]] = 1;//复原
                }
                else if(map[now_x+dre[i][0]][now_y+dre[i][1]] == 3){//到终点
                    t++;
                    DFS(now_x+dre[i][0],now_y+dre[i][1],t);//会直接返回
                    t--;
                }
            }
        }
    }
}