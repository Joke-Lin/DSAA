#include<iostream>

using namespace std;

int N,M;
char field[102][102];

void DFS(int x,int y)
{
	field[x][y]  = '.';
	for(int i = -1;i <= 1;i++)
	{
		for(int j = -1;j <= 1;j++)
		{
			int dx = x+i,dy = y+j;
			if(field[dx][dy]=='W' && dx>=0 && dx < N && dy >= 0 && dy < M) DFS(dx,dy);
		}
	}
	return;
}

int main()
{
	int count = 0;
	cin >> N >> M;
	for(int i = 0;i < N;i++)
		for(int j = 0;j < M;j++) cin >> field[i][j];
	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j < M;j++)
		{
			if(field[i][j]=='W')
			{
				DFS(i,j);
				count++;
			}
		}
	}
	cout << count;
	return 0;
}
