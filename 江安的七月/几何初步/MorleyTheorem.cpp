//:page 259
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>

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
double Dot(Vector A,Vector B){ return A.x*B.x+A.y*B.y;}
double Length(Vector A){ return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){ return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A,Vector B){ return A.x*B.y-A.y*B.x;}
Vector Rotate(Vector A,double rad){ return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
{
    Vector u = P-Q;
    double t = Cross(w,u)/Cross(v,w);
    return P+t*v;
}

Point Get_D(Point A,Point B,Point C)
{
    Vector v1 = C-B,v2 = B-C;
    double a1 = Angle(A-B,v1),a2 = Angle(A-C,v2);
    v1 = Rotate(v1,a1/3);
    v2 = Rotate(v2,-a2/3);//顺时针转
    return GetLineIntersection(B,v1,C,v2);
}

int main()
{
    // freopen("./in.txt","r",stdin);
    // freopen("./out.txt","w",stdout);
    int T; scanf("%d",&T);
    Point A,B,C,D,E,F;
    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
        D = Get_D(A,B,C);
        E = Get_D(B,C,A);
        F = Get_D(C,A,B);
        printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",D.x,D.y,E.x,E.y,F.x,F.y);
    }

    return 0;
}