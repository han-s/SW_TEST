#include<iostream>
#include<utility>
#include<queue>

using namespace std;

typedef struct board{
	int b[21][21];
	int depth;
}board;

board right(board bd);
int n;
int main(void)
{
	int result =0;
	cin >> n;
	board bd;
	bd.depth=0;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin >> bd.b[i][j];

	queue<board> q;
	q.push(bd);

	while(1)
	{
	}
}
board right(board bd)
{
	board bd1=bd;
	for(int i=1; i<=n; i++)
	{	
		int z=n;
		int t=1;
		for(int j=n; j>1; j++)
		{	
			if(bd1.b[i][z] == 0)
			{
				for(int k = z; k>1; k--)
					bd1.b[i][k] = bd1.b[i][k-1];
				
				bd1.b[i][t] = 0;
				























