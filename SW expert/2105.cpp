#include<iostream>
#include<vector>
bool check[101] ={false,};
int dx[4] = {-1,1,1,-1};
int dy[4] = {1,1,-1,-1};
int length[2];
int N;
int T;
int map[20][20];
int f_posx, f_posy;
int result = 0;
std::vector<int> v;
using namespace std;
void DFS(int y, int x, int dir);

int main(void)
{
	cin >> T;
	for(int t = 1 ; t<=T; t++)
	{
		cin >> N;
		for(int i = 0 ; i<N; i++)
			for(int j = 0; j<N; j++)
				cin >> map[i][j];

		
		for(int i=0; i<N-1; i++)
			for(int j=1; j<N-1; j++)
			{
				length[0]=0;
				length[1]=1;
				v.push_back(map[i][j]);
				f_posy = i;
				f_posx = j;
				DFS(i,j,0);
				v.clear();
			}
	}
	cout << result << endl;
}

void DFS(int y, int x, int dir)
{	
//	cout << " x : " << x << " " << "y: "<< y << " " << dir << endl;
//	for(int i=0; i<v.size(); i++)
//		cout << v[i] << " ";

//	cout<<endl;
	//cout << " x : " << x << " " << "y : " << y << endl;
	//cout << dir << endl;
	int new_y = y;
	int new_x = x;
	if(dir == 2)
	{	
		int cnt = 0;
		for(int j=0; j<2; j++)
		{	

			int length1 = length[j];
			while(length1--)
			{	
				new_y = new_y + dy[dir+j];
				new_x = new_x + dx[dir+j];
				if(new_y <0 || new_x <0 || new_y >=N || new_x >=N)
					return;
				//cout << " x : " << new_x << " " << "y : " << new_y << endl;
				for(int i=0; i<v.size(); i++)
					if(map[new_y][new_x] == v[i])
					{	
						if(new_y == f_posy && new_x == f_posx)
						{	
							result = max(result, 2*(length[0] + length[1]-1));
							cout << "!!!"<<new_x << " " << new_y<<" "<<length[0] << " " << length[1] << " " <<  endl;
						}
						while(cnt--)
							v.pop_back();	
						return;
					}
				v.push_back(map[new_y][new_x]);
				cnt++;
				
			}

		}			
	}
	new_y = y + dy[dir];
	new_x = x + dx[dir];

	while(!(new_y <0 || new_x<0 || new_y>=N || new_x>=N))
	{	
		for(int i=0; i<v.size(); i++)
			if(v[i] == map[new_y][new_x])
			{
				return;
			}
		
		if(dir == 0)
		{	
			length[0]++;
			v.push_back(map[new_y][new_x]);
			DFS(new_y,new_x,dir+1);
		}
		else if(dir == 1)
		{
			v.push_back(map[new_y][new_x]);
			length[1]++;
			DFS(new_y,new_x,dir+1);
			if(new_y+dy[dir]<0 || new_x+dx[dir] <0 || new_y+dy[dir] >=N || new_x+dx[dir] >=N)
				while(--length[1])
				{
//					cout << v[v.size()-1];
					v.pop_back();
				}
		}
		
		new_y = new_y + dy[dir];
		new_x = new_x + dx[dir];
	}

}
