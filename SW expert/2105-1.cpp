#include<iostream>

using namespace std;

int dx[4] = { -1,1,1,-1};
int dy[4] = {1,1,-1,-1};
int cnt[2] = {0,};
int T,N;
int map[20][20];
bool check[10] = {false,};
bool check2[10] = P{false,};
int main(void)
{
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		cin >> N;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				cin >> map[i][j];

		for(int i=0;i<N-2; i++)
			for(int j=1; j<N-1;j++)
			{	
				check[map[i][j]] = true;
				DFS(i,j,0);
				checj[map[i][j]] = false;
			}			
	}
}

void DFS(int y, int x, int dir)
{	
	
	int new_x=x, new_y=y;
	if(dir == 2)
	{
		int cnt2[2];
		cnt2[0] = cnt[0];
		cnt2[1] = cnt[1];
		
		for(i=0;i<2;i++)
		{
			while(cnt2[i]--)
			{
				new_x = new_x + dx[dir+i];
				new_y = new_y + dy[dir+i];
				if(check2[map[new_y][new_x]])
				{
					for(int j=0; j<10; j++)
						check2[j] = false;
					return;
				}
						
				if(new_x <0 || new_y <0 || new_x >=N || new_y >=N)
					return;
			}
		}
	
	}
	while(1)
	{
		new_x = new_x + dx[dir];
		new_y = new_y + dy[dir];

		if(new_x <0 || new_y <0 || new_x>=N || new_y>=N)
			break;

		if(check[new_y][new_x])				
			break;	
		
		check[new_y][new_x] = true;
		cnt[dir]++;
		DFS(new_y,new_x, dir+1);

	}

	while(--cnt[dir])
	{	
		new_x = new_x -dx[dir];
		new_y = new_y -dy[dir];
		check[new_y][new_x] = false;
	}
		
}
