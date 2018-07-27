//page273
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

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
double Dot(Vector A,Vector B){ return A.x*B.x+A.y*B.y;}
double Length(Vector A){ return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){ return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A,Vector B){ return A.x*B.y-A.y*B.x;}
Vector Rotate(Vector A,double rad){ return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}
double torad(double x){ return x/180.0*acos(-1);}

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
{
    Vector u = P-Q;
    double t = Cross(w,u)/Cross(v,w);
    return P+t*v;
}

double PolygonArea(Point *p,int n)//n为边的个数
{
    double area = 0;
    for(int i = 1;i < n-1;i++)//以0作为划分点
    {
        area += Cross(p[i]-p[0],p[i+1]-p[0]);
    }
    return area/2.0;
}

int ConvexHull(Point *p,int n,Point* ch)//输入点数组 个数 输出点数组 返回顶点数
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

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int T; scanf("%d",&T);
    Point P[2500],ch[2500];
    while(T--)
    {
        int n,pc = 0;
        double area1 = 0;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            double x,y,w,h,j,ang;
            scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&h,&j);
            Point o(x,y);
            ang = -torad(j);//顺时针旋转
            P[pc++] = o+Rotate(Vector(-w/2,-h/2),ang);
            P[pc++] = o+Rotate(Vector(w/2,-h/2),ang);
            P[pc++] = o+Rotate(Vector(-w/2,h/2),ang);
            P[pc++] = o+Rotate(Vector(w/2,h/2),ang);
            area1 += w*h;
        }
        int m = ConvexHull(P,pc,ch);
        double area2 = PolygonArea(ch,m);
        printf("%.1lf %%\n",area1*100/area2);
    }
    return 0;
}