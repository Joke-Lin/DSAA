//GRAPH -- no direction
//using the way of Floyd  O(n^3)
//此处节点默认1，2，3，4...若需要变成地面自行更改 
#include<stdio.h>

#define max 10         //最大地点数 
#define MAX 9999       //表示两个地点之间不能通 
#define none -1        //路径不通处 

typedef struct
{
	int Vnum,Enum;            //点和边 
	int connection[max][max]; //相互关系 
	int path[max][max];       //解决路径保存问题，每个元素存的是其上一个元素 
}GRAPH;

void CreatGraph(GRAPH *p)
{
	printf("请输入图的点和边数: ");
	scanf("%d%d",&p->Vnum,&p->Enum);
	printf("\n点名字暂且默认为1->Vnum格式为1-->2-->3...\n\n");
	while(1)
	{
		if(p->Vnum<max) break;
		else
		{
			printf("输入的点数过大,请重新输入\n");
			scanf("%d",&p->Vnum);
		}
	}
	for(int i = 1;i <= p->Vnum;i++)
	{
		for(int j = 1;j <= p->Vnum;j++) 
		{
			if(i==j) p->connection[i][j]=0;
			else p->connection[i][j]=MAX;
			p->path[i][j] = none;
		}
	}
	printf("请输入两点之间的边:\n\n");
	for(int i = 1;i <= p->Enum;i++)
	{
		int start,end,weight;
		printf("正在输入第%d条边\n",i);
		scanf("%d%d%d",&start,&end,&weight);
		p->connection[start][end] = weight;
		p->connection[end][start] = weight;//保持无向图的对称性 
		
		/*初始化路径*/
		p->path[start][end] = start;
		p->path[end][start] =  end;
		 
	}
} 

void SearchTheway(GRAPH *p)
{
	int k,i,j;
	for(k = 1;k <= p->Vnum;k++)
	{
		for(i = 1;i <= p->Vnum;i++)
		{
			for(j = 1;j <= p->Vnum;j++)
			{
				if(p->connection[i][j]>p->connection[i][k]+p->connection[k][j]&&p->connection[i][k]<MAX&&p->connection[k][j]<MAX)
				{
					p->connection[i][j] =  p->connection[i][k]+p->connection[k][j];
					p->path[i][j] = p->path[k][j];
				}
			}
		}
	}
}

void PrintPath(GRAPH *p)
{
	printf("\t");
	for(int i = 1;i <= p->Vnum;i++) printf("\t%d",i);
	printf("\n\n");
	for(int i = 1;i <= p->Vnum;i++)
	{
		for(int j = 0;j <= p->Vnum;j++)
		{
			if(j==0) printf("\t%d",i);
			else
			{
				if(p->path[i][j]==none)  printf("\tnone");
				else printf("\t%d",p->path[i][j]);
			}
		}
		printf("\n\n");
	}
	
	
}

void PrintFinPath(GRAPH *p)
{
	int start,end;
	int Fpath[max];
	printf("请输入你所需要查询的开始与结束点（EOF结束）:\n");
	while(scanf("%d%d",&start,&end)!=EOF)
	{
		int i = 0;
		int mid = end;
		Fpath[i++] = end;
		while(p->path[start][mid]!=start)
		{
			mid = p->path[start][mid];	
			Fpath[i++] = mid;
		}
		Fpath[i] = start;
		printf("最短路线为：\n\n");
		for(int j = i;j >= 0;j--)
		{
			printf("%d",Fpath[j]);
			if(j!=0) printf("-->");
		}
		printf("距离为：%d",p->connection[start][end]);
		printf("\n\n");
	} 
}

void PrintGraph(GRAPH *p)
{
	printf("\t");
	for(int i = 1;i <= p->Vnum;i++) printf("\t%d",i);
	printf("\n\n");
	for(int i = 1;i <= p->Vnum;i++)
	{
		for(int j = 0;j <= p->Vnum;j++)
		{
			if(j==0) printf("\t%d",i);
			else
			{
				if(p->connection[i][j]==MAX)  printf("\t∞");
				else printf("\t%d",p->connection[i][j]);
			}
		}
		printf("\n\n");
	}
}

int main()
{
	GRAPH graph;
	GRAPH *p = &graph;
	CreatGraph(p);
	PrintPath(p);	
	printf("你的图为：\n\n");
	PrintGraph(p);
	SearchTheway(p);
	printf("寻找之后的图为：\n\n");
	PrintGraph(p);
	printf("最终路径图为：\n\n");
	PrintPath(p);
	PrintFinPath(p);
	return 0;
} 
