#include<iostream>
#include<queue>
#include<vector>
int direction[4] = {0,1,2,3};
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

using namespace std;

typedef struct snake
{
	int y,x;
	char dir;
}snake;

int main(void)
{
	long long result =0, result2 =0;
	int L,N;
	int first;
	int t,u;
	char second;
	vector< pair <int, char> > v;
	v.resize(N+2);
	cin >> L;
	cin >> N;
	int size = L*2 + 1;
	snake s[N+1];
	s[0].x = (size+1)/2;
	s[0].y = (size+1)/2;
	s[0].dir = 3;
	int cmp_t=0, cmp_u=0;
	bool c2=true;
	for(int i=1; i<=N+1; i++)
	{	
		if(i!=N+1)
		{
			cin >> first >> second;
			v[i].first = first;
			v[i].second = second;
		}
		else
		{
			v[i].first = 200000000;
			v[i].second = 'q';
		}
		for(int j=0; j<4 ;j++)
		{
			if(direction[j] == s[i-1].dir)
			{	
				int temp_cnt = 0;
				int cnt = v[i].first;
				int x = s[i-1].x;
				int y = s[i-1].y;
				int dir = s[i-1].dir;
				while(cnt--)
				{
					temp_cnt++;
					x = x+dx[j];
					y = y+dy[j];
					if(c2 && (x<1 || y<1 || x>size || y>size))
					{
						c2=false;
						cmp_t=i;
						cmp_u=temp_cnt;
						break;
					}
				}
				
				if(v[i].second == 'L')	
					dir = (dir + 1) % 4;
				if(v[i].second == 'R')
					dir = (dir + 3) % 4;
				s[i].x =x;
				s[i].y =y;
				s[i].dir =dir;
			}
		}
	}

	for(int i=0;i<cmp_t; i++)
	{
		bool check = false;
		for(int j=i+2 ; j<=cmp_t; j++)
		{	
			int ix = s[i].x;
			int iy = s[i].y;		
			int cnt = v[i+1].first;
			for(int k=0; k<=cnt; k++)
			{	
				int jx = s[j].x;
				int jy = s[j].y;
				int cnt2 = v[j+1].first;
				for(int q=1; q<=cnt2; q++)
				{
					jx = jx + dx[s[j].dir];
					jy = jy + dy[s[j].dir];
					if(jx <1 || jy <1 || jx>size || jy >size)
						break;
					if(ix == jx && iy == jy)
					{
						t=j;
						u=q;
						check = true;
						break;
					}
				}
				ix = ix + dx[s[i].dir];
				iy = iy + dy[s[i].dir];
				if(check)
					break;
			}
			if(check)
				break;
		}
		if(check)
			break;
	}
	
	for(int i=1; i<cmp_t; i++)
		result = result + v[i].first;

	result = result + cmp_u;
	for(int i=1; i<=t; i++)
	{
		result2 = result2 + v[i].first;
	}
	result2 = result2 + u;
	
	if(result2!=0 && result !=0 &&result<result2)
		cout << result<<endl;
	else if(result>result2 && result!=0 && result2!=0)
		cout <<result2<<endl;
	else if(result==0 && result2 !=0)
		cout << result2 << endl;
	else if(result2==0 && result !=0)
		cout << result << endl;
	else if(result2 == 0 && result == 0)
	{
		for(int i=1 ;i<v.size(); i++)
		{
			result = result + v[i].first;
		}
		cout << result << endl;
	}

	return 0;
}









