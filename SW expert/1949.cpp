#include<iostream>

using namespace std;

int map[8][8]={0,};
int N,K;
int max_num;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int max_height();
void DFS(int y, int x, int depth);

int main(void)
{
	int T;
	int max_h;
	cin >> T;
	for(int i=0; i<T; i++)
	{	
		max_num = 0;
		cin >> N >> K;
		for(int j=0; j<N; j++)
			for(int k=0; k<N;k++)
			{
				cin >> map[j][k];
			}
		
		
		max_h = max_height();
		for(int j=0; j<=K; j++)
		{	
			for(int k=0; k<N; k++)
				for(int l=0; l<N; l++)
				{	
					
					map[k][l] = map[k][l] - j;
					for(int q = 0; q<N ; q++)
						for(int w = 0 ; w<N; w++)
							if(map[q][w] == max_h)
							{	
								DFS(q,w, 1);
							}
					
					map[k][l] = map[k][l] + j;
				}
		}
		
		cout << "#" <<(i+1) <<" " << max_num << endl; 
	}
}
int max_height()
{
	int max_num = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(max_num < map[i][j])
				max_num = map[i][j];

	return max_num;
}
void DFS(int y, int x, int depth)
{	
	int new_x, new_y;
	for(int i=0; i<4; i++)
	{
		new_y = y + dy[i];
		new_x = x + dx[i];
		if(new_y <0 || new_x <0 || new_y >=N || new_x >=N)
			continue;
		
		
		if(map[new_y][new_x]<map[y][x])
		{	
			DFS(new_y, new_x, depth+1);
		}
	}

	if(max_num < depth)
	{
		max_num = depth;
	}
}









