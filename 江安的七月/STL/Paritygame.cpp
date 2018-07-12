//https://blog.csdn.net/u013480600/article/details/21128299 很好的解释（离散化）
//https://blog.csdn.net/dominating413421391/article/details/47103281 
//https://blog.csdn.net/dominating413421391/article/details/47100515 类似题POJ1962
//带权并查集+离散化+合理的路径压缩
//用奇+奇的偶的思想来做，特别的相减也是一样的

#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<stdlib.h>

using namespace std;

const int maxn = 2*5e3+10;//因为串的长度特别长，不能存
int len,m;//长度和命令     //但是我们发现，数据只有5e3，即有效的节点只有2*5e3个
char cmd[10];            //所以我们只存代表区间的端点
int father[maxn],to_rel[maxn]; //存父节点，和i点与其父节点的奇偶
map<int,int> point;

void init();//初始化
int find(int);//找父节点
bool Uion(int,int,int);//合并两个节点，返回值代表是否冲突

int main()
{
    // freopen("./in.txt","r",stdin);
    int index = 0,ans = 0,flag = 0;//离散化节点，ans代表错误的行
    int odd_even; //奇偶位
    init();//初始化
    scanf("%d%d",&len,&m);
    for(int i = 0;i < m;i++)
    {
        int a,b; scanf("%d%d%s",&a,&b,&cmd);
       // printf("%d %d %s\n",a,b,cmd);
        if(flag) continue;
        a--;//我们将区间化为(a,b]半开半闭区间，好让区间首位相接 ps(1,2)->(0,2] (3,4)->(2,4]可以由1链接到2->4
        if(point.find(a) == point.end()) point[a] = index++; //如果没有找到，说明是一个新的点
        if(point.find(b) == point.end()) point[b] = index++;
        int x = point[a], y = point[b]; //获取离散化之后的下标
        if(cmd[0] == 'e')  odd_even = 0;//偶数
        else odd_even = 1;
        if(!Uion(x,y,odd_even)) flag = 1;//此处与前面矛盾
        else ans++;
    }
    printf("%d\n",ans);
    // freopen("CON","r",stdin);
    // system("pause");
    return 0;
}

void init(){
    for(int i = 0;i < maxn;i++){
        father[i] = i;
        to_rel[i] = 0;//开始全部不确定所以全部都初始化为0
    }
}

int find(int x)  //寻找根节点并且路径压缩+奇偶数组更新,每次都是在Uion中更新
{
    if(x == father[x]) return x;
    else{
        int rel = father[x];//x的原先根节点
        father[x] = find(father[x]);//必须在此位置，不能放到最后，从里到外一层层更新
        to_rel[x] = (to_rel[x]+to_rel[rel])%2;//奇数+奇数=偶数 0是偶数
        return father[x];
    }
}

bool Uion(int x,int y,int d)
{
    int fx = find(x);//找到与x同集合的根
    int fy = find(y);//同上
    if(fx == fy) //说明在一个集合中，可以判断命令是否正确
    {
        if((to_rel[x]+to_rel[y])%2 == d) return true;
        //x到y的奇偶性=x->root+y->root%2画图就可以理解了
        else return false;
    }
    else{//说明无法判断，更新数据
        father[fx] = fy;//更新父节点 ps:fx的子节点对fx的距离在下次find的时候更新
        to_rel[fx] = (to_rel[x]+to_rel[y]+d)%2;//画图以便理解，to_rel[x/y]都是x,y到自己根的距离
    }
    return true;
}