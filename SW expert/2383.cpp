#include<iostream>

using namespace std;

int T,N;
int map[10][10];
int person_x[10];
int person_y[10];
int person_cnt = 0;
int exit_x[2];
int exit_y[2];
int exit_cnt=0;
int distance[2][10];
int stair1[10];
int stair2[10];
int stair1_cnt=0;
int stair2_cnt=0;
bool select[10];
int main(void)
{
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		cin >> N;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{	
				person_cnt = 0;
				exit_cnt = 0;
				cin >> map[i][j];
				if(map[i][j]==1)
				{
					person_x[person_cnt] = j;
					person_y[person_cnt++] = i;
				}

				if(map[i][j] != 0 && map[i][j] != 1)
				{
					exit_x[exit_cnt] = j;
					exit_y[exit_cnt++] = i;
				}
			}
		for(int i=0; i<exit_cnt; i++)
			for(int j=0; j<person_cnt; j++)
			{
				distance[i][j] = abs(person_x[j] - exit_x[i]) + abs(person_y[j] - exit_y[i]);

			}

		

	}
}

void DFS(int person)
{	
	if(person == person_cnt)
	{
		
	}
	for(int i=0; i<2; i++)
	{	
		select[person] = i;
		DFS(person+1);
	}
}

void DFS2(int time)
{
	for(int i=0; i<person_cnt; i++)
	{
		for(int j=0; j<2; j++)
		{
			if(select[i] == j && distance[i][j] == time)
			{
			
			}				
		}
	}
}








