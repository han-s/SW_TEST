#include<iostream>
#include<queue>
#include<vector>
int direction[4] = { 0, 1, 2, 3 };
int dx[4] = { 0, -1, 0, 1};
int dy[4] = { -1, 0, 1, 0};
using namespace std;

typedef struct snake
{
	int y,x;
	char dir;
}snake;

int main(void)
{
	long long result =0;
	int L, v_temp=0;
	queue<snake> q;
	cin >> L;
	int size = L*2 +3;
	int board[size][size];
	snake s;
	
	for(int i=0 ; i<size ; i++)
		for(int j=0 ; j<size; j++)
		{	
			if(i!=0 && j !=0 && i != size-1 && j != size-1)
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	
	int N;
	cin >> N;
	vector< pair <int, char> > v;
	v.resize(N+1);
	for(int i=1; i<=N; i++)
	{
		int i_tmp;
		char c_tmp;
		cin >> i_tmp >> c_tmp;
		v[i].first = i_tmp;
		v[i].second = c_tmp;
	}
	s.dir =	3;
	s.x = s.y = size/2;
	board[s.y][s.x] = 1;
	q.push(s);

	while(!q.empty())
	{	
		bool check = false;
		snake n = q.front();
		q.pop();
		int cnt = v[v_temp].first;
		int nx=n.x, ny=n.y, ndir=n.dir;
		while(cnt--)
		{	
			result++;
			ny = ny + dy[ndir];
			nx = nx + dx[ndir];
			if(board[ny][nx] == 1)
			{	
				//cout << board[ny][nx] << endl;
				//cout << ny << " " << nx << " " << ndir << endl;
				check = true;
				break;
			}	
			board[ny][nx] = 1;
		}

		if(check)
			break;
		if(v[v_temp].second == 'L')
			ndir = (n.dir + 1) % 4;
		if(v[v_temp].second == 'R')
			ndir = (n.dir + 3) % 4;
		
		n.dir = ndir;
		n.x = nx;
		n.y = ny;
		q.push(n);
		v_temp++;
	}
	for(int i=0 ; i<size ;i++)
	{
		cout << endl;
		for(int j=0; j<size ; j++)
			cout << board[i][j] << " ";
	}
//	cout << result << endl;
	return 0;
}
