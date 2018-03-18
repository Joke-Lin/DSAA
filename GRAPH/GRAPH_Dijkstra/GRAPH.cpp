//GRAPH -- no direction
//using the way of Dijkstra
//�˴��ڵ�Ĭ��1��2��3��4...����Ҫ��ɵ������и��� 
#include<stdio.h>

#define max 10         //���ص��� 
#define MAX 9999       //��ʾ�����ص�֮�䲻��ͨ 
int book[max] = {0};

typedef struct
{
	int Vnum,Enum;            //��ͱ� 
	int connection[max][max]; //�໥��ϵ 
	int dis[max];
}GRAPH;

void CreatGraph(GRAPH *p)
{
	printf("������ͼ�ĵ�ͱ���: ");
	scanf("%d%d",&p->Vnum,&p->Enum);
//	for(int i = 1;i<=p->Vnum;i++) p->dis[i] = 0;
	printf("\n����������Ĭ��Ϊ1->Vnum��ʽΪ1-->2-->3...\n\n");
	while(1)
	{
		if(p->Vnum<max) break;
		else
		{
			printf("����ĵ�������,����������\n");
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
	printf("����������֮��ı�:\n\n");
	for(int i = 1;i <= p->Enum;i++)
	{
		int start,end,weight;
		printf("���������%d����\n",i);
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
        printf("1�Ŷ��㵽%d�Ŷ������̾���Ϊ------>%d\n\n",i,p->dis[i]);
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
