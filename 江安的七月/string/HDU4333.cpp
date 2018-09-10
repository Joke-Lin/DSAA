#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
// #define LOCAL

const int maxn = 1e5*2+10;
int G,E,L,len;

char des[maxn];
char res[maxn];
int NEXT[maxn];//从[i,len-1]与原串的最大相同前缀
int extend[maxn];

void get_next();
void get_extend();
int cal_again();//计算重复

int main()
{
#ifdef LOCAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++)
    {
        G = E = L = 0;
        scanf("%s",res);
        strcpy(des,res);
        strcat(des,res);
        len = strlen(res);
        get_extend();
        for(int i = 0;i < len;i++)
        {
            if(extend[i] == len) 
            {
                E++;
                continue;
            }
            if(des[i+extend[i]] > res[extend[i]]) G++;
            else L++;
        }
        int again = cal_again();
        // printf("again:%d\n",again);
        printf("Case %d: %d %d %d\n",kase,L/again,E/again,G/again);
    }
    return 0;
}

void get_next()
{
    int len = strlen(res);
    NEXT[0] = len;
    int a,p;//开始和最长匹配
    for(int i = 1,j = -1;i < len;i++,j--)//j是i与p的距离
    {
        if(j < 0 || i+NEXT[i-a] >= p)
        {
            if(j < 0) p = i,j = 0;
            while(p < len && res[p] == res[j]) p++,j++;
            NEXT[i] = j;
            a = i;
        }
        else NEXT[i] = NEXT[i-a];
    }
}

void get_extend()
{
    get_next();
    int a,p;
    int len_des = strlen(des);
    int len_res = strlen(res);
    for(int i = 0,j = -1;i < len_des;i++,j--)
    {
        if(j < 0 || i+NEXT[i-a] >= p)
        {
            if(j < 0) p = i,j = 0;
            while(p < len_des && j < len_res && des[p] == res[j]) p++,j++;
            extend[i] = j;
            a = i;
        }
        else extend[i] = NEXT[i-a];
    }
}

int cal_again()
{
    int Next[maxn];
    int j = 0,k = -1;
    Next[0] = -1;
    while(j < len)
    {
        if(k==-1 || des[j]==des[k]) Next[++j] = ++k;
        else k = Next[k];
    }
    if(len%(len-Next[len]) == 0) return len/(len-Next[len]);
    else return 1;
}