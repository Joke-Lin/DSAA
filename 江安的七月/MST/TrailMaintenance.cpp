//题目大意 https://blog.csdn.net/xiao_k666/article/details/79342524
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
#define LOCKAL

using namespace std;
const int INF = 0x3f3f3f3f;
int n, v, m; //点边

struct edge
{
	int st, ed, cost;
    bool operator < (const edge& b){ return cost < b.cost;} //评测机报错。。。必须写外面。。
}edges[10000];

int father[220];

int find(int x)
{
	return x == father[x] ? x : father[x] = find(father[x]);
}

int karuskal();

int main()
{
#ifdef LOCKAL
	freopen("./in.txt", "r", stdin);
	freopen("./out.txt", "w", stdout);
#endif
	int T; scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++)
	{
		v = 0;
		scanf("%d%d", &n, &m);
		printf("Case %d:\n", kase);
		for (int i = 0; i < m; i++)
		{
			int st, ed, cost; scanf("%d%d%d", &st, &ed, &cost);
			edges[v].st = st, edges[v].ed = ed, edges[v].cost = cost;
			v++;
			sort(edges, edges + v);
			printf("%d\n", karuskal());
		}
	}
	return 0;
}

int karuskal()
{
	int judge_edge = 0;//判断是否联通
	for (int i = 1; i <= 200; i++) father[i] = i;//初始化并查集
	int res = 0;
	int k = v;//这里栽了。。。
	for (int i = 0; i < k; i++)
	{
		edge e = edges[i];
		int x = find(e.st);
		int y = find(e.ed);
		if (x == y)
		{
			edges[i] = edges[v-1];//注意
			v--;
			continue;
		}
		father[x] = y;
		res += e.cost;
		judge_edge++;
	}
	if (judge_edge != n - 1) return -1;
	return res;
}