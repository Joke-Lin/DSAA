//http://www.cnblogs.com/kickit/p/7682490.html
// 题意：
// 有若干个由两种元素组成的简单化合物，
// 现在把它们装进车里，如果车上有恰好有k种简单化合物并且恰好有k种元素的话，那么就会引发爆炸，
// 所以车上的化合物必须避免满足这个条件。
// 现在用一个整数表示元素，每行两个整数表示一个简单化合物，按顺序给出，
// 求出这些化合物中有多少个化合物不能装进车。
// Sample Input
// 1 2
// 3 4
// 3 5
// 3 1
// 2 3
// 4 1
// 2 6
// 6 5
// -1

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stdlib.h>

using namespace std;

const int maxn = 100000+10;

int father[maxn];//存父节点

void init();
int find(int);
bool Uion(int,int);

int main()
{
    int x,y;
    while(~scanf("%d",&x))
    {
        int ans = 0;
        init();
        while(true)
        {
            if(x == -1) break;
            scanf("%d",&y);
            if(Uion(x,y) == true) ans++;//如果构成环+1
            scanf("%d",&x);
        }
        printf("%d\n",ans);
    }
    //system("pause");
    return 0;
}

void init()
{
    for(int i = 0;i <= maxn;i++) father[i]=i;
}

int find(int x)
{
    return x == father[x] ? x:father[x] = find(father[x]);
}

bool Uion(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    //printf("fx %d %d",fx,fy);
    if(fx != fy) 
    {
        father[fx] = fy;
        return false;
    }
    return true;

}