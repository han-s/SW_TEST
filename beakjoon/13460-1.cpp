#include<iostream>
#include<queue>

using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

typedef struct board{
	int depth, rx, ry,bx, by;
}board;

bool check[11][11][11][11];
char b[11][11];

int main(void)
{
	int N,M,i,j;
	queue<board> q;
	board bo;
	bo.depth=0;
	cin >> N >> M;
	for(i=1; i<=N ; i++)
		for(j=1; j<=M; j++)
		{
			cin >> b[i][j];
			if(b[i][j] == 'B')
				bo.bx=i, bo.by=j;

			if(b[i][j] == 'R')
				bo.rx=i, bo.ry=j;
		}
	check[bo.rx][bo.ry][bo.bx][bo.by]=true;
	q.push(bo);
    
	while(!q.empty())
	{	
		board tmp=q.front();
		q.pop();

		for(int i=0;i<4; i++)
		{
			int rc=0, rb=0;
			int nrx=tmp.rx, nry=tmp.ry, nbx=tmp.bx, nby=tmp.by;
			while(b[nrx+dx[i]][nry+dy[i]] != '#' && b[nrx][nry] !='O')
			{	
				nrx=nrx+dx[i];
				nry=nry+dy[i];
				rc++;
			}
            
			while(b[nbx+dx[i]][nby+dy[i]] != '#' && b[nbx][nby] !='O')
			{	
				nbx=nbx+dx[i];
				nby=nby+dy[i];
				rb++;
			}
			
			if(nrx==nbx && nry == nby)
			{
				if(b[nrx][nry]=='O')
					continue;

				if(rc > rb)
				{
					nrx=nrx-dx[i];
					nry=nry-dy[i];
				}
				else if(rc < rb)
				{
					nbx=nbx-dx[i];
					nby=nby-dy[i];
				}
			}
            
			if(b[nrx][nry] == 'O'){
                cout<<tmp.depth+1<<endl;
	            return 0;
            }
            else if(b[nbx][nby] == 'O')
				continue;
            
			if(check[nrx][nry][nbx][nby])
				continue;
			if(tmp.depth<9){
				check[nrx][nry][nbx][nby]=1;
			    board w={tmp.depth+1,nrx,nry,nbx,nby};
				q.push(w);
			}
		
		}
	}
    
	cout << "-1" << endl;
	return 0;
}
	





