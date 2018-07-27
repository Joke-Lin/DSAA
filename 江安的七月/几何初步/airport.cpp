//page 274
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 1e4+10;
const double INF = 1e30;

struct Point{
    double x,y;
    Point(double x = 0,double y = 0):x(x),y(y){}
};

typedef Point Vector; //点的别名
const double eps = 1e-10;

Vector operator - (Point A,Point B){ return Vector(A.x-B.x,A.y-B.y);}
Vector operator + (Vector A,Vector B){ return Vector(A.x+B.x,A.y+B.y);}
Vector operator * (double x,Vector A){ return Vector(x*A.x,x*A.y);}
int dcmp(double x){ if(fabs(x)<eps) return 0; else return x<0?-1:1;}
bool operator < (const Point& a,const Point& b){ return a.x < b.x || (a.x == b.x && a.y < b.y);}
double Dot(Vector A,Vector B){ return A.x*B.x+A.y*B.y;}//点积
double Length(Vector A){ return sqrt(Dot(A,A));}//向量长度
double Angle(Vector A,Vector B){ return acos(Dot(A,B)/Length(A)/Length(B));}//直线夹角
double Cross(Vector A,Vector B){ return A.x*B.y-A.y*B.x;}//叉乘
Vector Rotate(Vector A,double rad){ return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}
double torad(double x){ return x/180.0*acos(-1);}//角度换算

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)//获取直线交点
{
    Vector u = P-Q;
    double t = Cross(w,u)/Cross(v,w);
    return P+t*v;
}

double PolygonArea(Point *p,int n)//n为边的个数 获取多边形面积
{
    double area = 0;
    for(int i = 1;i < n-1;i++)//以0作为划分点
    {
        area += Cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return area/2.0;
}

int ConvexHull(Point *p,int n,Point* ch)//输入点数组 个数 输出点数组 返回顶点数 凸包
{
    sort(p,p+n);
    int m = 0;
    for(int i = 0;i < n;i++)
    {
        while(m > 1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2;i >= 0;i--)
    {
         while(m > k && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]) <= 0) m--;
         ch[m++] = p[i];
    }
    if(n > 1) m--;
    return m;
}

void line(Point A,Point B,double &a,double &b,double& c)//转换成一般式
{
    a=B.y-A.y;
    b=A.x-B.x;
    c=B.x*A.y-A.x*B.y;
}

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    int T; scanf("%d",&T);
    for(int Case = 1;Case <= T;Case++)
    {
        Point P[maxn],ch[maxn];
        double sum_line = INF,sum_x = 0,sum_y = 0,A,B,C;
        int n; scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            double x,y; scanf("%lf%lf",&x,&y);
            P[i].x = x; P[i].y = y;
            sum_x += x; sum_y += y;
        }
        int m = ConvexHull(P,n,ch);
        for(int i = 0;i< m;i++)
        {
            line(ch[i],ch[(i+1)%m],A,B,C);
            sum_line = min(sum_line,fabs(A*sum_x+B*sum_y+n*C)/sqrt(A*A+B*B));
        }
        if(n == 1) sum_line = 0;//一个点无法产生直线，特别处理
        printf("Case #%d: %.3lf\n",Case,sum_line/n);
    }
    return 0;
}