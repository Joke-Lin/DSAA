//GRAPH -- no direction

#include<stdio.h>

#define max 10

typedef struct
{
	int Vnum,Enum;            //点和边 
//	int point[max];           //点信息 默认先为1 2 3 4 .... 
	int connection[max][max]; //相互关系 
}GRAPH;

void creatgraph(GRAPH *p)
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
		for(int j = 0;j < p->Vnum;j++) p->connection[i][j]=0;
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

void printgraph(GRAPH *p)
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
				printf("\t%d",p->connection[i][j-1]);
			}
		}
		printf("\n\n");
	}
}

int main()
{
	GRAPH graph;
	GRAPH *p = &graph;
	creatgraph(p);
	printgraph(p);
	return 0;
} 
