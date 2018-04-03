/* DFS */

#include<iostream>
#include<functional>
int cost[16];
int day[16];
int n;
int max_value;
void dfs(int d, int sum);
using namespace std;
int main(void)
{	
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> day[i] >> cost[i];
	dfs(1,0);
	cout  << max_value << endl;
}

void dfs(int d, int sum)
{
	if(d == n+1){
		max_value= max(max_value, sum);
		return;
	}
	if(d+day[d] <= n+1)
		dfs(d+day[d], sum+cost[d]);
	if(d+1 <= n+1)
		dfs(d+1, sum);
}		
