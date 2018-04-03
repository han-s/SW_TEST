#include<iostream>
#include<queue>

using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] =	{-1,0,1,0};

struct tail
{
	int x;
	int y;
	tail(int _x,int _y):x(_x),y(_y){}
};
int main(void)
{
	int N,K,L,x,y,dir=3,second=0;
	cin >> N >> K;
	bool apple[N+1][N+1];
	bool check[N+1][N+1];
	char rotate[10001];
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N;j++)
		{
			apple[i][j] = false;
			check[i][j] = false;
		}

	for(int i=0; i<K;i++)
	{
		cin >> y >> x;
		apple[y][x] = true;
	}
	
	cin >> L;
	for(int i=0; i<L;i++)
	{
		cin >> x;
		cin >> rotate[x];
	}
	x=1, y=1;
	check[y][x] = true;
	queue<tail> q;
	q.push(tail(x,y));
	while(1)
	{	
		second++;		
		x=x+dx[dir];
		y=y+dy[dir];
		q.push(tail(x,y));
		if(check[y][x] || x==0 || y == 0 || x>N || y>N)
			break;
		
		if(!apple[y][x])
		{
			tail t = q.front();
			q.pop();
			check[t.y][t.x] = false;
		}
		else
		{
			apple[y][x] = false;
		}
		
		if(rotate[second] == 'L')
			dir = (dir+1)%4;
		else if(rotate[second] == 'D')
			dir = (dir+3)%4;
		check[y][x] = true;
	}
	cout << second << endl;
		
}

