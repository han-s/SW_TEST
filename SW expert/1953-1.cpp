#include<iostream>
#include<queue>

using namespace std;

int map[50][50];
bool check[50][50];
int total = 0;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int T,N,M,R,C,L;
void DFS(int y, int x, int length);

struct pos{
	int x,y,depth;
	pos(int _x=0,int _y=0, int _depth=0): x(_x),y(_y),depth(_depth){}
};

bool connect[4][8] = {{false,true, true, false, false, true, true, false}, {false, true, false, true, true, true, false, false}, {false, true, true, false, true,false, false, true}, {false,true,false,true,false,false,true,true}};

bool connect2[8][4] = {{false,false,false,false}, {true,true,true,true},{true, false, true, false}, {false, true,false, true}, {true,false,false,true}, {false,false,true,true},{false,true,true,false}, {true,true,false,false}};
int main(void)
{
	cin >> T;
	queue<pos> q;
	pos p;
	for(int t=0; t<T; t++)
	{
		cin >> N >> M >> R >> C >> L;
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
			{
				cin >> map[i][j];
				check[i][j] = false;
			}
		q.push(pos(C,R,1));
		total = 0;
		check[R][C] = true;

		while(!q.empty())
		{
			p = q.front();
			q.pop();
			
			total++;
		
			if(p.depth == L)
				continue;

			int new_y =0;
			int new_x =0;
			
			for(int i=1; i<=7; i++)
			{
				if(map[p.y][p.x] == i)
				{
					for(int j=0; j<4; j++)
					{
						if(connect2[i][j])
						{
							new_y = p.y + dy[j];
							new_x = p.x + dx[j];
							if(new_y <0 || new_x < 0 || new_y >=N || new_x >=M)
								continue;

							for(int k=1; k<=7; k++)
							{
								if( !check[new_y][new_x] && connect[j][k] && map[new_y][new_x] == k)
								{
									check[new_y][new_x] = true;
									q.push(pos(new_x,new_y,p.depth+1));
								}
							}
						}
					}
				}
			}
		}	
	cout << "#" <<t+1 <<" " << total<< endl;
	}
}


