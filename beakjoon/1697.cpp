#include<iostream>
#include<queue>

using namespace std;
bool check[100001]={0,};

typedef struct pos
{
	int n;
	int depth;
}pos;
int main(void)
{
	queue<pos> q;
	int N, K;
	cin >> N >> K;
	pos p;
	p.n = N;
	p.depth = 0;
	check[p.n] = true;
	q.push(p);
	pos new_p;
	while(1)
	{	
		p = q.front();
		q.pop();
		new_p.depth = p.depth+1;
		
		if(p.n == K)
		{	
			cout << p.depth << endl;
			return 0;
		}

		if(p.n>0 && !check[p.n-1])
		{	
			new_p.n = p.n-1;
			q.push(new_p);
			check[p.n-1]=true;
		}

		if(p.n<100000 && !check[p.n+1])
		{	
			new_p.n = p.n+1;
			q.push(new_p);
			check[p.n+1]=true;
		}
		if(p.n<=50000 && !check[ (p.n) * 2 ])
		{	
			new_p.n = p.n*2;
			q.push(new_p);
			check[p.n*2] = true;
		}
	}
	return 0;
}
		










