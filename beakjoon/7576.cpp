#include<iostream>
#include<queue>

using namespace std;
int box[1001][1001]={0,};
bool check[1001][1001]={0,};

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

typedef struct pos{
	int x, y, depth;
}pos;
int main(void)
{
	int N,M;
	cin >> M >> N;
	pos p;
	queue<pos> q;
	for(int i=1;i<=N;i++)
		for(int j=1; j<=M; j++)
		{
			cin >> box[i][j];
			check[i][j] = true;
			if(box[i][j]!=0)
				check[i][j] = false;
			if(box[i][j] == 1)
			{
				p.x = j;
				p.y = i;
				p.depth = 0;
				q.push(p);
			}
		}
	pos new_p;
	
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{	
			if(box[p.y+dy[i]][p.x+dx[i]]==0 && check[p.y+dy[i]][p.x+dx[i]] ==true)
			{	
				box[p.y+dy[i]][p.x+dx[i]] = 1;
				new_p.x = p.x+dx[i];
				new_p.y = p.y+dy[i];
				new_p.depth = p.depth+1;
				q.push(new_p);
			}
		}
	}
	for(int i=1; i<=N;i++)
		for(int j=1; j<=M; j++)
		{
			if(box[i][j] == 0)
			{
				cout << "-1" << endl;
				return 0;
			}
		}
			
	cout << new_p.depth << endl;
	return 0;
}

