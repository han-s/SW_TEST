#include<iostream>
#include<queue>

using namespace std;

int N,T;
int person[10][3];
int Map[10][10];
int stair_buf[2][3];
int stair_x[2];
int stair_y[2];
int stair_len[2];
int person_num;
int max_num=0;
int min_result=100000;
queue<int> q[2];
queue<int> q2;
void DFS1(int num);
void DFS2(int time);

int main(void)
{
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		cin >> N;
		int tmp = 0;
		min_result = 100000;	
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				cin >> Map[i][j];
				if(Map[i][j] != 0 && Map[i][j] !=1)
				{
					stair_x[tmp] = j;		
					stair_y[tmp] = i;
					stair_len[tmp++] = Map[i][j];
				}
			}
		person_num=0;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				if(Map[i][j] == 1)
				{
					for(int k=0; k<2; k++)
						person[person_num][k] = abs(stair_x[k]-j) + abs(stair_y[k]-i);
					person_num++;
				}
			}
			

		DFS1(0);
		cout << "#"<< t<< " " << min_result << endl;
	}
}
void DFS1(int num)
{	
	
	if(num == person_num)
	{	
		max_num = 0;
		for(int i=0; i<person_num; i++)
			max_num = max(max_num, person[i][person[i][2]]);
		
		DFS2(1);
		return;
	}
	for(int i=0; i<2; i++)
	{
		person[num][2] = i;
		DFS1(num+1);
	}		
}

void DFS2(int time)
{	
	bool ch = false;
	if(q[0].empty() && q[1].empty() && max_num < time)
	{	
		for(int i=0; i<3; i++)
		{
			if(stair_buf[0][i] != 0 || stair_buf[1][i] != 0)
			{	
				ch=true;
				break;
			}
		}
		if(!ch)
		{
			min_result = min(time, min_result);
			return;
		}	
	}

	for(int i=0; i<3; i++)
	{	
		for(int j=0; j<2; j++)
			if(stair_buf[j][i] !=0)
				stair_buf[j][i]--;
	}
	for(int i=0; i<person_num ;i++)
	{
		if(person[i][person[i][2]] == time)
			q[person[i][2]].push(i);
	}
	bool check= true;

	for(int i=0; i<2; i++)
	{	
		check = true;
		while(!q[i].empty())
		{	
			for(int j=0; j<3; j++)
				if(stair_buf[i][j] == 0)
				{
					stair_buf[i][j] = stair_len[i];
					check = false;
					break;
				}
			if(check)
				break;

			q[i].pop();
		}
	}

	DFS2(time+1);
}

