//http://www.mamicode.com/info-detail-2338704.html
//题目：https://blog.csdn.net/xs18952904/article/details/80400445

#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<algorithm>

using namespace std;

const int maxn = 1e6+5;
int cost[maxn];//每种灯的花费
bool blocked[maxn];//存灯的损坏情况
int pre_pos[maxn];//该位置最前面第一个可以放灯泡的位置

int main()
{
    int n,m,k; //路；锁定的灯座；有k种灯泡 ps:每种只能那一个！！！！！
    memset(blocked,0,sizeof(blocked));
    memset(pre_pos,0,sizeof(pre_pos));

    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0;i < m;i++)
    {
        int x; scanf("%d",&x);
        blocked[x] = true;
    }
    for(int i = 1;i <= k;i++) scanf("%d",&cost[i]);//第i种灯泡的价格
    if(blocked[0]) { printf("-1\n");return 0;}//第一个是锁的话，直接不行
    int front = 0;
    for(int i = 1;i <= n;i++)//设置pre数组
    {
        if(!blocked[i]) front = i;//没锁的话更新,针对连续锁的情况
        pre_pos[i] = front;
    }
    long long ans = 0;
    for(int i = 1;i <= k;i++)
    {
        long long cost_lamps = 0;//此种灯泡的总价格
        for(int pos = 0;pos < n;)//遍历所有的灯泡位
        {
            cost_lamps += cost[i];
            if(pos+i >= n) pos = n;//下一个就不用灯了
            else{
                int loc = pre_pos[pos+i];
                if(loc <= pos) {cost_lamps = -1; break;}//说明这个灯泡不能所有都照亮
                pos = loc;//下一个位置的设置
            }
        }
        if(cost_lamps == -1) continue;
        else{
            if(ans == 0) ans=cost_lamps;
            else ans = min(ans,cost_lamps);//取最小的那个
        }
    }
    if(ans == 0)  printf("-1");
    else printf("%lld",ans);
   // system("pause");
    return 0;
}