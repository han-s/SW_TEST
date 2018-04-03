#include<iostream>
#include<algorithm>
#include<math.h>
bool ox[21];
int N;
int board[21][21];
int A_result=0;
int B_result=0;
int A_team[11];
int B_team[11];
int result = 1000000;
using namespace std;

void cal();
void dfs(int n, int tmp);
int main(void)
{

	cin >> N;
	for(int i=1; i<=N; i++)
	{	
		ox[i] = false;
		for(int j=1; j<=N; j++)
			cin >> board[i][j];
	}
	dfs(1, 0);
	cout << result << endl;
}

void dfs(int n, int tmp)
{	
	if(n == ((N/2)+1))
	{	
		cal();
		result = min(result, abs(A_result-B_result));
		return;
	}
	for(int i=tmp+1; i<=N; i++)
	{
		if(ox[i]==false)
		{
			ox[i] = true;
			dfs(n+1,i);
			ox[i] = false;
		}
	}
}		

void cal()
{	
	int A_cnt = 1;
	int B_cnt = 1;
	A_result = 0;
	B_result = 0;
	for(int i=1; i<=N; i++)
	{
		if(ox[i])
		{
			A_team[A_cnt] = i;
			A_cnt++;
		}
		else
		{
			B_team[B_cnt] = i;
			B_cnt++;
		}
	}
	
	for(int i=1; i<=(N/2) ; i++)
	{
		for(int j=i; j<=(N/2) ; j++)
		{
			A_result = A_result + board[A_team[i]][A_team[j]];
			A_result = A_result + board[A_team[j]][A_team[i]];
			
			B_result = B_result + board[B_team[i]][B_team[j]];
			B_result = B_result + board[B_team[j]][B_team[i]];
		}
	}

}	











