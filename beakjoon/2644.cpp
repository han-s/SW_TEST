#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int n,m;
	int mother, son, m_r, s_r;
	cin >> n >> mother >> son >> m;
	pair<int, int> new_r;
	bool rel[n+1][n+1];
	
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
		{
			rel[i][j] = false;
		}

	for(int i=1; i<=m; i++)
	{
		cin >> m_r >> s_r;
		rel[m_r][s_r] = true;
		rel[s_r][m_r] = true;
	}

	queue< pair<int, int > > q;
	q.push(make_pair(mother, 1));
	while(!q.empty())
	{
		new_r = q.front();
		q.pop();
		for(int i=1; i<=n; i++)
		{
			if(rel[new_r.first][i])
			{	
				if(i == son)
				{
					cout << new_r.second << endl;
					return 0;
				}
				rel[new_r.first][i] = false;
				rel[i][new_r.first] = false;
				q.push(make_pair(i, new_r.second+1));
			}
		}	
	}

	cout << "-1" << endl;
	return 0;
}
