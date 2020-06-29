//:poj 2019 二维RMQ
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 255;

short num[maxn][maxn];
short f_max[maxn][maxn][8][8];
short f_min[maxn][maxn][8][8];

void rmq_init(int n,int m);//对相应大小的数组RMQ初始化
short rmq(int x,int y,int _x,int _y);//相应区间找最值

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    int n,b,k;
    while(scanf("%d%d%d",&n,&b,&k)==3)
    {
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++) scanf("%d",&num[i][j]);
        rmq_init(n,n);
        while(k--)
        {
            int x,y; scanf("%d%d",&x,&y);
            printf("%d\n",rmq(x,y,x+b-1,y+b-1));
        }
    }
    return 0;
}

void rmq_init(int n,int m)
{
    memset(f_max,0,sizeof(f_max));
    memset(f_min,0,sizeof(f_max));
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) f_max[i][j][0][0] = f_min[i][j][0][0] = num[i][j];
    for(int i = 0;(1<<i) <= n;i++)
        for(int j = 0;(1<<j) <= m;j++)
        {
            if(i == 0 && j ==0 ) continue;//此处只有一个元素不用讨论
            for(int ii = 1;ii + (1<<i) - 1 <= n;ii++)
                for(int jj = 1;jj + (1<<j) - 1 <= m;jj++)
                {
                    if(i == 0) //一个矩形分为两个部分 i==0时为一条线不能左右分要上下分 单独讨论
                    {//i j 不会同时为0
                        f_max[ii][jj][i][j]=max(f_max[ii][jj][i][j-1],f_max[ii][jj+(1<<(j-1))][i][j-1]);
                        f_min[ii][jj][i][j]=min(f_min[ii][jj][i][j-1],f_min[ii][jj+(1<<(j-1))][i][j-1]);
                    }
                    else
                    {
                        f_max[ii][jj][i][j]=max(f_max[ii][jj][i-1][j],f_max[ii+(1<<(i-1))][jj][i-1][j]);
                        f_min[ii][jj][i][j]=min(f_min[ii][jj][i-1][j],f_min[ii+(1<<(i-1))][jj][i-1][j]);
                    }
                }
        }
}

short rmq(int x,int y,int _x ,int _y)
{
    int kr = int(log(_x-x+1.0)/log(2.0));
    int kc = int(log(_y-y+1.0)/log(2.0));
    short mi = f_min[x][y][kr][kc],ma = f_max[x][y][kr][kc];
    //分为3个部分
    mi = min(mi,f_min[_x-(1<<kr)+1][y][kr][kc]);
    mi = min(mi,f_min[x][_y-(1<<kc)+1][kr][kc]);
    mi = min(mi,f_min[_x-(1<<kr)+1][_y-(1<<kc)+1][kr][kc]);

    ma=max(ma,f_max[_x-(1<<kr)+1][y][kr][kc]);
	ma=max(ma,f_max[x][_y-(1<<kc)+1][kr][kc]);
	ma=max(ma,f_max[_x-(1<<kr)+1][_y-(1<<kc)+1][kr][kc]);
    return ma-mi;
}