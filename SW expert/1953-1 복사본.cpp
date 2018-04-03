#include<iostream>

using namespace std;

int map[50][50];
bool check[50][50];
int total = 0;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int T,N,M,R,C,L;
void DFS(int y, int x, int length);

bool connect[4][8] = {{false,true, true, false, false, true, true, false}, {false, true, false, true, true, true, false, false}, {false, true, true, false, true,false, false, true}, {false,true,false,true,false,false,true,true}};

bool connect2[8][4] = {{false,false,false,false}, {true,true,true,true},{true, false, true, false}, {false, true,false, true}, {true,false,false,true}, {false,false,true,true},{false,true,true,false}, {true,true,false,false}};
int main(void)
{
	cin >> T;
	for(int t=0; t<T; t++)
	{
		cin >> N >> M >> R >> C >> L;
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
			{
				cin >> map[i][j];
				check[i][j] = false;
			}
		total = 0;
		DFS(R,C,1);
		cout <<"#" << t+1 << " " << total << endl;
	}
}
 void DFS(int y, int x, int length)
{
	if(length > L)
		return;
	if(!check[y][x])
	{
		cout << " x : " << x <<" "<< "y : " << y << endl;
		total++;
		check[y][x] = true;
	}

	int new_y =0;
	int new_x =0;
	int value;
	
	for(int i=1; i<=7; i++)
	{
		if(map[y][x] == i)
		{
			for(int j=0; j<4; j++)
			{
				if(connect2[i][j])
				{
					new_y = y + dy[j];
					new_x = x + dx[j];
					if(new_y <0 || new_x < 0 || new_y >=N || new_x >=M)
						continue;

					for(int k=1; k<=7; k++)
					{
						if( connect[j][k] && map[new_y][new_x] == k)
							DFS(new_y,new_x,length+1);
					}
				}
			}
		}
	}
							
}


