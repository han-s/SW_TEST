#include<iostream>
#include<queue>
#include<utility>
#include<math.h>
#include<vector>
using namespace std;
int N;
int map[101][101]={0,};
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int cnt=1;
int result=200;
int x,y;
int tmp_x, tmp_y;
void before_DFS(int x, int y);
vector< pair<int,int> > v[5];
int main(void)
{	
	cin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N;j++)
			cin >> map[i][j];
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(map[i][j] == 1)
			{	
				cnt++;
				before_DFS(j,i);
			}
	for(int i=0; i<cnt-2; i++)
		for(int j=i+1; j<cnt-1; j++)
		{
			for(int k=0; k<v[i].size(); k++)
				for(int m=0; m<v[j].size(); m++)
				{
					x=abs(v[i][k].first-v[j][m].first);
					y=abs(v[j][m].second-v[i][k].second);
					result = min(result, x+y);
				}
		}
	cout << result-1 << endl;
}
					
void before_DFS(int x, int y)
{	
	map[y][x] = cnt;
	for(int i=0; i<4; i++)
	{	
		tmp_x = dx[i]+x;
		tmp_y = dy[i]+y;
		if(tmp_x<1 || tmp_x >N || tmp_y<1 || tmp_y>N)
			continue;
		if(map[tmp_y][tmp_x] == 0){
			v[cnt-2].push_back(make_pair(x,y));
			break;
		}
	}
	for(int i=0; i<4; i++)
	{
		tmp_x = dx[i]+x;
		tmp_y = dy[i]+y;
		if(tmp_x<1 || tmp_x >N || tmp_y<1 || tmp_y>N)
		{
			continue;
		}
		if(map[dy[i] + y][dx[i]+x] == 1){
			before_DFS(dx[i]+x,dy[i]+y);
		}
	}
}	

