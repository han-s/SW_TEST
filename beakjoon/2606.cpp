#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(void)
{
	int N,M,f,s,result=0;
	cin >> N;
	cin >> M;
	vector< pair <int, int> > v;
	queue<int> q;
	bool check[101];

	for(int i=0; i<101; i++)
		check[i]=false;

	for(int i=0; i<M; i++)
	{
		cin >> f >> s;
		v.push_back(make_pair(f,s));
	}

	check[1] = true;
	q.push(1);
	while(!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for(int i=0; i<M; i++)
		{
			if(v[i].first == tmp){
				if(check[v[i].second])
					continue;
				
				check[v[i].second] = true;
				q.push(v[i].second);
			}

			if(v[i].second == tmp){
				if(check[v[i].first])
					continue;
				check[v[i].first] = true;
				q.push(v[i].first);
			}
		}
	}

	for(int i=1;i<=N; i++)
		if(check[i])
			result++;
		
	cout << result-1 << endl;
	return 0;
}


