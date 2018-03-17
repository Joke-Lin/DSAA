//GRAPH -- no direction
//using the way of Floyd  O(n^3)

#include<stdio.h>

#define max 10
#define MAX 9999

typedef struct
{
	int Vnum,Enum;            //点和边 
//	int point[max];           //点信息 默认先为1 2 3 4 .... 
	int connection[max][max]; //相互关系 
}GRAPH;

void CreatGraph(GRAPH *p)
{
	printf("请输入图的点和边数: ");
	scanf("%d%d",&p->Vnum,&p->Enum);
	printf("点名字暂且默认为1->Vnum\n");
	while(1)
	{
		if(p->Vnum<max) break;
		else
		{
			printf("输入的点数过大,请重新输入\n");
			scanf("%d",&p->Vnum);
		}
	}
	for(int i = 0;i < p->Vnum;i++)
	{
		for(int j = 0;j < p->Vnum;j++) 
		{
			if(i==j) p->connection[i][j]=0;
			else p->connection[i][j]=MAX;
		}
	}
	printf("请输入两点之间的边:\n\n");
	for(int i = 0;i < p->Enum;i++)
	{
		int start,end,weight;
		printf("正在输入第%d条边\n",i+1);
		scanf("%d%d%d",&start,&end,&weight);
		p->connection[start-1][end-1] = weight;
		p->connection[end-1][start-1] = weight;//保持无向图的对称性 
	}
} 

void SearchTheway(GRAPH *p)
{
	int k,i,j;
	for(k = 0;k < p->Vnum;k++)
	{
		for(i = 0;i < p->Vnum;i++)
		{
			for(j = 0;j < p->Vnum;j++)
			{
				if(p->connection[i][j]>p->connection[i][k]+p->connection[k][j]&&p->connection[i][k]<MAX&&p->connection[k][j]<MAX)
				p->connection[i][j] =  p->connection[i][k]+p->connection[k][j];
			}
		}
	}
}

void PrintGraph(GRAPH *p)
{
	printf("\t");
	for(int i = 0;i < p->Vnum;i++) printf("\t%d",i+1);
	printf("\n\n");
	for(int i = 0;i < p->Vnum;i++)
	{
		for(int j = 0;j < p->Vnum+1;j++)
		{
			if(j==0) printf("\t%d",i+1);
			else
			{
				if(p->connection[i][j-1]==MAX)  printf("\t∞");
				else printf("\t%d",p->connection[i][j-1]);
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
	PrintGraph(p);
	printf("the shortest is that:\n\n");
	SearchTheway(p);
	PrintGraph(p);
	return 0;
} 
