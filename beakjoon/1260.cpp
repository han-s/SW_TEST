#include<iostream>
#include<queue>

using namespace std;

bool allcheck(bool check[]);
void DFS(int n,int v);
void BFS();

bool check[1001]= {0,};
bool check2[1002]={0,};
int N,M,V;
bool link[1001][1001] = {0,};
queue<int> q;

int main(void)
{	
	int link_a, link_b;
	cin >> N >> M >> V;
	for(int i=1; i<=M; i++)
	{
		cin >> link_a >> link_b;
		link[link_a][link_b] = true;
		link[link_b][link_a] = true;
	}
	
	cout << V<< " ";
	check[V] = 1;
	DFS(1,V);
	cout << endl;
	q.push(V);
	BFS();
}

void DFS(int n,int v)
{
	if(allcheck(check))
		return;
	
	if(n==N+1)
		return;

	for(int i=1; i<=N ; i++)
	{
		if(link[v][i])
		{
			if(!check[i]){
				check[i]=true;
				cout << i<< " ";
				DFS(n+1,i);
			}
		}
	}
}

void BFS()
{	
	while(1)
	{	
		int k = q.front();
		q.pop();
		if(!check2[k])
		{	
			check2[k] = true;
			cout << k<<" ";
		}
		if(allcheck(check2))
			break;

		for(int i=1; i<=N; i++)
			if(link[k][i])
				q.push(i);
	}

}
bool allcheck(bool check[])
{	
	for(int i=1; i<=N; i++)
		if(!check[i])
			return false;
	return true;
}

