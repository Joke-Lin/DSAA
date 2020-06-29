//https://blog.csdn.net/liuke19950717/article/details/50803721
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int ball[11],l[11],r[11];
bool flag = false;

void dfs(int i,int j,int k)
{
    if(i >= 10){
        flag = true;
        return;
    }
    if(flag) return;//有一种满足之后就没有必要继续搜索l
    if(ball[i] >= l[j])
    {
        l[j+1] = ball[i];
        dfs(i+1,j+1,k);
    }
    if(ball[i] >= r[k])
    {
        r[k+1] = ball[i];
        dfs(i+1,j,k+1);
    }
    return;
}

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int T; scanf("%d",&T);
    while(T--)
    {
        flag = false;
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for(int i = 0;i < 10;i++) scanf("%d",ball+i);
        dfs(0,0,0);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}