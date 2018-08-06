// 一群小偷到一座小区里偷东西，这座小区正好是一条直线排开，房屋编号为1-n，偷完物品后小偷就要迅速沿着房屋编号增大的方向一步一房逃离现场。为了防止小偷逃跑，小区里面有m个富豪组织在房屋外安置陷阱。每个富豪会安置一组陷阱，每组陷阱都会恰好铺满一个l号房屋到一个r号房间[l,r]，小偷在该陷阱上每走一步会收到k点伤害，因此同一间房屋外可能会有多个陷阱重叠，每个陷阱都会对经过的小偷造成伤害。一共有x个小偷，每个小偷一个开始会在偷盗房间的编号p，并且有一个初始生命值h，询问每个偷盗逃跑的小偷能否在h降低到小于等于0之前逃离这片小区。

// Input
// 输入包含多个测试用例，输入由n=0终止。
// 每个样例首先输入一个整数n（0<n<=110000)表示小区里房间数目。然后第二行输入一个是整数m（0<m<=110000）表示陷阱组数。接下来的m行,每行包含三个数，l，r，k（1<=l<=r<=n，0<k<=1500)，表示陷阱安放位置[l，r]和小偷每在上面走一步造成的伤害k(小偷刚踏上陷阱也会受到伤害)
// 接下来是一个整数x（0<x<=110000)，即小偷数量。以下x行每行都会输入两个整数h、p（0<h<= 10^17,1<=pi<=n），第i行表示第i个小偷拥有的生命值和偷盗房间的编号。

// Output
// 每组样例输出一行活着的小偷数

// Sample Input
// 3
// 1
// 1 3 1
// 2
// 1 3
// 2 3
// 8
// 3
// 1 3 5
// 2 3 8
// 4 6 2
// 5
// 1 4
// 3 7
// 4 1
// 5 3
// 100 1
// 0

// Sample Output
// 1
// 2
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#define LOCKAL

using namespace std;
const int maxn = 110000+10;

int load[maxn];
int cost_sum[maxn];

int main()
{
#ifdef LOCKAL
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
#endif
    int n;
    while(scanf("%d",&n),n)
    {
        memset(load,0,sizeof(load));
        memset(cost_sum,0,sizeof(cost_sum));
        int m; scanf("%d",&m);
        for(int i = 0;i < m;i++)
        {
            int l,r,cost;scanf("%d%d%d",&l,&r,&cost);
            for(int j = l;j <= r;j++) load[j] += cost;
        }
        for(int i = n;i >= 1;i--) cost_sum[i] = cost_sum[i+1]+load[i];
        int k,x,hp; scanf("%d",&k);
        int ans = 0;
        while(k--)
        {
            scanf("%d%d",&hp,&x);
            // printf("cost:%d : %d %d\n",x,cost_sum[x],hp);
            if(hp > cost_sum[x]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}