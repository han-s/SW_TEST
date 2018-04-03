#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int b_cnt=0;
int aa=0;
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
		vector< pair<int, int> > tmp = q.front();
		
		bool b_tmp[N+1];
		int count=0;
		vector< pair<int, int> > tmp2 = q.front();
		for(i=1; i<=N; i++)
		{	
			for(int j=1 ; j<=N ; j++)
			{
				tmp2[j].first = tmp[j].first;
				tmp2[j].second = tmp[j].second;
			}
			if(tmp[i].second != 0 && tmp[i].first !=0)
			{	
				
				count++;
				int cnt = tmp2[i].first;
				for(int j=1; j<cnt; j++)
					tmp2[i+j].second =0;
				
				for(int j=1; j<i; j++)
				{
					if(tmp2[j].first+j-1 >= i)
						tmp2[j].second = 0;
				}
				tmp2[i].first=0;
					
				q.push(tmp2);
			}
			
		}
		if(count==0)
		{	
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
