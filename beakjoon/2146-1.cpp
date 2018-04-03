#include<iostream>

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int map[101][101];
int N;
int cnt = 1;
int result = 300;
void DFS(int y, int x, int num);

using namespace std;

int main(void)
{
	cin >> N;
	for(int i=0; i<=100; i++)
		for(int j=0; j<=100; j++)
			map[i][j] = 0;

	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> map[i][j];

	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
		{
			if(map[i][j] == 1)
			{	
				
				cnt++;
				DFS(i,j, cnt);
			}
		}

	int comp[cnt+1][10000][2];
	for(int i=0; i<=cnt; i++)
		for(int j=0; j<10000; j++)
		{
			comp[i][j][0] =0;
			comp[i][j][1] =0;
		}
	int cnt2=0;
	for(int z=2; z<=cnt; z++)
	{
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
			{
				for(int k=0; k<4; k++)
				{	
					if(i+dy[k] <1 || i+dy[k]>N || j+dx[k] <1 || j+dx[k]>N)
						continue;
				
					if(map[i+dy[k]][j+dx[k]] !=0)
						continue;
				
				
					if(map[i][j] == z)
					{
						comp[z][cnt2][0] = i;
						comp[z][cnt2++][1] = j;
						break;
					}
				}
			}

		cnt2=0;
	}
	
	for(int i=2; i<cnt; i++)
		for(int j=i+1; j<=cnt; j++)
		{
			for(int k=0; comp[i][k][0] != 0; k++)
				for(int z=0; comp[j][z][0] != 0; z++)
				{
						result = min(result,(abs(comp[i][k][0]-comp[j][z][0])+abs(comp[i][k][1]-comp[j][z][1])-1));
				}
		}

	cout << result << endl;

}

void DFS(int y, int x, int num)
{	
	map[y][x] = num;
	for(int i=0; i<4; i++)
	{	
		if(y+dy[i] <1 || y+dy[i]>N || x+dx[i] <1 || x+dx[i]>N)
			continue;
		
		if(map[y+dy[i]][x+dx[i]] == 1)
			DFS(y+dy[i],x+dx[i], num);
	}
}

