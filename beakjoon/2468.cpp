#include<iostream>
#include<algorithm>
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int N=0;
int map[101][101]={0,};
bool check[101][101][101]={0,};
int cnt=0;
void DFS(int i,int y, int x);
void check_map(int k);
using namespace std;

void check_map(int k);

int main(void)
{
	cin >> N;
	int result=1;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> map[i][j];

	for(int i=1; i<=100; i++)
	{	
		check_map(i);
		cnt=0;

		for(int j=1; j<=N; j++)
			for(int k=1; k<=N; k++)
				if(check[i][j][k])
				{	
					cnt++;
					DFS(i,j,k);
				}
		
		result = max(result,cnt);
	}
	cout << result << endl;
	return 0;
}

void DFS(int i,int y, int x)
{	
	check[i][y][x]=false;
	for(int j=0 ; j<4 ; j++)
		if(check[i][y+dy[j]][x+dx[j]])
			DFS(i,y+dy[j],x+dx[j]);
}

void check_map(int k)
{
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(k<map[i][j])
				check[k][i][j]=true;
}
