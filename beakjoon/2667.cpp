#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

void dfs(int y, int x);

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int home[26][26] = {0,};
int N;
int home_num=0;

using namespace std;

int main(void)
{
	int group_num = 0;
	vector<int> v;
	cin >> N;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			scanf("%1d",&home[i][j]); //이부분... cin 으로했을때는 불가..

	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(home[i][j]==1){
				group_num++;
				dfs(i,j);
				v.push_back(home_num);
				home_num=0;
			}

	sort(v.begin(),v.end());		//알아두면 좋을부분
	cout << group_num<<endl;
	for(int i=0; i<v.size(); i++)
		cout << v[i] << endl;

	return 0;
}

void dfs(int y, int x)
{	
	home[y][x] = 0;
	home_num++;	
	for(int i=0; i<4; i++)
		if(home[y+dy[i]][x+dx[i]]==1)
			dfs(y+dy[i], x+dx[i]);
}
