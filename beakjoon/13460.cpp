#include<iostream>
#include<queue>

using namespace std;

typedef struct board
{
	char b[11][11];
	char direction;
	int depth;
	int success;
}board;

typedef struct ball
{
	pair<int,int> red,blue;
}ball;

board left_board(board first);
board right_board(board first);
board up_board(board first);
board down_board(board first);
ball search_ball(board first);
int N,M;

int main(void)
{
	int i, j;
	queue<board> q;
	board first;
	cin >> N >> M;
	for(i=1; i<=N; i++)
		for(j=1; j<=M; j++)
			cin >> first.b[i][j];

	first.direction='c';
	first.depth = 0;
	first.success=0;
	q.push(first);

	while(!q.empty())
	{	
		first=q.front();
		q.pop();
		board left=left_board(first);
		board right=right_board(first);
		board up=up_board(first);
		board down=down_board(first);

		if(up.success==1 || down.success==1 || left.success==1 || right.success==1){
			cout << first.depth+1<<endl;
			break;
		}
		if(first.depth<10)
		{
		if(first.direction=='l')
		{
			if(up.success!=-1)
				q.push(up);
			if(down.success!=-1)
				q.push(down);
			if(right.success!=-1)
				q.push(right);
			if(left.success!=-1)
				q.push(left);
		}
		else if(first.direction=='r')
		{
			if(up.success!=-1)
				q.push(up);
			if(down.success!=-1)
				q.push(down);
			if(left.success!=-1)
				q.push(left);
			if(right.success!=-1)
				q.push(right);
			
		}
		else if(first.direction=='u')
		{
			
			if(left.success!=-1)
				q.push(left);
			if(right.success!=-1)
				q.push(right);
			if(down.success!=-1)
				q.push(down);
			if(up.success!=-1)
				q.push(up);
		}
		else if(first.direction=='d')
		{
			if(left.success!=-1)
				q.push(left);
			if(right.success!=-1)
				q.push(right);
			if(up.success!=-1)
				q.push(up);
			if(down.success!=-1)
				q.push(down);
		}
		else
		{
			if(up.success!=-1)
				q.push(up);
			if(down.success!=-1)
				q.push(down);
			if(left.success!=-1)
				q.push(left);
			if(right.success!=-1)
				q.push(right);
		}
		}
		if(q.empty())
			cout << "-1"<<endl;
	}
	return 0;
}

ball search_ball(board first)
{	
	ball ba;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
		{
			if(first.b[i][j]=='R')
			{
				ba.red.first=i;
				ba.red.second=j;
			}
			else if(first.b[i][j]=='B')
			{
				ba.blue.first=i;
				ba.blue.second=j;
			}
		}
	
	return ba;
}

board left_board(board first)
{
	board left=first;
	ball pos=search_ball(first);
	if(pos.red.first != pos.blue.first)
	{
		int i=pos.red.first;
		int j=pos.red.second;
		for(;left.b[i][j-1]!='#';j--)
		{
			if(left.b[i][j-1] =='O')
			{
				left.depth=left.depth+1;
				left.success=1;
				left.direction='l';
				return left;
			}
			
			left.b[i][j-1]='R';
			left.b[i][j]='.';
		}

		i=pos.blue.first;
		j=pos.blue.second;

		for(;left.b[i][j-1]!='#';j--)
		{
			if(left.b[i][j-1] =='O')
			{
				left.success= -1;
				left.direction='l';
				left.depth+=1;
				return left;
			}

			left.b[i][j-1]='B';
			left.b[i][j]='.';
		}
	}
	else if(pos.red.first == pos.blue.first)
	{
		int i=pos.red.first;
		int j=pos.red.second;
		int count=0;
		for(;left.b[i][j-1]!='#';j--)
		{
			if(left.b[i][j-1] =='O')
				count++;
		}

		i=pos.blue.first;
		j=pos.blue.second;

		for(;left.b[i][j-1]!='#';j--)
		{
			if(left.b[i][j-1]=='O')
				count++;
		}

		if(count == 2){
			left.success=-1;
			left.direction='l';
			left.depth=left.depth+1;
			return left;
		}

		if(pos.red.second < pos.blue.second)
		{
			int i=pos.red.first;
			int j=pos.red.second;
			for(;left.b[i][j-1]!='#';j--)
			{
				if(left.b[i][j-1]=='O')
				{
					left.success=1;
					left.depth+=1;
					left.direction='l';
					return left;
				}
				left.b[i][j-1]='R';
				left.b[i][j]='.';
			}

			i=pos.blue.first;
			j=pos.blue.second;

			for(;left.b[i][j-1]!='#';j--)
			{
				if(left.b[i][j-1]=='O')
				{	
					left.depth=left.depth+1;
					left.success=-1;
					left.direction='l';
					return left;
				}

				if(left.b[i][j-1] == 'R')
					break;
			
				left.b[i][j-1]='B';
				left.b[i][j]='.';
			}
		}
		if(pos.red.second > pos.blue.second)
		{
			
			int i=pos.blue.first;
			int j=pos.blue.second;
			for(;left.b[i][j-1]!='#';j--)
			{
				if(left.b[i][j-1]=='O')
				{
					left.depth +=1;
					left.direction='l';
					left.success=-1;
					return left;
				}
				left.b[i][j-1]='B';
				left.b[i][j]='.';
			}
		
			i=pos.red.first;
			j=pos.red.second;

			for(;left.b[i][j-1]!='#';j--)
			{	
				if(left.b[i][j-1]=='O')
				{
					left.depth=left.depth+1;
					left.success=1;
					left.direction='l';
					return left;
				}

				if(left.b[i][j-1] == 'B')
					break;
			
				left.b[i][j-1]='R';
				left.b[i][j]='.';
			}
		}
	}
	left.depth=left.depth+1;
	left.direction='l';
	left.success=0;
	return left;
}


board right_board(board first)
{
	board right=first;
	ball pos=search_ball(first);
	if(pos.red.first != pos.blue.first)
	{
		
		int i=pos.red.first;
		int j=pos.red.second;
		for(;right.b[i][j+1]!='#';j++)
		{
			if(right.b[i][j+1] =='O')
			{
				right.depth=right.depth+1;
				right.success=1;
				right.direction='r';
				return right;
			}
			
			right.b[i][j+1]='R';
			right.b[i][j]='.';
		}

		i=pos.blue.first;
		j=pos.blue.second;

		for(;right.b[i][j+1]!='#';j++)
		{
			if(right.b[i][j+1] =='O')
			{
				right.success= -1;
				right.depth+=1;
				right.direction='r';
				return right;
			}

			right.b[i][j+1]='B';
			right.b[i][j]='.';
		}
	}
	else if(pos.red.first == pos.blue.first)
	{
		int i=pos.red.first;
		int j=pos.red.second;
		int count=0;
		for(;right.b[i][j+1]!='#';j++)
		{
			if(right.b[i][j+1] =='O')
				count++;
		}

		i=pos.blue.first;
		j=pos.blue.second;

		for(;right.b[i][j+1]!='#';j++)
		{
			if(right.b[i][j+1]=='O')
				count++;
		}

		if(count == 2){
			right.success=-1;
			right.direction='r';
			right.depth=right.depth+1;
			return right;
		}

		if(pos.red.second > pos.blue.second)
		{
			int i=pos.red.first;
			int j=pos.red.second;
			for(;right.b[i][j+1]!='#';j++)
			{
				if(right.b[i][j+1] =='O')
				{
					right.depth=right.depth+1;
					right.success=1;
					right.direction='r';
				}
				right.b[i][j+1]='R';
				right.b[i][j]='.';
			}
			
			i=pos.blue.first;
			j=pos.blue.second;

			for(;right.b[i][j+1]!='#';j++)
			{
				if(right.b[i][j+1] == 'R')
					break;

				if(right.b[i][j+1] =='O')
				{
					right.depth +=1;
					right.direction='r';
					right.success=-1;
					return right;
				}
			
				right.b[i][j+1]='B';
				right.b[i][j]='.';
			}
		}
		if(pos.red.second < pos.blue.second)
		{
			
			int i=pos.blue.first;
			int j=pos.blue.second;
			for(;right.b[i][j+1]!='#';j++)
			{
				if(right.b[i][j+1]=='O')
				{
					right.depth +=1;
					right.direction='r';
					right.success=-1;
					return right;
				}
				right.b[i][j+1]='B';
				right.b[i][j]='.';
			}

			i=pos.red.first;
			j=pos.red.second;

			for(;right.b[i][j+1]!='#';j++)
			{	
				if(right.b[i][j+1]=='O')
				{
					right.depth=right.depth+1;
					right.success=1;
					right.direction='r';
					return right;
				}

				if(right.b[i][j+1] == 'B')
					break;
			
				right.b[i][j+1]='R';
				right.b[i][j]='.';
			}
		}
	}
	right.depth=right.depth+1;
	right.direction='r';
	right.success=0;
	return right;
}

board up_board(board first)
{
	board up=first;
	ball pos=search_ball(first);
	if(pos.red.second != pos.blue.second)
	{
		int i=pos.red.first;
		int j=pos.red.second;
		for(;up.b[i-1][j]!='#';i--)
		{
			if(up.b[i-1][j] =='O')
			{
				up.depth=up.depth+1;
				up.success=1;
				up.direction='u';
				return up;
			}
			
			up.b[i-1][j]='R';
			up.b[i][j]='.';
		}

		i=pos.blue.first;
		j=pos.blue.second;

		for(;up.b[i-1][j]!='#';i--)
		{
			if(up.b[i-1][j] =='O')
			{
				up.success= -1;
				up.depth+=1;
				up.direction='u';
				return up;
			}

			up.b[i-1][j]='B';
			up.b[i][j]='.';
		}
	}
	else if(pos.red.second == pos.blue.second)
	{
		int i=pos.red.first;
		int j=pos.red.second;
		int count=0;
		for(;up.b[i-1][j]!='#';i--)
		{
			if(up.b[i-1][j] =='O')
				count++;
		}

		i=pos.blue.first;
		j=pos.blue.second;

		for(;up.b[i-1][j]!='#';i--)
		{
			if(up.b[i-1][j]=='O')
				count++;
		}

		if(count == 2){
			up.success=-1;
			up.direction='u';
			up.depth=up.depth+1;
			return up;
		}

		if(pos.red.first < pos.blue.first)
		{
			int i=pos.red.first;
			int j=pos.red.second;
			for(;up.b[i-1][j]!='#';i--)
			{
				if(up.b[i-1][j]=='O')
				{
					up.depth+=1;
					up.success=1;
					up.direction='u';
					return up;
				}
				up.b[i-1][j]='R';
				up.b[i][j]='.';
			}

			i=pos.blue.first;
			j=pos.blue.second;

			for(;up.b[i-1][j]!='#';i--)
			{
				if(up.b[i-1][j]=='O')
				{	
					up.depth=up.depth+1;
					up.success=-1;
					up.direction='u';
					return up;
				}

				if(up.b[i-1][j] == 'R')
					break;
			
				up.b[i-1][j]='B';
				up.b[i][j]='.';
			}
		}
		if(pos.red.first > pos.blue.first)
		{
			
			int i=pos.blue.first;
			int j=pos.blue.second;
			for(;up.b[i-1][j]!='#';i--)
			{
				if(up.b[i-1][j]=='O')
				{
					up.depth +=1;
					up.direction='u';
					up.success=-1;
					return up;
				}
				up.b[i-1][j]='B';
				up.b[i][j]='.';
			}
		
			i=pos.red.first;
			j=pos.red.second;

			for(;up.b[i-1][j]!='#';i--)
			{	
				if(up.b[i-1][j]=='O')
				{
					up.depth=up.depth+1;
					up.success=1;
					up.direction='u';
					return up;
				}

				if(up.b[i-1][j] == 'B')
					break;
			
				up.b[i-1][j]='R';
				up.b[i][j]='.';
			}
		}
	}
	up.depth=up.depth+1;
	up.direction='u';
	up.success=0;
	return up;
}

board down_board(board first)
{
	board down=first;
	ball pos=search_ball(first);
	if(pos.red.second != pos.blue.second)
	{
		
		int i=pos.red.first;
		int j=pos.red.second;
		for(;down.b[i+1][j]!='#';i++)
		{
			if(down.b[i+1][j] =='O')
			{
				down.depth=down.depth+1;
				down.success=1;
				down.direction='d';
				return down;
			}
			
			down.b[i+1][j]='R';
			down.b[i][j]='.';
		}

		i=pos.blue.first;
		j=pos.blue.second;

		for(;down.b[i+1][j]!='#';i++)
		{
			if(down.b[i+1][j] =='O')
			{
				down.success= -1;
				down.direction='d';
				down.depth+=1;
				return down;
			}

			down.b[i+1][j]='B';
			down.b[i][j]='.';
		}
	}
	else if(pos.red.second == pos.blue.second)
	{
		int i=pos.red.first;
		int j=pos.red.second;
		int count=0;
		for(;down.b[i+1][j]!='#';i++)
		{
			if(down.b[i+1][j] =='O')
				count++;
		}

		i=pos.blue.first;
		j=pos.blue.second;

		for(;down.b[i+1][j]!='#';i++)
		{
			if(down.b[i+1][j]=='O')
				count++;
		}

		if(count == 2){
			down.success=-1;
			down.direction='d';
			down.depth=down.depth+1;
			return down;
		}

		if(pos.red.first > pos.blue.first)
		{
			int i=pos.red.first;
			int j=pos.red.second;
			for(;down.b[i+1][j]!='#';i++)
			{
				if(down.b[i+1][j] =='O')
				{
					down.depth=down.depth+1;
					down.success=1;
					down.direction='d';
				}
				down.b[i+1][j]='R';
				down.b[i][j]='.';
			}
			
			i=pos.blue.first;
			j=pos.blue.second;

			for(;down.b[i+1][j]!='#';i++)
			{
				if(down.b[i+1][j] == 'R')
					break;

				if(down.b[i+1][j] =='O')
				{
					down.depth +=1;
					down.direction='d';
					down.success=-1;
					return down;
				}
			
				down.b[i+1][j]='B';
				down.b[i][j]='.';
			}
		}
		if(pos.red.first < pos.blue.first)
		{
			
			int i=pos.blue.first;
			int j=pos.blue.second;
			for(;down.b[i+1][j]!='#';i++)
			{
				if(down.b[i+1][j]=='O')
				{
					down.depth +=1;
					down.direction='d';
					down.success=-1;
					return down;
				}
				down.b[i+1][j]='B';
				down.b[i][j]='.';
			}

			i=pos.red.first;
			j=pos.red.second;

			for(;down.b[i+1][j]!='#';i++)
			{	
				if(down.b[i+1][j]=='O')
				{
					down.depth=down.depth+1;
					down.success=1;
					down.direction='d';
					return down;
				}

				if(down.b[i+1][j] == 'B')
					break;
			
				down.b[i+1][j]='R';
				down.b[i][j]='.';
			}
		}
	}
	down.depth=down.depth+1;
	down.direction='d';
	down.success=0;
	return down;
}










