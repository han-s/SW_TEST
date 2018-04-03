#include<iostream>

using namespace std;

struct line{
	int x1,y1,x2,y2;
	line(int _x1=0, int _y1=0, int _x2=0, int _y2=0): x1(_x1),y1(_y1),x2(_x2), y2(_y2){}
};

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int main(void)
{
	int L, N;
	cin >> L >> N;
	int tmp_rot[1000];
	int total_rot=0;
	line Li[1001];
	int x1=0,x2=0,y1=0,y2=0;
	char tmp_dir;
	int dir[1001];
	dir[0] = 3;
	
	for(int i=0; i<N; i++)
	{	

		cin >> tmp_rot[i] >> tmp_dir;
		x2 = x2 + tmp_rot[i] * dx[dir[i]];
		y2 = y2 + tmp_rot[i] * dy[dir[i]];
		Li[i] = line(x1,y1,x2, y2);
		x1 = x2;
		y1 = y2;
		
		if(tmp_dir == 'L')
			dir[i+1] = (dir[i] + 1) % 4;
		if(tmp_dir == 'R')
			dir[i+1] = (dir[i] + 3) % 4;
		
	}	
	if(dir[N] == 0)
		y2 = -1* L;
	else if(dir[N] == 1)
		x2 = -1 * L;
	else if(dir[N] == 2)
		y2 = 1 * L;
	else if(dir[N] == 3)
		x2 = 1 * L;
	
	Li[N] = line(x1,y1,x2,y2);
	for(int i=0; i<=N; i++)
	{
		cout << Li[i].x1 << " " << Li[i].y1 << " " << Li[i].x2 << " " << Li[i].y2 << endl;
	
	}
	int cnt = 0;
	int tmp_x1,tmp_x2,tmp_y1,tmp_y2;
	int tmp = 2*L+2;
	while(1)
	{
		//if(Li[cnt].x2 >2*L || Li[cnt].x2 <-2*L || Li[cnt].y1 >2*L || Li[cnt].y2 <-3)
		//break;
		tmp_x1 = Li[cnt].x1;
		tmp_x2 = Li[cnt].x2;
		tmp_y1 = Li[cnt].y1;
		tmp_y2 = Li[cnt].y2;
		cout << tmp_y1 << endl;
		for(int i=0; i<cnt-1; i++)
		{	
			if(cnt%2 == 0)
			{
				if(tmp_x1>tmp_x2)
				{
					for(int j = tmp_x1; j>=tmp_x2; j--)
					{
						if((Li[i].x1 < j && Li[i].x2 <j) || (Li[i].x1 >j && Li[i].x2 >j))
							continue;
						if((Li[i].y1 < tmp_y1 && Li[i].y2 <tmp_y1) || (Li[i].y1 >tmp_y1 && Li[i].y2 >tmp_y2))
							continue;
						
						tmp = j;
						break;
					}
				}
				else if(tmp_x1 < tmp_x2)
				{
					for(int j = tmp_x1; j<=tmp_x2; j++)
					{
						if((Li[i].x1 < j && Li[i].x2 <j) || (Li[i].x1 >j && Li[i].x2 >j))
							continue;
						if((Li[i].y1 < tmp_y1 && Li[i].y2 <tmp_y1) || (Li[i].y1 >tmp_y1 && Li[i].y2 >tmp_y2))
							continue;

						tmp = j;
						break;
					}
				}
				if(tmp != 2*L+2)
					break;
			}
			else
			{
				if(tmp_y1>tmp_y2)
				{
					for(int j = tmp_y1; j>=tmp_y2; j--)
					{	
						if((Li[i].y1 < j && Li[i].y2 <j) || (Li[i].y1 >j && Li[i].y2 >j))
							continue;
						if((Li[i].x1 < tmp_x1 && Li[i].x2 <tmp_x1) || (Li[i].x1 >tmp_x1 && Li[i].x2 >tmp_x2))
							continue;
						
						tmp = j;
						break;
					}
				}
				else if(tmp_y1 < tmp_y2)
				{
					for(int j = tmp_y1; j<=tmp_y2; j++)
					{
						cout << j << endl;
						if((Li[i].y1 < j && Li[i].y2 <j) || (Li[i].y1 >j && Li[i].y2 >j))
							continue;
						if((Li[i].x1 < tmp_x1 && Li[i].x2 <tmp_x1) || (Li[i].x1 >tmp_x1 && Li[i].x2 >tmp_x2))
							continue;
						
						tmp = j;
						break;
					}
				}
				if(tmp != 2*L+2)
					break;

			}
		}	
		if(tmp != 2*L + 2)
			break;
		cnt++;
	}
	cout << cnt << " " << tmp << endl;		
}
