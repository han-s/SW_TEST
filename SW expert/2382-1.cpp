#include<iostream>

using namespace std;
int M, N, K, T;
typedef struct mic{
	int x,y;
	int num;
	int dir;
}mic;

mic m[1000];
int check[5][100][100];
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,-1,1,0,0};
int Max = 0;
void DFS(int depth);
int main(void)
{
	cin >> T;
	for(int t=1; t<=T; t++)
	{	
		Max=0;
		cin >> N  >> M >> K;
		for(int i=0; i<K;i++)
			cin >> m[i].y >> m[i].x >> m[i].num >> m[i].dir;
	
		DFS(1);
		cout <<"#" << t << " " <<  Max<<endl;

	}
}

void DFS(int depth)
{	
	if(depth >M)
	{	
		for(int i=0; i<K; i++)
		{
			//cout <<  m[i].x << " " << m[i].y <<  " "<< m[i].num <<" "<< m[i].dir <<  endl;
			Max = Max + m[i].num;
		}
		return;
	}
	//체크 초기화
	for(int i=0; i<5; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<N ; k++)
			{
				check[i][j][k] = -1;
			}

	int new_x, new_y;
	//좌표이동
	for(int i=0; i<K; i++)
	{	
		//값이 0이면 없어진 군집
		if(m[i].num == 0)
			continue;
     
		m[i].x = m[i].x + dx[m[i].dir];
		m[i].y = m[i].y + dy[m[i].dir];
		if(m[i].x <1 || m[i].y <1 || m[i].x >N-2 || m[i].y > N-2)
		{		
			m[i].num /=2;
			if(m[i].dir == 1 || m[i].dir == 3)
				m[i].dir += 1;
			else
				m[i].dir -= 1;
			continue;
		}

		check[0][m[i].y][m[i].x]++;
		for(int j=1; j<5; j++)
		{
			if(check[j][m[i].y][m[i].x] == -1)
			{
				check[j][m[i].y][m[i].x] = i;
				break;
			}
		}
	}
	int max_mic=0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			if(check[0][i][j]>0)
			{	
				max_mic = check[1][i][j];
				for(int k=2; k<5; k++)
				{	
					
					if(check[k][i][j] != -1)
						if(m[max_mic].num < m[check[k][i][j]].num)
							max_mic = check[k][i][j];
				}
				for(int k=1; k<5; k++)
				{
					if(check[k][i][j] == max_mic)
						continue;
					if(check[k][i][j] == -1)
						break;
					m[max_mic].num += m[check[k][i][j]].num;
					m[check[k][i][j]].num = 0;
				}
				if(m[max_mic].num>10000)
					m[max_mic].num = 10000;
			}
		}

	DFS(depth+1);			

			
		
}
