//果园.pdf
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

char map[110][110];
int ans,w,h;

void dfs(int x,int y,char target);//对此类进行DFS

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    while(scanf("%d%d",&h,&w),w+h)
    {
        int x,y;
        for(int i = 0;i < h;i++)
            for(int j = 0;j < w;j++) cin >> map[i][j];
        ans = 0;
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                if(map[i][j] != '.')
                {
                    dfs(i,j,map[i][j]);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

void dfs(int x,int y,char target)
{
    map[x][y] = '.';
    if(map[x+1][y] == target && (0<=(x+1)&&(x+1)<h)) dfs(x+1,y,target);
    if(map[x][y+1] == target && (0<=(y+1)&&(y+1)<w)) dfs(x,y+1,target);
    if(map[x-1][y] == target && (0<=(x-1)&&(x-1)<h)) dfs(x-1,y,target);
    if(map[x][y-1] == target && (0<=(y-1)&&(y-1)<w)) dfs(x,y-1,target);
    return;
}