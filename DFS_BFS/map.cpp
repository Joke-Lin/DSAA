/*给定一个大小为N，M的迷宫，求出起点到终点的最小步数
因为是算最小步数
可以采用BFS，按每一步所能到达的范围来算
列出同一个步数下的可以到达的范围                  */

#include<iostream>
#include<queue>


using namespace std;

typedef pair<int,int> P; //每个点的坐标 x = first y = second
const int INF = 1000000;

int N,M,startx,starty,endx,endy;
char map[102][102];		 //存放地图
int Distance[102][102] = {INF};  //存放点到起点的距离

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};  //四个方向

int BFS()
{
	for(int i = 0;i < N;i ++)
		for(int j = 0;j < M;j++) Distance[i][j] = INF; //初始化距离，设置为极大
	queue<P> que;
	que.push(P(startx,starty));
	Distance[startx][starty] = 0;       //设置起点
	while(que.size())               //如果循环到队列长度为0，代表走到尽头
	{
		P p = que.front();
		que.pop();         //取出最前端
		if(p.first == endx && p.second == endy) break; //遇到终点退出循环
		for(int i = 0;i < 4;i++)   //循环四个方向
		{
			int Dx = p.first + dx[i];
			int Dy = p.second + dy[i];
			if(Dx >= 0&&Dx < N && Dy>=0&&Dy < M && map[Dx][Dy] != '#'&&Distance[Dx][Dy]==INF)
			{
				que.push(P(Dx,Dy));
				Distance[Dx][Dy] = Distance[p.first][p.second] + 1;
			}
		}
	}
	return Distance[endx][endy];
}

int main()
{
	//import
	cin >> N >> M ;
	for(int i = 0;i < N;i ++)
		for(int j = 0;j < M;j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 'S')
			{
				startx = i;
				starty = j;
			}
			if(map[i][j] =='G')
			{
				endx = i;
				endy = j;
			}
		}
	cout << BFS();
	return 0;
}
