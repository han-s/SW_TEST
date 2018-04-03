#include<iostream>
#include<queue>

using namespace std;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
char map[51][51];
int N;
struct Tree{
	int  x,y;
	int dir;
	int depth;
	Tree(int _x=0, int _y=0, char _dir=0 ,int _depth=0): x(_x),y(_y),dir(_dir),depth (_depth){}
};
Tree B_search();
Tree E_search();
bool Up(Tree t);
bool Down(Tree t);
bool Left(Tree t);
bool Right(Tree t);
bool check[2][51][51]={0,};
int main(void)
{
	cin >> N;
	queue<Tree> q;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> map[i][j];
	for(int i=1; i<=50; i++)
		for(int j=1; j<=50; j++)
		{
			if(i>N || j>N)
			{
				check[0][i][j] = true;
				check[1][i][j] = true;
			}
		}

	q.push(B_search());
	Tree t = E_search();
	//cout << t.x << " " << t.y <<" "<< t.dir << endl;
	Tree new_t;	
	while(!q.empty())
	{
		new_t = q.front();
		q.pop();
	//	cout << new_t.x <<" "<< new_t.y <<" "<< new_t.dir<<" " << new_t.depth << endl;
		if(new_t.x == t.x && new_t.y == t.y && new_t.dir == t.dir)
		{
			cout << new_t.depth << endl;
			return 0;
		}

		if(Up(new_t) && !check[new_t.dir][new_t.y-1][new_t.x])
		{	
			if(new_t.y-1>0)
			{
				q.push(Tree(new_t.x, new_t.y-1, new_t.dir,new_t.depth+1));
				check[new_t.dir][new_t.y-1][new_t.x] = true;
			}
		}
		if(Down(new_t) && !check[new_t.dir][new_t.y+1][new_t.x])
		{
			q.push(Tree(new_t.x, new_t.y+1, new_t.dir,new_t.depth+1));
			check[new_t.dir][new_t.y+1][new_t.x] = true;
		}
		if(Left(new_t) && !check[new_t.dir][new_t.y][new_t.x-1])
		{	
			if(new_t.x-1 >0)
			{
				q.push(Tree(new_t.x-1, new_t.y, new_t.dir,new_t.depth+1));
				check[new_t.dir][new_t.y][new_t.x-1] = true;
			}
		}
		if(Right(new_t) && !check[new_t.dir][new_t.y][new_t.x+1])
		{
			q.push(Tree(new_t.x+1, new_t.y, new_t.dir,new_t.depth+1));
			check[new_t.dir][new_t.y][new_t.x+1] = true;
		}
		if(!check[1][new_t.y][new_t.x] && Up(new_t) && Down(new_t))
		{	
			q.push(Tree(new_t.x,new_t.y,1,new_t.depth+1));
			check[1][new_t.y][new_t.x] = true;
		}
		if(!check[0][new_t.y][new_t.x] && Left(new_t) && Right(new_t))
		{	
			q.push(Tree(new_t.x,new_t.y,0,new_t.depth+1));
			check[0][new_t.y][new_t.x] = true;
		}
		
	}
	cout << "0" << endl;

}
	
bool Up(Tree t)
{	

	if(t.dir == 0)
	{	
		if(t.y-1<1)
			return false;

		if( map[t.y-1][t.x] != '1' && map[t.y-1][t.x-1] != '1' && map[t.y-1][t.x+1] !='1')
			return true;
		else
			return false;
	}
	if(t.dir==1)
	{	
		if(t.y-2<1)
			return false;

		if(map[t.y-2][t.x] != '1')
			return true;
		else
			return false;
	}
	return false;
}
bool Down(Tree t)
{	if(t.y+1 >N)
		return false;
	if(t.dir == 0)
	{
		if(map[t.y+1][t.x] != '1' && map[t.y+1][t.x-1] != '1' && map[t.y+1][t.x+1] !='1')
			return true;
		else
			return false;
	}
	if(t.dir == 1)
	{
		if(map[t.y+2][t.x] != '1')
			return true;
		else
			return false;
	}
	return false;
}

bool Left(Tree t)
{
	if(t.dir == 1)
	{	
		if(t.x-1<1)
			return false;
		if(map[t.y][t.x-1] != '1' && map[t.y-1][t.x-1] != '1' && map[t.y+1][t.x+-1] !='1')
			return true;
		else
			return false;
	}
	if(t.dir == 0)
	{	
		if(t.x-2 <1)
			return false;

		if(map[t.y][t.x-2] != '1')
			return true;
		else
			return false;
	}
	return false;
}
bool Right(Tree t)
{	
	if(t.x+1 >N)
		return false;
	if(t.dir == 1)
	{	
		if(map[t.y][t.x+1] != '1' && map[t.y-1][t.x+1] != '1' && map[t.y+1][t.x+1] !='1')
		{	
			return true;
		}
		else
			return false;
	}
	if(t.dir == 0)
	{
		if(map[t.y][t.x+2] != '1')
			return true;
		else
			return false;
	}
	return false;
}

Tree B_search()
{
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(map[i][j] == 'B')
			{	
				for(int k=0; k<4; k++)
					if(map[i+dy[k]][j+dx[k]] == 'B')
					{
						if(dy[k] == 0)
						{
							Tree t(j+dx[k],i+dy[k],0,0);
							check[0][i+dy[k]][j+dx[k]]=true;
							return t;
						}
						else
						{
							Tree t(j+dx[k],i+dy[k],1,0);
							check[1][i+dy[k]][j+dx[k]]=true;
							return t;
						}
					}
			}
}

Tree E_search()
{
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			if(map[i][j] == 'E')
			{	
				for(int k=0; k<4; k++)
					if(map[i+dy[k]][j+dx[k]] == 'E')
					{
						if(dy[k] == 0)
						{
							Tree t(j+dx[k],i+dy[k],0,0);
							return t;
						}
						else
						{
							Tree t(j+dx[k],i+dy[k],1,0);
							return t;
						}
					}
			}
}
