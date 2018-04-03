#include<iostream>
#include<queue>
using namespace std;

struct pos
{
	int x,y, depth;
	pos(int _x=0,int _y=0, int _depth=0 ) : x(_x),y(_y),depth(_depth){}
};
int house_cnt=0;
int T,N,M;
int result=0;
int cnt=0;
bool Map[20][20];
bool check[20][20];

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
queue<pos> q;

void BFS();
int main(void)
{
	cin >> T;

	for(int t=1; t<=T; t++)
	{
		cin >> N >> M;
		result = 0;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				cin >> Map[i][j];
				check[i][j] = false;
				if(Map[i][j])
					house_cnt++;
			}
		for(int i=1; i<41; i++)	
			if(house_cnt*M < i * i + (i-1)*(i-1))
			{
				house_cnt = i;
				break;
			}’ㅇ
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{	
				if(Map[i][j] == 1)
					cnt=1;

				else
					cnt=0;
				
				if(cnt * M >= 1)
					result = max(result,cnt);

				check[i][j] = 1;
				q.push(pos(j,i,1));
				BFS();
				
				while(!q.empty())
					q.pop();
				for(int q=0; q<N; q++)
					for(int w=0; w<N; w++)
						check[q][w] = false;
			}

		cout << "#" <<t << " " <<result << endl;
					
	}
}

void BFS()
{
	int new_x,new_y;
	pos p;
	while(!q.empty())
	{	
		p = q.front();
		if(p.depth >=house_cnt)
			break;

		q.pop();
		for(int i=0; i<4; i++)
		{
			new_x = p.x + dx[i];
			new_y = p.y + dy[i];
			
			if(new_x<0 || new_y <0 || new_x >=N || new_y >=N)
				continue;
			
			if(check[new_y][new_x])
				continue;

			if(Map[new_y][new_x])
			{
				cnt++;
			}
			check[new_y][new_x] = true;
			q.push(pos(new_x,new_y,p.depth+1));
		}
		

		if(p.depth + 1 == q.front().depth)
			if(cnt * M >= (p.depth+1) * (p.depth+1) + (p.depth) * (p.depth))
				result = max(result, cnt);
	}
}
