#include<iostream>

using namespace std;

int dx[5] = {0, 0,0,-1,1};
int dy[5] = {0, -1,1,0,0};
int result =0;
int mic[1001]= {0,};
int map[100][100][5]={0,};
int T,N,K,M;
int check[5] = {false,};
bool check2[100][100][5]={false,};
void DFS(int depth);

int main(void)
{
	cin >> T;
	int dir,x,y;
	for(int t=1; t<=T; t++)
	{
		cin >> N >> M >> K;
		for(int i=1; i<=K ;i++)
		{
			cin >> y >> x >> mic[i] >> dir;
			map[y][x][dir]=i;
		}
		/*
		for(int k=1; k<5; k++)
		{
			cout << endl;

			for(int i=0; i<N; i++)
			{
				cout << endl;

				for(int j=0; j<N; j++)
					cout << map[i][j][k] << " " ;
			}
		}*/
		DFS(1);
		for(int i=1; i<=K; i++)
		{
			result += mic[i];
		
		}
		cout << result<< endl;
	}


}

void DFS(int depth)
{	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			for(int k=1; k<5; k++)
				check2[i][j][k] = false;
		for(int k=1; k<5; k++)
		{
			cout << endl;

			for(int i=0; i<N; i++)
			{
				cout << endl;

				for(int j=0; j<N; j++)
					cout << map[i][j][k] << " " ;
			}
		}
		
	if(depth > M)
		return;
		
	int new_x;
	int new_y;
	int q;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			for(int k=1; k<5; k++)
			{
				if(map[i][j][k]==0)
					continue;
				
				new_x = j +dx[k];	
				new_y = i +dy[k];
				
				if(check2[i][j][k])
					continue;

				if(new_x <1 || new_y <1 || new_x >=N-1 || new_y >=N-1)
				{
					mic[map[i][j][k]] /= 2;
					if(mic[map[i][j][k]] == 0)
					{
						map[i][j][k] =0;
						continue;
					}
					if(k==1 || k == 3)
						q= k+1;
					else
						q = k-1;
					
					map[new_y][new_x][q] = map[i][j][k];
					map[i][j][k] = 0;
					continue;	
				}
				
				check2[new_y][new_x][k] = true;
				map[new_y][new_x][k] = map[i][j][k];
				map[i][j][k] = 0;
			}
	
	int cnt=0;
	int max_mic=0;
	int dir =0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N;j++)
		{	
			cnt=0;
			max_mic = 0;
			for(int k=1; k<5; k++)
			{
				if(map[i][j][k]==0)
					continue;
				
				cnt++;
				
				if(max_mic == 0)
				{
					max_mic = map[i][j][k];
					dir = k;
				}
				else
				{
					if(mic[max_mic] < mic[map[i][j][k]])
					{
						max_mic = map[i][j][k];
						dir = k;
					}
				}
				check[k] = true;
			}
			if(cnt>1)
			{
				for(int k=1; k<5; k++)
				{
					if(k==dir)
						continue;
	
					mic[max_mic] += mic[map[i][j][k]];
					mic[map[i][j][k]]=0;
					map[i][j][k]=0;
				}
			}
		}
	 	DFS(depth+1);
}
