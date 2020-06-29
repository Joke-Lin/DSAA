//:poj 2019
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 255;
int num[maxn][maxn];

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    int N,B,K;
    while(scanf("%d%d%d",&N,&B,&K)==3)
    {
        for(int i = 1;i <= N;i++)
            for(int j = 1;j <= N;j++) scanf("%d",&num[i][j]);
        while(K--)
        {
            int MAX = -1,MIN = 0x3f3f3f3f;
            int x,y; scanf("%d%d",&x,&y);
            for(int i = x;i < x+B;i++)
            {
                for(int j = y;j < y+B;j++)
                {
                    MAX = max(MAX,num[i][j]);
                    MIN = min(MIN,num[i][j]);
                }
            }
            printf("%d\n",MAX-MIN);
        }

    }
    return 0;
}