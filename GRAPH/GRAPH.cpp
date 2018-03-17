//GRAPH -- no direction
//using the way of Floyd  O(n^3)
//�˴��ڵ�Ĭ��1��2��3��4...����Ҫ��ɵ������и��� 
#include<stdio.h>

#define max 10         //���ص��� 
#define MAX 9999       //��ʾ�����ص�֮�䲻��ͨ 
#define none -1        //·����ͨ�� 

typedef struct
{
	int Vnum,Enum;            //��ͱ� 
	int connection[max][max]; //�໥��ϵ 
	int path[max][max];       //���·���������⣬ÿ��Ԫ�ش��������һ��Ԫ�� 
}GRAPH;

void CreatGraph(GRAPH *p)
{
	printf("������ͼ�ĵ�ͱ���: ");
	scanf("%d%d",&p->Vnum,&p->Enum);
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
			p->path[i][j] = none;
		}
	}
	printf("����������֮��ı�:\n\n");
	for(int i = 1;i <= p->Enum;i++)
	{
		int start,end,weight;
		printf("���������%d����\n",i);
		scanf("%d%d%d",&start,&end,&weight);
		p->connection[start][end] = weight;
		p->connection[end][start] = weight;//��������ͼ�ĶԳ��� 
		
		/*��ʼ��·��*/
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
	printf("������������Ҫ��ѯ�Ŀ�ʼ������㣨EOF������:\n");
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
		printf("���·��Ϊ��\n\n");
		for(int j = i;j >= 0;j--)
		{
			printf("%d",Fpath[j]);
			if(j!=0) printf("-->");
		}
		printf("����Ϊ��%d",p->connection[start][end]);
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
				if(p->connection[i][j]==MAX)  printf("\t��");
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
	printf("���ͼΪ��\n\n");
	PrintGraph(p);
	SearchTheway(p);
	printf("Ѱ��֮���ͼΪ��\n\n");
	PrintGraph(p);
	printf("����·��ͼΪ��\n\n");
	PrintPath(p);
	PrintFinPath(p);
	return 0;
} 
