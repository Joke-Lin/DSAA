//POJ3368
//pageq98
//attention it is non-decreasing order
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<algorithm>

#define CLS(x) memset(x,0,sizeof(x))

const int maxn = 1e5+10;

using namespace std;

int n,m,x,y;//n个数字 m组询问 左右两个端点
int a[maxn],value[maxn],Count[maxn],num[maxn],left[maxn],right[maxn];//存数字

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(int i = 0;i < n;i++) scanf("%d",a+i);
        int cmp = a[0],index = 0,sum = 0;
        for(int i = 0;i < n;i++)//初始化，方法比较笨，有待改进
        {
            if(cmp != a[i])
            {
                Count[index] = sum;
                value[index++] = cmp;
                cmp = a[i];
                if(i == n-1) {
                    value[index] = cmp;
                    Count[index++] = 1;
                    break;
                }
                sum = 0;
            }
            if(i == n-1) {
                value[index] = cmp;
                Count[index++] = sum+1;
                break;
            }
            sum++;
        }
        //Count[index-1]++;
        for(int i = 0;i < index;i++) printf("value[%d]: %d count[%d]:%d\n",i,value[i],i,Count[i]);
        for(int i = 0;i < m;i++){
            scanf("%d%d",&x,&y);
        }
    }

    return 0;
}