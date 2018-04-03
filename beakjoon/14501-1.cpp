#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main(void)
{
	int N;
	int t,p,i,result=0;
	int cnt=1;
	vector< pair<int, int> > v;
	queue<vector<pair<int,int> > > q;
	
	cin >> N;
	v.resize(N);
	v.push_back(make_pair(-1,-1));
	
	for(i=1; i<=N; i++)
	{
		cin >> t >> p;
		v[i].first = t;
		v[i].second = p;
	}

	for(i=1; i<=N;i++)
	{	
		if(v[i].first + i-1 >= N+1)
		{	
			
			v[i].second = 0;
			continue;
		}
	}

	q.push(v);
	while(!q.empty())	
	{	
		int count=0;
		//cout << tmp.size() << endl;
		//cout << endl << endl;
		//for(i=1; i<=N;i++)
		//cout << tmp[i].first << " " << tmp[i].second<<endl;
		for(int k=1; k<=N; k++)
		{
			vector< pair<int, int> > tmp = q.front();
			for(i=k; i<=N; i++)
			{	
				
				if(tmp[i].second != 0 && tmp[i].first !=0)
				{	
					int cnt = tmp[i].first;
					for(int j=1; j<cnt; j++)
						tmp[i+j].second =0;
				
					for(int j=1; j<i; j++)
					{
						if(tmp[j].first+j-1 >= i)
							tmp[j].second = 0;
					}
					tmp[i].first=0;
				}
			}
		cout << endl << endl;
		for(i=1; i<=N;i++)
		cout << tmp[i].first << " " << tmp[i].second<<endl;
			int total=0;
			for(i=1; i<=N; i++)
			{
				total = total + tmp[i].second;
			}
			if(result <total)
				result = total;
			
		}
		q.pop();
	}
	cout << result << endl;
	return 0;
	
}		



		
		
