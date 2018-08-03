//HDU1007
//分治法
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;
const int maxn = 1e5+10;
const double INF = 1e20;
struct Point
{
    double x,y;
    void set(int a,int b){ x = a;y = b;}
};
int n;
Point points[maxn];
Point temp_point[maxn];

bool cmp_xy(const Point& a,const Point& b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

class cmp  //伪函数
{
    public:
        bool operator()(const Point& a,const Point& b){ return cmp_xy(a,b);}
};

bool cmp_y(const Point& a,const Point& b)
{
    return a.y < b.y;
}

double cal_dis(const Point& a,const Point& b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double closet_pair(int l,int r);

int main()
{
    // freopen("../江安的七月/second_exam/in.txt","r",stdin);
    // freopen("../江安的七月/second_exam/out.txt","w",stdout);
    while(scanf("%d",&n),n)
    {
        set<Point,cmp> judge_two;
        bool flag = false;
        for(int i = 0;i < n;i++)//提前判断是否有相同的点 有的话直接返回0
        {
            scanf("%lf%lf",&points[i].x,&points[i].y);
            if(judge_two.find(points[i]) != judge_two.end()) flag = true;
            else judge_two.insert(points[i]);
        }
        if(flag) printf("0.00\n");
        else {
            sort(points,points+n,cmp_xy);
            printf("%.2lf\n",closet_pair(0,n-1)/2.0);
        }
    }
    return 0;
}

double closet_pair(int l,int r)
{
    double d = INF;
    if(l==r) return d;//自己一个点没有距离
    if(l+1 == r) return cal_dis(points[l],points[r]);//只有两个点此时
    int mid = (l+r) / 2;
    double d1 = closet_pair(l,mid);
    double d2 = closet_pair(mid+1,r);
    d = min(d1,d2);
    int k = 0;
    //对x压缩
    for(int i = l;i <= r;i++)
    {
        if(fabs(points[i].x - points[mid].x) <= d) temp_point[k++] = points[i];
    }
    //排序之后对y压缩
    sort(temp_point,temp_point+k,cmp_y);
    for(int i = 0;i < k;i++)
    {
        for(int j = i+1;j < k && temp_point[j].y - temp_point[i].y < d;j++)//枚举所有情况
        {
            d = min(d,cal_dis(temp_point[i],temp_point[j]));
        }
    }
    return d;
}