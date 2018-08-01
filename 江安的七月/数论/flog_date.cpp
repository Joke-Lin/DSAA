//https://blog.csdn.net/dtl66/article/details/52079784
#include<stdio.h>
#include<math.h>

int x,y;
int exgcd(int a,int b)//方程ax+by=gcd(a,b)的一对解 
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b);
    int tem=x;
    x=y;
    y=tem-a/b*y;
    return r; 
} 

int main()
{
    int m,n,X,Y,l,a,b,c,d; 
    while(~scanf("%d %d %d %d %d",&X,&Y,&m,&n,&l))
    {
        a=n-m;
        b=l;
        c=X-Y;
        d=exgcd(a,b);
        if(c%d!=0)//此条件下，无整数解 c与a,b没有约数
        {
            printf("Impossible\n");
            continue;
        }
        x=x/d*c;//ax+by=c的x的一个特解 
        int b1=abs(b/d);//ax+by=c的通解x=x1+b1*t(t为任意整数） 特解+通解
        x=(x%b1+b1)%b1;//确定最小正解 

        printf("%d\n",x);

     } 
    return 0;
 } 