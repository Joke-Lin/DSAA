//https://blog.csdn.net/vv494049661/article/details/50916301
//uva10825
//通过枚举每一种个位，推导出该序列的一种可能的数值组合
//然后枚举该序列的所有搭配可能
//判断是否有一中排列满足要求
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int m,n;//m位n进制
int vis[10],num[10],order[10];//判断是否用过 存数字 顺序便于枚举全排列

bool judge(int x);//判断以x结尾的这段数值符不符合要求

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    while(scanf("%d%d",&m,&n),m+n)
    {
        bool flag = false;
        for(int i = 1;i < n;i++) //枚举最后一位数字 为什么不能是0？？？
        {
            for(int j = 1;j <= m;j++) num[j] = (i*j)%n;//顺序是倒序 最后一位乘j就可以得到数字里面的各个位值
            if(judge(i)){
                flag = true;//如果i符合要求
                for(int j = m;j >= 2;j--) printf("%d ",num[order[j]]);//逆序输出
                printf("%d\n",i);//i是最后一位
                break;
            }
        }
        if(!flag) printf("Not found.\n");
    }
    return 0;
}

bool judge(int x)
{
    for(int i = 2;i <= m;i++) order[i] = i;//初始化顺序 最后一位已经确定
    do{
        bool flag = true;
        for(int i = 2;i <= m;i++)//乘以2...m
        {
            memset(vis,0,sizeof(vis));
            vis[i] = 1;
            int c = x*i/n;//进位 这里是最后一位的操作 不用整除 x就是整除结果
            for(int j = 2;j <= m;j++)
            {
                int temp = (num[order[j]]*i+c)%n;//第j个位置乘以i
                c = (num[order[j]]*i+c)/n;
                bool flag2 = false;
                for(int k = 1;k <= m;k++) //判断是否是这个序列里的值
                {
                    if(temp == num[k] && !vis[k])
                    {
                        vis[k] = 1;//第k位已经用过 不能重复
                        flag2 = true;
                        break;
                    }
                }
                if(!flag2) {//如果找不到退出
                    flag = false;
                    break;
                }
            }
            if(!flag) break;//退出此种情况
        }
        if(flag) return true;
    }while(next_permutation(order+2,order+m+1));//遍历该种数值序下的每一种情况
    return false;
}