#include<iostream>

using namespace std;

int map[50][50];
bool check[50][50];
int total=0;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int T,N,M,R,C,L;

void DFS(int y, int x, int length);
int main(void)
{
	cin >> T;
	for(int t=0; t<T;t++)
	{
		cin >> N >> M >>R >> C >> L;
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j++)
			{
				cin >> map[i][j];
				check[i][j] = false;
			}

		check[R][C] = true;
		total = 0;
		DFS(R,C,1);
		cout << total << endl;
	}
}

void DFS(int y, int x, int length)
{	
	if(length >L)
		return;

	if(map[y][x] !=0)
	{
		cout << y << " " << x << endl;
		total++;
	}
	else
		return;

	check[y][x] = true;
	int new_y=0;
	int new_x=0;
	int value;
	if(map[y][x] == 1)
	{
		for(int i=0; i<4; i++)
		{	
			cout << " aa";
			new_y = y + dy[i];
			new_x = x + dx[i];
			if(new_y < 0 || new_x <0 || new_y >=N || new_y >=M)
				continue;
			
			if(check[new_y][new_x])
				continue;
			
			cout << "bb";
			value = map[new_y][new_x];
			if(i == 0)
			{	
				if(value == 1 || value == 2 || value ==5 || value ==6)
					DFS(new_y,new_x,length+1);
			}
			else if(i==1)
			{	
				if(value == 1 || value == 3 || value ==4 || value == 5)
				{
					DFS(new_y,new_x,length+1);
			
				}
			}
			else if(i==2)
			{
				if(value == 1 || value == 2 || value ==4 || value == 7)
					DFS(new_y,new_x,length+1);
			}
			else if(i==3)
			{
				if(value == 1 || value == 3 || value ==6 || value == 7)
					DFS(new_y,new_x,length+1);
			}

		}
	}
	if(map[y][x] == 2)
	{	
		if(y+dy[0] < 0 || x + dx[0] < 0 || y + dy[0] >=N || x+ dx[0] >=M);
		else
		{
			if(!check[y+dy[0]][x+dx[0]] && map[y+dy[0]][x+dx[0]] )
				DFS(y+dy[0],x+dx[0],length+1);
		}
		if(y+dy[2] < 0 || x + dx[2] < 0 || y + dy[2] >=N || x+ dx[2] >=M);
		else
		{
			if(!check[y+dy[2]][x+dx[2]])
			DFS(y+dy[2],x+dx[2], length+1);
		}
	}
	if(map[y][x] == 3)
	{
		if(y+dy[1] < 0 || x + dx[1] < 0 || y + dy[1] >=N || x+ dx[1] >=M);
		else
		{
		if(!check[y+dy[1]][x+dx[1]])
			DFS(y+dy[1],x+dx[1],length+1);
		}
		if(y+dy[3] < 0 || x + dx[3] < 0 || y + dy[3] >=N || x+ dx[3] >=M);
		else
		{
		if(!check[y+dy[3]][x+dx[3]])
			DFS(y+dy[3],x+dx[3], length+1);

		}
	}
	if(map[y][x] == 4)
	{
		if(y+dy[0] < 0 || x + dx[0] < 0 || y + dy[0] >=N || x+ dx[0] >=M);
		else
		{
		if(!check[y+dy[0]][x+dx[0]])
			DFS(y+dy[0],x+dx[0],length+1);
		}

		if(y+dy[3] < 0 || x + dx[3] < 0 || y + dy[3] >=N || x+ dx[3] >=M);
		else
		{
		if(!check[y+dy[3]][x+dx[3]])
			DFS(y+dy[3],x+dx[3], length+1);
		}
	}
	if(map[y][x] == 5)
	{
		if(y+dy[2] < 0 || x + dx[2] < 0 || y + dy[2] >=N || x+ dx[2] >=M);
		else
		{
			if(!check[y+dy[2]][x+dx[2]])
				DFS(y+dy[2],x+dx[2],length+1);
		}

		if(y+dy[3] < 0 || x + dx[3] < 0 || y + dy[3] >=N || x+ dx[3] >=M);
		else
		{
			if(!check[y+dy[3]][x+dx[3]])
				DFS(y+dy[3],x+dx[3], length+1);
		}
	}
	if(map[y][x] == 6)
	{
		if(y+dy[1] < 0 || x + dx[1] < 0 || y + dy[1] >=N || x+ dx[1] >=M);
		else
		{
			if(!check[y+dy[1]][x+dx[1]])
				DFS(y+dy[1],x+dx[1],length+1);
		}	
		if(y+dy[2] < 0 || x + dx[2] < 0 || y + dy[2] >=N || x+ dx[2] >=M);
		else
		{	
			if(!check[y+dy[2]][x+dx[2]])
				DFS(y+dy[2],x+dx[2], length+1);
		}
	}
	if(map[y][x] == 7)
	{
		if(y+dy[0] < 0 || x + dx[0] < 0 || y + dy[0] >=N || x+ dx[0] >=M);
		else
		{
			if(!check[y+dy[0]][x+dx[0]])
				DFS(y+dy[0],x+dx[0],length+1);
		}	
		if(y+dy[1] < 0 || x + dx[1] < 0 || y + dy[1] >=N || x+ dx[1] >=M);
		else
		{
			if(!check[y+dy[1]][x+dx[1]])
				DFS(y+dy[1],x+dx[1], length+1);
		}
	}

}
