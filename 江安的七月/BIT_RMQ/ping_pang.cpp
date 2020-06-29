//page197
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#define lowbit(a) (a&-(a))

typedef long long ll;

using namespace std;

const int maxn1 = 20000+10;//有n个球员
const int maxn2 = 1e5+10;//运动员最大有1e5的技巧值

int a[maxn1];
int smaller[maxn1];//1-i有几个比ai小的
int bigger[maxn1];//i-n有几个比ai大的
int MID[maxn2];//计算smaller和bigger的中间数组

int sum(int);//前缀和
void add(int,int);//修改


int main()
{
    // freopen("./in.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--)
    {
        memset(bigger,0,sizeof(bigger));
        memset(smaller,0,sizeof(smaller));
        memset(MID,0,sizeof(MID));

        int m; scanf("%d",&m);
        ll ans = 0;
        for(int i = 1;i <= m;i++) scanf("%d",a+i);
        for(int i = 1;i <= m;i++){
            add(a[i],1);
            smaller[i] = sum(a[i]-1);
        }

        memset(MID,0,sizeof(MID));

        for(int i = m;i >= 1;i--){
            add(a[i],1);
            bigger[i] = sum(a[i]-1);
        }
        for(int i = 1;i <= m;i++){
            ans += smaller[i]*(m-i-bigger[i])+bigger[i]*(i-smaller[i]-1);
        }
        printf("%lld\n",ans);
    }
    // freopen("CON","r",stdin);
    // system("pause");
    return 0;
}

int sum(int x){
    int ans = 0;
    while(x>0){
        ans += MID[x];
        x -= lowbit(x);
    }
    return ans;
}

void add(int x,int d){
    if(x <= 0) return;
    while(x <= maxn2-1){
        MID[x] += d;
        x += lowbit(x);
    }
}