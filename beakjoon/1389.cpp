#include<iostream>
#include<queue>
using namespace std;

int N,M;
int A,B;
int check[101][101]={false,};

struct line{
	int x,y,depth;
	line(int _x=0, int _y=0, int _depth=0): x(_x),y(_y),depth(_depth){}
};

int main(void)
{
	cin >> N >> M;
	
	bool map[N+1][N+1];
	int len[N+1][N+1];
	for(int i=0; i<=N; i++)
		for(int j=0; j<=N; j++)
		{
			map[i][j]=false;
			len[i][j]=0;
			check[i][j] = false;
			check[j][i] = false;
		}
	
	for(int i=0; i<M;i++)
	{
		cin >> A >> B;
		map[A][B] = true;
		map[B][A] = true;
	}
	queue<line> q;
	for(int i=1; i<=N;i++)
		for(int j=1; j<=N; j++)
		{	
			if(i == j)
				continue;
			if(map[i][j])
			{
				q.push(line(i,j,1));
				len[i][j] = 1;
				len[j][i] = 1;
				check[i][j] = true;
				check[j][i] =true;
			}
		}

	while(!q.empty())
	{
		line l = q.front();
		q.pop();
		
		for(int i=1; i<=N; i++)
		{	
			
			if(l.x == i || l.y == i ||  check[l.x][i] || check[i][l.x])
				continue;

			if(map[l.y][i])
			{
				check[l.x][i] = true;
				check[i][l.x] = true;
				len[l.x][i] = l.depth + 1;
				len[i][l.x] = l.depth + 1;
				q.push(line(l.x,i,l.depth+1));
			}
		}
	}
	int m = 100000;
	int result =0;
	for(int i=1; i<=N; i++)
	{	
		int num = 0;
		for(int j=1; j<=N ;j++)
			if(i!=j)
				num += len[i][j];
		
		if(m > num)
		{
			m = num;
			result = i;
		}		
	}
	cout << result << endl;
}

	
