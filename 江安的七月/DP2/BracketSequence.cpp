//page278
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int maxn = 110;

inline bool match(char a,char b){//判断是否匹配
    if((a=='('&&b==')')||(a=='['&&b==']')) return true;
    else return false;
}

char S[maxn];
int d[maxn][maxn];
int n;//字符串长度

void dp();
void print(int i,int j);

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int T; scanf("%d",&T);
    getchar();
    while(T--)
    {
        cin.getline(S,maxn);
        cin.getline(S,maxn);
        n = strlen(S);
        dp();
        print(0,n-1);
        puts("");
        if (T) puts("");
    }
    return 0;
}

void dp()
{
    for(int i = 0;i < n;i++)//边界条件
    {
        d[i+1][i] = 0;
        d[i][i] = 1;
    }
    for(int i = n-2; i>= 0;i--)
    {
        for(int j = i+1;j < n;j++)
        {
            d[i][j] = n;//INF
            if(match(S[i],S[j])) d[i][j] = min(d[i][j],d[i+1][j-1]);//1
            for(int k = i; k < j;k++) d[i][j] = min(d[i][j],d[i][k]+d[k+1][j]);//2
        }
    }
}

void print(int i,int j)
{
    if(i > j) return;//空串
    if(i == j)
    {
        if(S[i] == '(' || S[i] == ')') printf("()");
        else printf("[]");
        return;
    }
    int ans = d[i][j];
    if(match(S[i],S[j]) && ans == d[i+1][j-1])
    {
        printf("%c",S[i]);
        print(i+1,j-1);
        printf("%c",S[j]);
        return;
    }
    for(int k = i; k < j;k++)
    {
        if(ans == d[i][k]+d[k+1][j]){
            print(i,k);print(k+1,j);
            return;
        }
    }
}