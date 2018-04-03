#include<iostream>

bool check[1001] = {0,};
int perm[1001]={0,};
int N;
int cnt=0;
using namespace std;

void DFS(int n);

int main(void)
{
	int T;
	cin >> T;
	int result[T+1];
	for(int i=1; i<=T; i++)
	{	
		cnt=0;
		cin >> N;
		for(int j=1; j<=N;j++)
			cin >> perm[j];

		for(int j=1; j<=N; j++)
			if(!check[j])
			{
				DFS(j);
				result[i]=cnt;
			}

		for(int j=1; j<=N; j++)
			check[j]=false;
	}
	for(int i=1;i<=T; i++)
		cout << result[i] << endl;
	
	return 0;
}
void DFS(int n)
{	
	if(!check[n])
	{
		check[n] = true;
		DFS(perm[n]);
	}
	else
		cnt++;
}
		
