//page198
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<ctime>
#define CLS(x) memset(x,0,sizeof(x))

using namespace std;

const int maxn = 1e5+10;
int n,q;
int quene_pos[maxn];//存正数
int quene_neg[maxn];//存负数
int num[maxn];
int index[maxn];

int main()
{
    // freopen("./in.txt","r",stdin);
    while(scanf("%d",&n))
    {
        if(n == 0) break;
        CLS(quene_pos); CLS(quene_neg);
        scanf("%d",&q);
        for(int i = 1;i <= n;i++) scanf("%d",num+i);
        while(q--)
        {
            CLS(quene_pos); CLS(quene_neg);CLS(index);
            int x,y;
            int sum = 0;
            scanf("%d%d",&x,&y);
            for(int i = x;i <= y;i++)
            {
                if(num[i]>= 0) quene_pos[num[i]]++;
                else quene_neg[abs(num[i])]++;
                index[sum] = abs(num[i]);
                sum++;
            }
           // printf("sum:%d\n",sum);
            int ans = 0;
            for(int i = 0;i < sum;i++)
            {
                //if(quene_neg[i]==0 && quene_neg[i]==0) continue;
                ans = max(ans,quene_pos[index[i]]);
                ans = max(ans,quene_neg[index[i]]);
            }
            printf("%d\n",ans);
        }
    }
    // freopen("CON","r",stdin);
    // system("pause");
    return 0;
}