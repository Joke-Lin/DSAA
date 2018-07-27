//:poj2318
//叉积的运用
#include<cstdio>
#include<iostream>
#include<cstring>

const int maxn = 5010;
using namespace std;

struct Point{
    double x,y;
    Point(double x = 0,double y = 0):x(x),y(y){}
};
typedef Point Vector; //点的别名

double Cross(Vector A,Vector B){ return A.x*B.y-A.y*B.x;}//叉乘
Vector operator - (Point A,Point B){ return Vector(A.x-B.x,A.y-B.y);}

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int n,m,x1,y1,x2,y2,U[maxn],L[maxn],ans[maxn];
    while(scanf("%d",&n),n)
    {
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for(int i = 0;i < n;i++) scanf("%d%d",U+i,L+i);
        memset(ans,0,sizeof(ans));
        for(int i = 0;i < m;i++)
        {
            int x,y,j; scanf("%d%d",&x,&y);
            Point toy(x,y);
            for(j = 0;j < n;j++)
            {
                Point Up(U[j],y1),Down(L[j],y2);
                if(Cross(Up-Down,toy-Down)>=0) break;
            }
            ans[j]++;
        }
        for(int i = 0;i <= n;i++) printf("%d: %d\n",i,ans[i]);
        printf("\n");
    }
}