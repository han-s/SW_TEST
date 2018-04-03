#include<iostream>

int dice[6]={0,};
int order[1001] = {5,};
int temp_dice[4]={0,};

int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,-1,1};
using namespace std;

int main(void)
{
	int N,M,x,y,k;
	cin >> N >> M >> x >> y >> k;
	int map[N][M];
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> map[i][j];

	for(int i=1; i<=k; i++)
		cin >> order[i];

	for(int i=1; i<=k; i++)
	{	
		if((x+dy[order[i]]) == N || (y+dx[order[i]]) == M)
			continue;
		if((x+dy[order[i]]) <0 || (y+dx[order[i]]) <0)
			continue;
		
		x += dy[order[i]];
		y += dx[order[i]];

		if(order[i] == 1)
		{
			temp_dice[0] = dice[2];
			temp_dice[1] = dice[3];
			temp_dice[2] = dice[5];
			temp_dice[3] = dice[1];
		}
		
		if(order[i] == 2)
		{
			temp_dice[0] = dice[5];
			temp_dice[1] = dice[1];
			temp_dice[2] = dice[2];
			temp_dice[3] = dice[3];
		}

		if(order[i] == 3)
		{
			temp_dice[0] = dice[5];
			temp_dice[1] = dice[0];
			temp_dice[2] = dice[2];
			temp_dice[3] = dice[4];
		}

		if(order[i] == 4)
		{
			temp_dice[0] = dice[2];
			temp_dice[1] = dice[4];
			temp_dice[2] = dice[5];
			temp_dice[3] = dice[0];
		}

		if(order[i] == 1 || order[i] == 2)
		{
			dice[1] = temp_dice[0];
			dice[2] = temp_dice[1];
			dice[3] = temp_dice[2];
			dice[5] = temp_dice[3];
		}
		else
		{
			dice[0] = temp_dice[0];
			dice[2] = temp_dice[1];
			dice[4] = temp_dice[2];
			dice[5] = temp_dice[3];
		}
		
		if(map[x][y] == 0)
			map[x][y] = dice[2];
		else
		{
			dice[2] = map[x][y];
			map[x][y] = 0;
		}
		
		cout << dice[5] << endl;
	}
}
		

	







