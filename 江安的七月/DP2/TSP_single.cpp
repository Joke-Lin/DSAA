//page270
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int n,m;//m行 n列
    while(cin >> m >> n)
    {
        int map[15][150];
        int d[15][150];
        int next[15][150];//路径顺序
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++) scanf("%d",&map[i][j]);
        int ans = INF,first = 0;
        for(int j = n-1;j >= 0;j--)//逆推
        {
            for(int i = 0;i < m;i++)
            {
                if(j == n-1) d[i][j] = map[i][j];//边界
                else
                {
                    int rows[3] = {i,i-1,i+1};
                    if(i == 0) rows[1] = m-1;
                    if(i == m-1) rows[2] = 0;
                    sort(rows,rows+3);//保证字典序
                    d[i][j] = INF;
                    for(int k = 0; k < 3;k++)
                    {
                        int v = d[rows[k]][j+1]+map[i][j];
                        if(v < d[i][j])
                        {
                            d[i][j] = v;
                            next[i][j] = rows[k];
                        }
                    }
                }
                if(j == 0 && d[i][j] < ans)//找到第一列的所求值以便推出其他的
                {
                    ans = d[i][j];
                    first = i;
                }
            }
        }
        printf("%d",first+1);
        for(int i = next[first][0],j = 1;j < n;i = next[i][j],j++) printf(" %d",i+1);
        printf("\n%d\n",ans);
    }
    return 0;
}