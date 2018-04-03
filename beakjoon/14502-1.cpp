#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N,M;
int search();
void BFS();
int board[9][9];
int tmp[11][11];
int main(void)
{
	int i,j,result=0;
	cin >> N >> M;
	vector< pair <int, int> > v;

	for(i=1; i<=N; i++)
		for(j=1; j<=M; j++)
			cin >> board[i][j];
	
	for(i=1; i<=N; i++)
		for(j=1; j<=M; j++)
			if(board[i][j] == 0)
				v.push_back(make_pair(i,j));

	
	for(i=0; i<v.size();i++)
	{	
		board[v[i].first][v[i].second] = 1;
		for(j=i+1; j<v.size();j++)
		{	
			board[v[j].first][v[j].second] = 1;
			
			for(int k=j+1; k<v.size(); k++)
			{
				board[v[k].first][v[k].second] = 1;
				BFS();
				if(result < search()){
					result = search();
				}
				
				board[v[k].first][v[k].second] = 0;
			}
			board[v[j].first][v[j].second] = 0;
		}
		board[v[i].first][v[i].second] = 0;
	}
	

	cout << result << endl;

	
}	
void BFS()
{
	int i,j;
	queue<pair <int, int> > q;
	for(i=1; i<=N; i++)
		for(j=1; j<=M; j++)
			tmp[i][j] = board[i][j];

	for(i=0; i<=N; i++)
	{
		tmp[i][0] = 3;
		tmp[i][M+1] = 3;
	}
	for(i=0; i<=M; i++)
	{
		tmp[0][i] = 3;
		tmp[N+1][i] = 3;
	}
	

	for(i=1; i<=N; i++)
		for(j=1; j<=M; j++)
			if(tmp[i][j] == 2)
				q.push(make_pair(i,j));
	
	
				
	while(!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		
		int x = p.first;
		int y = p.second;

		if(tmp[x-1][y] == 0)
		{
			tmp[x-1][y] = 2;
			q.push(make_pair(x-1,y));
		}
		if(tmp[x+1][y] == 0)
		{
			tmp[x+1][y] = 2;
			q.push(make_pair(x+1,y));
		}
		if(tmp[x][y-1] == 0)
		{
			tmp[x][y-1] = 2;
			q.push(make_pair(x,y-1));
		}
		if(tmp[x][y+1] == 0)
		{
			tmp[x][y+1] = 2;
			q.push(make_pair(x,y+1));
		}

		
	}
}
int search()
{	
	int result = 0;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			if(tmp[i][j]==0)
				result++;

	return result;
}
