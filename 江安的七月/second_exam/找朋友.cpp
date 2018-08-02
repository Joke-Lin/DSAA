//DFS
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 100+10;
int m,n;//n行m列
char map[maxn][maxn];

void dfs(int x,int y);

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    while(scanf("%d%d",&n,&m),n+m)
    {
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++) cin >> map[i][j];
        int ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(map[i][j] == '@'){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}

void dfs(int x,int y)
{
    map[x][y] = '*';
    for(int dx = -1;dx <= 1;dx++)
    {
        for(int dy = -1;dy <= 1;dy++)
        {
            int nx = x+dx,ny = y+dy;
            if(0<=nx&&nx<=n && 0<=ny&&ny<=m && map[nx][ny]=='@') dfs(nx,ny);
        }
    }
}