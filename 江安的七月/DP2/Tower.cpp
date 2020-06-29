//uva437
//原理同最长上升子序列
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

struct block{
    int x,y,z;
    void set(int a,int b,int c){
        x = a;
        y = b;
        z = c;
    }
}Block[200];//30*6

bool cmp(const block& a,const block& b)//从小到大排 面积 符合条件的面积一定比后面的小
{
    return a.x*a.y < b.x*b.y;
}

int n,dp[200];//dp[i]表示以i这个块结尾的最高度
int x,y,z;


int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int kase = 0;
    while(scanf("%d",&n),n)
    {
        int num = 0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            Block[num++].set(x,y,z);
            Block[num++].set(x,z,y);
            Block[num++].set(z,y,x);
            Block[num++].set(z,x,y);
            Block[num++].set(y,x,z);
            Block[num++].set(y,z,x);
        }
        sort(Block,Block+num,cmp);//使可以放的相对顺序满足
        int len = 0;
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < num;i++)
        {
            dp[i] = Block[i].z;
            for(int j = 0;j < i;j++)
            {
                if(Block[i].x>Block[j].x && Block[i].y>Block[j].y)//满足条件的
                {
                    dp[i] = max(dp[i],dp[j]+Block[i].z);
                }
            }
            len = max(len,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",++kase,len);
    }
    return 0;
}