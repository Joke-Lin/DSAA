//GRAPH -- no direction
//using the way of Dijkstra
//此处节点默认1，2，3，4...若需要变成地面自行更改 
#include<stdio.h>

#define max 10         //最大地点数 
#define MAX 9999       //表示两个地点之间不能通 
int book[max] = {0};

typedef struct
{
	int Vnum,Enum;            //点和边 
	int connection[max][max]; //相互关系 
	int dis[max];
}GRAPH;

void CreatGraph(GRAPH *p)
{
	printf("请输入图的点和边数: ");
	scanf("%d%d",&p->Vnum,&p->Enum);
//	for(int i = 1;i<=p->Vnum;i++) p->dis[i] = 0;
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
		}
	}
	printf("请输入两点之间的边:\n\n");
	for(int i = 1;i <= p->Enum;i++)
	{
		int start,end,weight;
		printf("正在输入第%d条边\n",i);
		scanf("%d%d%d",&start,&end,&weight);
		p->connection[start][end] = weight;
	}
	for(int i = 1;i <= p->Vnum;i++)
	{
		p->dis[i]=p->connection[1][i];
	}
	book[1] = 1;
} 

void SearchTheway(GRAPH *p)
{
	int min;
	int index = 1;
	for(int i = 1;i <= p->Vnum-1;i++)
	{
		min = MAX;
		for(int j = 1;j <= p->Vnum;j++)
		{
			if(book[j]==0&&min>p->dis[j]) 
			{
				min = p->dis[i];
				index = j;
			}
		}
		book[index] = 1;
		for(int k = 1;k <= p->Vnum;k++)
		{
			if(p->connection[index][k]<MAX)
			{
				if(p->dis[k]>p->dis[index]+p->connection[index][k])
				{
					p->dis[k] = p->dis[index]+p->connection[index][k];
				}
			}
		}
	}
	for(int i = 1;i <= p->Vnum;i++)
	{
        printf("1号顶点到%d号顶点的最短距离为------>%d\n\n",i,p->dis[i]);
    }
}

int main()
{
	GRAPH graph;
	GRAPH *p = &graph;
	CreatGraph(p);
	SearchTheway(p);
	return 0;
} 
