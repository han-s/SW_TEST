#include<iostream>

using namespace std;
int T;
int N,M,C;
int map[10][10];
int tong_size = 0;
int tong[5] = {0,};
int tong2[5] = {0,};
int result = 0;
int total = 0;
int total_result = 0;
bool check[10][10] ={false,};
void DFS(int y, int x, int depth, int pos);
int main(void)
{
	int cnt=0;
	bool ox=false;
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		cin >> N >> M >> C;
		total_result = 0;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				cin >> map[i][j];

		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(j+M > N)
					break;
				
				for(int k=0; k<M; k++)				
					check[i][j+k] = true;

				result = 0;
				DFS(i,j,0,-1);
				total = result;
				
				for(int q=i; q<N; q++)
					for(int w=0; w<N; w++)
					{
						ox = false;
							
						if(w+M > N)
							break;
						for(int e=0 ;e<M; e++)
							if(check[q][w+e])
							{
								ox = true;
								break;
							}
						
						if(ox)
							continue;

						result = 0;
						DFS(q,w,0,-1);
						total = total +result;
						total_result = max(total_result, total);
						total = total - result;
					}

				for(int k=0; k<M; k++)
					check[i][j+k] = false;
			}
		}
		cout << "#" << t << " " << total_result << endl;
	}
}
void DFS(int y, int x, int depth, int pos)
{	
	int tmp=0;
	for(int i=0; i<M; i++)
	{
		tmp = tmp + tong[i]*tong[i];
		result = max(result, tmp);
	}
	if(depth == M)
		return;
	
	for(int i = pos+1 ; i<M; i++)
	{	
		if(tong_size + map[y][x+i] > C)
			continue;
		
		tong[depth] = map[y][x+i];
		tong_size = tong_size + map[y][x+i];
		DFS(y,x,depth+1, i); 
		tong_size = tong_size - map[y][x+i];
		tong[depth] = 0;
	}

}
