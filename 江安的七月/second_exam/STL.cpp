// Glory认识很多小姐姐，这些小姐姐之间的关联形成了一棵树（包含n个小姐姐和n-1个关联），Glory的小姐姐太多了，读完她们的名字需要一天一夜，于是他把认识的小姐姐标记为1到n。
// 这些小姐姐互相可能认识也可能不认识（认识标记为0，不认识标记为1），Glory突然想知道每个小姐姐i∈[1 ，n]所认识的小姐姐的数量（包含小姐姐i本身），但是他又要去认识更多的小姐姐，于是他把这个任务交给你。
// 注意：认识具有传递性，即A与B认识，B与C认识时，A与C也认识。
// Input
// 第一行输入数字T，表示有T个测试用例。
// 对于每个测试用例，第一行是数字n，表示小姐姐的数量。
// 接下来的n-1行，每行包含三个数字u，v，w，表示小姐姐u和小姐姐v之间存在关联，且w=0时表示互相认识，w=1时互相不认识。
// T≤50,n≤10^5,u,v∈[1,n],w∈[0,1]
// Output
// 对于每个测试用例，输出每个小姐姐所认识的小姐姐的数量的异或和。
// Sample Input
// 1
// 3
// 1 2 0
// 2 3 1
// Sample Output
// 1

// 在这个样例里
// 小姐姐1认识1 和 2
// 小姐姐2认识2 和 1
// 小姐姐3只认识3
// 所以ans=ansP1 xor ansP2 xor ansP3=2 xor 2 xor 1
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 1e5+10;

int root[maxn],num[maxn];

int find(int x)
{
    return x==root[x]? x : root[x] = find(root[x]);
}

void Uion(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy)
    {
        root[fx] = fy;
        num[fy] += num[fx];
    }
}

int main()
{
    freopen("./in.txt","r",stdin);
    freopen("./out.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) root[i] = i,num[i] = 1;
        for(int i = 0;i < n-1;i++)
        {
            int x,y,flag;
            scanf("%d%d%d",&x,&y,&flag);
            if(!flag) Uion(x,y);
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            int f = find(i);
            ans ^= num[f];
        }
        printf("%d\n",ans);
    }
    return 0; 
}