#include<iostream>
#include<queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

typedef struct robot{
	int x,y;
	int dir;
}robot;

int main(void)
{	
	int count=0;
	int N,M,i,j;
	queue<robot> q;
	cin >> N >> M;
	int board[N+1][M+1];
	robot r;
	cin >> r.y >> r.x >> r.dir;
	
	r.x++;
	r.y++;
	for(i=1; i<=N; i++)
		for(j=1;j<=M; j++)
			cin >> board[i][j];
	q.push(r);
	while(!q.empty())
	{
		robot nr = q.front();
		q.pop();
		board[nr.y][nr.x]=3;
		count++;
		for(int i=0; i<4; i++)
		{
			nr.dir = (nr.dir+3)%4;
			if(board[nr.y+dy[nr.dir]][nr.x+dx[nr.dir]] == 0)
			{	
				nr.x = nr.x+dx[nr.dir];
				nr.y = nr.y+dy[nr.dir];
				q.push(nr);
				break;
			}
		}
		while(q.empty())
		{
			int temp_dir = (nr.dir+2)%4;
			nr.x = nr.x + dx[temp_dir];
			nr.y = nr.y + dy[temp_dir];
			
			if(board[nr.y][nr.x] == 1)
				break;
			
			for(int i=0; i<4; i++)
			{
				nr.dir = (nr.dir+3)%4;
				if(board[nr.y+dy[nr.dir]][nr.x+dx[nr.dir]] == 0)
				{
				nr.x = nr.x+dx[nr.dir];
				nr.y = nr.y+dy[nr.dir];
				q.push(nr);
				break;
				}
			}
		}
	}
	cout << count << endl;
	return 0;
}
