#include<iostream>

using namespace std;

int T,D,W,K;
bool map[13][20];
bool tmp[13][20];
int min_value = 30;

bool check();
void DFS(int line,int depth);
int main(void)
{
	cin >> T;
	for(int t = 1; t<=T; t++)
	{	
		min_value = 30;
		cin >> D >> W >> K;
		
		for(int i = 0; i<D; i++)
			for(int j=0; j<W; j++)
			{
				cin >> map[i][j];
				tmp[i][j] = map[i][j];
			}

		DFS(-1,0);
		cout << "#" << t <<" " << min_value << endl;
	}
}
void DFS(int line,int depth)
{	
	if(check())
		min_value = min(min_value,depth);
	
	if(depth >= min_value-1)
		return;
	
	for(int i = line +1 ; i< D; i++)
	{
		for(int j=0; j<2; j++)
		{
			for(int k =0 ; k<W;k++)
				map[i][k] = j;
			
			DFS(i, depth+1);
			
			for(int k=0; k<W; k++)
				map[i][k] = tmp[i][k];
		}
	}
}
				
bool check()
{	
	int count=1;
	int ox = false;
	for(int i=0; i<W; i++)
	{
		count = 1;
		ox = false;
		for(int j=0; j<D-1; j++)
		{
			if(map[j][i] == map[j+1][i])
				count++;
			else
				count =1;

			if(count == K)
			{
				ox = true;
				break;
			}
		}
		
		if(!ox)
			return false;
	}
	return true;
}
