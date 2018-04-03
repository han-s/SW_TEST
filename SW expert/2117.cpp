#include<iostream>
#include<queue>

bool map[20][20] = {false,};
int N,T,M,K;
int cnt;
int result = 0;

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
bool check[20][20] = {false,};
void DFS(int y, int x, int depth);
using namespace std;
int main(void)
{	
	cin >> T;
	for(int t=1; t<=T; t++)
	{	
		
		cin >> N >> M;
		cnt = 0;
		result = 0;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				cin >> map[i][j];
				if(map[i][j])
					cnt++;
			}
		
		for(int i=1; i<30; i++)
			if(cnt*M >= (i*i+(i-1)*(i-1)))
				K = i;

		cout << K << endl;
		
		for(int i=0;i<N;i++)
			for(int j=0; j<N;j++)
			{	
				for(int k=0; k<N;k++)
					for(int q=0; q<N; q++)
						check[k][q] = false;

				if(map[i][j])
				{
					cnt = 1;
				}
				else
					cnt = 0;

				check[i][j] = true;
				DFS(i,j,1);				
			}	
		cout << result << endl;
	}
}
void DFS(int y, int x, int depth)
{	
	if(K-1 < depth)
		return;
	
	int new_x;
	int new_y;
	int nnew_x;
	int nnew_y;
	int nnnew_x;
	int nnnew_y;
	for(int i=0; i<4; i++)
	{
		new_x = x + dx[i]*(depth-1);
		new_y = y + dy[i]*(depth-1);
		if(new_x <0 || new_y <0 || new_x >=N || new_y >=N)
			continue;
		
		for(int j=0; j<4; j++)
		{
			nnew_x = new_x + dx[j];
			nnew_y = new_y + dy[j];
			if(nnew_x <0 || nnew_y <0 || nnew_x >=N || nnew_y >=N)
				continue;
			if(!map[nnew_y][nnew_x] || check[nnew_y][nnew_x])
				continue;
			
			cnt++;
			check[nnew_y][nnew_x]=true;				
		}

	}
	if((depth+1)*(depth+1) + depth*depth <= cnt *M)
		result = max(result, cnt);
	DFS(y,x,depth+1);
}
	
