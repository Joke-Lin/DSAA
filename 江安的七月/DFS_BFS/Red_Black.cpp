//:HDU1312
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
char map[21][21];
int ans,w,h;

void dfs(int x,int y);//对人的位置处DFS

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    while(scanf("%d%d",&w,&h),(w!=0 || h!=0))
    {
        int x,y;
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                cin >> map[i][j];
                if(map[i][j] == '@') x = i,y = j;
            }
        }
        ans = 0;
        dfs(x,y);
        printf("%d\n",ans);
    }
    return 0;
}

void dfs(int x,int y)
{
    ans++;
    map[x][y]='#';
    if(map[x+1][y] == '.' && (0<=(x+1)&&(x+1)<h)) dfs(x+1,y);
    if(map[x][y+1] == '.' && (0<=(y+1)&&(y+1)<w)) dfs(x,y+1);
    if(map[x-1][y] == '.' && (0<=(x-1)&&(x-1)<h)) dfs(x-1,y);
    if(map[x][y-1] == '.' && (0<=(y-1)&&(y-1)<w)) dfs(x,y-1);
    return;
}