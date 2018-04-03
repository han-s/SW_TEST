#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

struct pos{
	int x,y;
	int depth;
	bool broken;
	pos(int _x=0,int _y=0,int _depth=0,bool _broken=true): x(_x),y(_y), depth(_depth),broken(_broken){}
};

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
bool check[2][1001][1001];
int main(void)
{
	int N,M,i,j,k;
	int new_x,new_y;
	cin >> N >> M;
	int map[N+1][M+1];
	for(k=0; k<2; k++)
		for(i=1; i<=N; i++)
			for(j=1; j<=M; j++)
				check[k][i][j] = true;
	for(i=1; i<=N; i++)
		for(j=1; j<=M; j++)
			scanf("%1d",&map[i][j]);
	if(N==1 && M==1)
	{
		cout << "1" << endl;
		return 0;
	}
	
	queue<pos> q;
	q.push(pos(1,1,0,true));
	pos p;
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		for(i=0; i<4; i++)
		{
			new_x = p.x + dx[i];
			new_y = p.y + dy[i];
			if(new_x < 1 || new_x>M || new_y <1 || new_y >N)
				continue;

			if(new_x == M && new_y == N)
			{
				cout << p.depth+2 << endl;
				return 0;
			}

			if(map[new_y][new_x] == 0 && check[1][new_y][new_x] && p.broken)
			{
				q.push(pos(new_x,new_y,p.depth+1,p.broken));
				check[1][new_y][new_x] = false;
			}

			if(map[new_y][new_x] == 0 && check[0][new_y][new_x] && !p.broken)
			{
				q.push(pos(new_x,new_y,p.depth+1,p.broken));
				check[0][new_y][new_x] = false;
			}

			if(map[new_y][new_x] == 1 && check[0][new_y][new_x] && p.broken)
			{
				q.push(pos(new_x,new_y,p.depth+1,false));
				check[0][new_y][new_x] = false;
			}
		}
	}
	cout << "-1" << endl;
	return 0;
}
