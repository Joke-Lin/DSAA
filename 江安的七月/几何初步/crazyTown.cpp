// 一个神奇的小镇被n条马路分成一些区块。马路由方程ax+by+c= 0确定（马路没有宽度）
// 我们可以从一个区块进入另一个区块，当且仅当它们之间有公共马路，且公共部分的长度不为0。
// 现在告诉你你家的坐标和学校的坐标，求你到学校至少要穿越几个马路。保证家和学校的坐标不在马路上。
// Input
// 一行是两个整数x1, y1 ( - 106 ≤ x1, y1 ≤ 106) 表示你家的坐标
// 第二行是两个整数x2, y2 ( - 106 ≤ x2, y2 ≤ 106) 表示学校的坐标
// 第三行一个正整数n (1 ≤ n ≤ 300) 表示有几条马路。
// 接下来n行，每行3个整数a,b,c，表示一条马路的方程为ax+by+x=0，数据保证所有的马路互不相同
//:数学题判断有几条直线与线段AB相交即可
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    long long x1,x2,y1,y2,n;
    scanf("%lld%lld",&x1,&y1);
    scanf("%lld%lld",&x2,&y2);
    scanf("%lld",&n);
    long long ans = 0;
    for(long long i = 0;i < n;i++)
    {
        long long a,b,c; scanf("%lld%lld%lld",&a,&b,&c);
        long long s1=a*x1+b*y1+c;
        long long s2=a*x2+b*y2+c;
        if((s1>0&&s2<0)||(s1<0&&s2>0)) ans++;//直接相乘可能会溢出
    }
    printf("%lld",ans);
    return 0;
}