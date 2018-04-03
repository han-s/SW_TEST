#include<iostream>

int R,C;
int board[21][21];
bool ABC[26]={false,};
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int max_value = 0;

void DFS(int x,int y, int depth);

using namespace std;

int main(void)
{
	char tmp;
	cin >> R >> C;
	for(int i=1; i<=R; i++)
		for(int j=1; j<=C; j++)
		{
			cin >> tmp;
			board[i][j] = tmp-65;
		}
	ABC[board[1][1]] = true;	
	DFS(1,1,1);
	cout << max_value << endl;
}

void DFS(int x,int y, int depth)
{	
	max_value = max(max_value,depth);
	for(int i=0; i<4; i++)
	{

		if(x + dx[i] <1 || x + dx[i] > C || y + dy[i] < 1 || y + dy[i] > R)
			continue;
		
		if(ABC[board[y+dy[i]][x+dx[i]]])
			continue;
		ABC[board[y+dy[i]][x+dx[i]]] = true;
		DFS(x+dx[i],y+dy[i],depth+1);
		ABC[board[y+dy[i]][x+dx[i]]] = false;
	}
}
