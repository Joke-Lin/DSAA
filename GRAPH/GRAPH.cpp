//GRAPH -- no direction

#include<stdio.h>

#define max 10

typedef struct
{
	int Vnum,Enum;            //��ͱ� 
//	int point[max];           //����Ϣ Ĭ����Ϊ1 2 3 4 .... 
	int connection[max][max]; //�໥��ϵ 
}GRAPH;

void creatgraph(GRAPH *p)
{
	printf("������ͼ�ĵ�ͱ���: ");
	scanf("%d%d",&p->Vnum,&p->Enum);
	printf("����������Ĭ��Ϊ1->Vnum\n");
	while(1)
	{
		if(p->Vnum<max) break;
		else
		{
			printf("����ĵ�������,����������\n");
			scanf("%d",&p->Vnum);
		}
	}
	for(int i = 0;i < p->Vnum;i++)
	{
		for(int j = 0;j < p->Vnum;j++) p->connection[i][j]=0;
	}
	printf("����������֮��ı�:\n\n");
	for(int i = 0;i < p->Enum;i++)
	{
		int start,end,weight;
		printf("���������%d����\n",i+1);
		scanf("%d%d%d",&start,&end,&weight);
		p->connection[start-1][end-1] = weight;
		p->connection[end-1][start-1] = weight;//��������ͼ�ĶԳ��� 
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
