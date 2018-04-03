#include<iostream>
#include<algorithm>
using namespace std;

int M,N,K;
int cnt=0;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
void DFS(int x,int y,int cnt);
bool check[100][100];
int result[5000]={0,};
int main(void)
{	
	int x1,x2,y1,y2;
	cin >> M >> N >> K;
	
	for(int i=0; i<100;i++)
		for(int j=0; j<100;j++)
			check[i][j] = false;

	for(int i=0; i<K; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for(int q=x1; q<x2;q++)
			for(int w=y1; w<y2; w++)
				check[w][q] = true;
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0; j<N;j++)
		{
			if(!check[i][j])
			{
				DFS(j,i,cnt);
				cnt++;
			}
		}
	}
	sort(result,result+cnt);
	cout << cnt << endl;
	for(int i=0; i<cnt; i++)
		cout << result[i] << " ";

	cout << endl;
}
void DFS(int x,int y,int cnt)
{	
	result[cnt]++;
	check[y][x] = true;
	for(int i=0;i<4; i++)
	{	
		if(y+dy[i]<0 || y+dy[i]>=M || x+dx[i] <0 || x+dx[i]>=N)
			continue;

		if(!check[y+dy[i]][x+dx[i]])
			DFS(x+dx[i],y+dy[i],cnt);
	}
}
