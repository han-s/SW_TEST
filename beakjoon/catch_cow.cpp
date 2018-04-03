#include<iostream>
#include<queue>
#include<utility>
#include<math.h>

using namespace std;

int main(void)
{	
	int n;
	int k;
	pair<int,int> p;
	queue<pair<int,int> >q;
	cin >> n >> k;
	q.push(make_pair(n,0));
	int result=0;
	while(1)
	{	
		p=q.front();
		q.pop();
		if(p.first==k)
			break;

		if(p.first>=1){
			q.push(make_pair(p.first-1,p.second+1));
			cout << p.first-1 << p.second +1 <<endl;
		}
		if(p.first<100000 && p.first<k){
			q.push(make_pair(p.first+1,p.second+1));
			cout << p.first+1 << p.second +1 <<endl;
		}

		if(p.first*2 <=100000 && p.first<k){
			q.push(make_pair(p.first*2,p.second+1));
			cout << p.first*2 << p.second +1 <<endl;
		}
		if(p.first+1 ==k || p.first-1 ==k || p.first*2 == k)
			break;
	}
	cout << p.second +1 << endl;
	return 0;
}
