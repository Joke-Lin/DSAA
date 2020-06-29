// Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors.
//
// Given a diagram of Farmer John's field, determine how many ponds he has.
// Input
//
// * Line 1: Two space-separated integers: N and M
//
// * Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.
// Output
//
// * Line 1: The number of ponds in Farmer John's field.
// Sample Input
//
// 10 12
// W........WW.
// .WWW.....WWW
// ....WW...WW.
// .........WW.
// .........W..
// ..W......W..
// .W.W.....WW.
// W.W.W.....W.
// .W.W......W.
// ..W.......W.
// Sample Output
//
// 3

#include<iostream>

#define MAX 101

char Field[MAX][MAX];

int N,M;
void dfs(int x,int y)
{
	Field[x][y] = '.';
	for(int dx = -1;dx <= 1;dx++)
		for(int dy = -1;dy <= 1;dy++)
		{
			int nx = x+dx;
			int ny = y+dy;
			if(0 <= nx && nx < N && 0 <= ny && ny < M && Field[nx][ny] == 'W') dfs(nx,ny);
		}
	return;
}

int main()
{
	std::cin >> N >> M;
	for(int i = 0;i < N;i++)
		for(int j = 0;j < M;j++) std::cin >> Field[i][j];
	int res = 0;
	for(int i = 0;i < N;i++)
		for(int j = 0;j < M;j++)
		{
			if(Field[i][j] == 'W')
			{
				dfs(i,j);
				res++;
			}
		}
	std::cout << res << '\n';
	return 0;
}
