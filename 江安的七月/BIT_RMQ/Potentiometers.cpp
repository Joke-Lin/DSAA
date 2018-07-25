//:page247 树状数组
// 给定n个整数，两个操作，
// S x y：把第x个数变成y
// M x y：计算第x个数到第y个数的总和
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define lowbit(x) ((x)&(-x))
#define CLS(x) memset(x,0,sizeof(x))

using namespace std;

const int maxn = 2e5+10;

int numbers[maxn],C[maxn],n;

int sum(int);//前缀和
void add(int,int);//更新值

int main()
{
    char cmd[5];
    int Case = 0;
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    while(scanf("%d",&n),n)
    {
        CLS(numbers); CLS(C);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",numbers+i);
            add(i,numbers[i]);
        }
        if(Case) printf("\n");
        printf("Case %d:\n",++Case);
        while(scanf("%s",cmd) && cmd[0] != 'E')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(cmd[0] == 'S')
            {
                add(x,y-numbers[x]);
                numbers[x] = y;
            }
            else printf("%d\n",sum(y)-sum(x-1));
        }
    }
    return 0;
}

int sum(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans += C[x]; x -= lowbit(x);
    }
    return ans;
}

void add(int x,int d)
{
    while(x <= n)
    {
        C[x] += d; x += lowbit(x);
    }
}