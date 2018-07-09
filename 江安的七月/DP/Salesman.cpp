//:page 93
// ���⣺��һ��n���������ͼ����һ������L����������Ҫ�����޸�ʹ��L������������������ͬ���߶�Ӧͼ���������ڽ�㡣
// ˼·��dp��dp[i][j]��ʾ״̬Ϊ����i���һ������Ϊj�������Ҫ�������޸Ĵ�������ô״̬ת�Ʒ��̺ܺ��Ƴ�Ϊ��
// dp[i][k] = min(dp[i][k], dp[i - 1][j] + (l[i] != k))

#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>

using namespace std;

const int maxn = 205;
const int INF = 0x3f3f3f3f;

int dp[maxn][maxn]; //dp[i][j] ��ʾ��A[i]��Ϊj��ʱ��ʹ����ǰi�������������С�޸Ĵ���--from TK
bool graph[maxn][maxn]; //�ڽӾ���
int L[maxn]; //����

int n,m,k;

int solve()
{
	for(int i = 1;i <= n;i++) dp[1][i] = 1;//�ӵ�һ�����Ϊ�����㶼��Ҫ1��
	dp[1][L[1]] = 0; //�Լ����Լ����û�
	
	for(int i = 2;i<= k;i++) //��������
	{
		for(int j = 1;j<=n;j++) //�����������п��ܵĵ�
		{
			dp[i][j] = INF;
			for(int v = 1;v <= n;v++)//�������е�---������j���� �ĵ�
			{
				if(graph[v][j])//�����ͨ������ѡ�1.�Լ���ͬ��2.���Լ���ͬ
				{
					dp[i][j] = min(dp[i][j],dp[i-1][v]+(j!=L[i]));//��ͬ���ظı�+0����ͬ�ı�+1
				}
			}
		}
	}
	
	int ans = INF;
	for(int i = 1;i <= n;i++) ans = min(ans,dp[k][i]);//�ҵ���С���Ǹ�
	return ans;
}

int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		//����ϴε�����
		memset(dp,0,sizeof(dp));
		memset(graph,0,sizeof(graph));
		memset(L,0,sizeof(L));
		//��������
		scanf("%d%d",&n,&m);
		for(int i = 0;i < m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			graph[a][b] = graph[b][a] = true; //��ʼ���ڽ�ͼ
		}
		for(int i = 1;i <= n;i++) graph[i][i] = true;//�Լ����Լ�Ҳ������
		scanf("%d",&k);
		for(int i = 1;i <= k;i++) scanf("%d",&L[i]);
		printf("%d\n",solve());
	}
	return 0;
}

