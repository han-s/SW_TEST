#include <iostream>
#include <queue>

using namespace std;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int check[101][101]={0,};

typedef struct pos{
	int x,y;
	int depth;
}pos;

int main(void)
{
	int N,M;
	cin >> N >> M;
	for(int i=1; i<=N; i++)
		for(int j=1 ;j<=M ; j++)
			 scanf("%1d",&check[i][j]);
	
	pos p;
	p.x = 1;
	p.y = 1;
	p.depth = 1;
	check[1][1] = 0;
	queue<pos> q;
	q.push(p);

	while(!q.empty())
	{
		pos new_pos = q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{	
			pos p;
			int new_x = new_pos.x + dx[i];
			int new_y = new_pos.y + dy[i];
			if(check[new_y][new_x] == 1)
			{	
				if(new_y == N && new_x == M)
				{
					cout << new_pos.depth+1 << endl;
					return 0;
				}
				check[new_y][new_x] = 0;
				p.x = new_x;
				p.y = new_y;
				p.depth = new_pos.depth + 1;
				q.push(p);
			}
		}
	}
	
}
