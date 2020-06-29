//https://blog.csdn.net/freezhanacmore/article/details/876741311
//POJ 1182

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 50000+10;

int father[maxn];//存其父节点
int r[maxn];//存储与其父节点的关系

int find(int x)//找父节点并且路径压缩
{
	if(x == father[x]) return x;
	int t = father[x];
	father[x] = find(father[x]);//更新父节点
	r[x] = (r[x]+r[t])%3;//更新与新的父节点的关系，回溯由子节点与原父节点的关系和父节点与根节点的关系找子节点与根节点的关系
	return father[x];
}

int Union(int cmd,int x,int y)//判断是假话还是真话,传入的cmd==2
{
	int father_x = find(x);
	int father_y = find(y);
	
	father[father_y] = father_x;//合并树 注意：被 x 吃，所以以 x 的根为父
	r[father_y] = (r[x]-r[y]+3+(cmd-1))%3;//合并后也需要更新状态
	
	return 0;
}

int main()
{
	int n,m;//动物个数和下面的命令数
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		father[i] = i;
		r[i] = 0;//自己是自己的父节点
	}
	int ans = 0;
	for(int i = 0;i < m;i++)
	{
		int a,b,cmd;
		scanf("%d%d%d",&cmd,&a,&b);
		if(a>n || b>n || (cmd == 2 && a==b)) ans++;
		else if(find(a) == find(b))//如果已经有关系了，即前面的话默认是真
		{
			if(cmd == 1 && r[a]!=r[b]) ans++;
			if(cmd == 2 && (r[a]+1)%3 != r[b]) ans++;
		}
		else  Union(cmd,a,b);//否则建立新的关系
	}
	printf("%d",ans);
	return 0;
}