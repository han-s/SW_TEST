#include<iostream>
#include<utility>
#include<queue>

using namespace std;

typedef struct board{
	int b[21][21];
	int depth;
}board;

int main(void)
{
	int n, result = 0;
	cin >> n;
	board bd;
	bd.depth=0;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin >> bd.b[i][j];
	
	queue<board> q;
	q.push(bd);
	
	while(1)
	{
		
		bd = q.front();
		q.pop();
		if(n==1){
			result=bd.b[1][1];
			break;
		}
		/*
		cout << endl << "depth : " << bd.depth << endl;
		
		for(int i=1 ; i<=n; i++){
			cout << endl;
			for(int j=1; j<=n; j++)
				cout << bd.b[i][j] << " ";
		}
		*/
		if(bd.depth==5)
		{
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					if(bd.b[i][j] > result)
						result=bd.b[i][j];
		}
		else
		{	
			board bd1 = bd;
			board bd2 = bd;
			board bd3 = bd;
			board bd4 = bd;

			for(int i=1; i<=n; i++)
			{	
				int z=1;
				int t=n;
				for(int j=1; j<n; j++)
				{	
					
					if(bd1.b[i][z] == 0)
					{	
						for(int k=z; k<n; k++)
							bd1.b[i][k]=bd1.b[i][k+1];

						bd1.b[i][t]=0;
						if(j<t)
						t--;
						
					}
					else
						z++;
				}
				z=1;
				t=n;
		//		cout << endl;
		//		cout << endl;
		//		cout << i << endl;
		//		for(int j=1; j<=n; j++)
		//			cout << bd1.b[i][j] << " ";
				
						
				for(int j=1; j<n; j++)
				{	
					if(bd1.b[i][j] == bd1.b[i][j+1])
					{
						bd1.b[i][j] *= 2;
						bd1.b[i][j+1] = 0;
						j++;
					}
				}
				for(int j=1; j<n; j++)
				{	
					
					if(bd1.b[i][z] ==0)
					{
						for(int k=z; k<n; k++)
							bd1.b[i][k] = bd1.b[i][k+1];

						bd1.b[i][t]=0;
						if(j<t)
						t--;
					}
					else
						z++;
				}
			}

			for(int i=1; i<=n; i++)
			{	
				int z=n;
				int t=1;
				
				for(int j=n; j>1; j--)
				{	
					if(bd2.b[i][z] == 0)//
					{	
						for(int k=z; k>1; k--)
							bd2.b[i][k]=bd2.b[i][k-1];

						bd2.b[i][t]=0;
						if(t<j)
						t++;
					}
					else
						z--;
				}
				z=n;
				t=1;
				for(int j=n; j>1; j--)
				{	
					if(bd2.b[i][j] == bd2.b[i][j-1])
					{
						bd2.b[i][j] *= 2;
						bd2.b[i][j-1] = 0;
						j--;
					}
				}
				for(int j=n; j>1; j--)
				{	
					
					if(bd2.b[i][z] ==0)
					{
						for(int k=z; k>1; k--)
							bd2.b[i][k] = bd2.b[i][k-1];

						bd2.b[i][t]=0;
						if(t<j)
						t++;
					}
					else
						z--;
				}
			}

			for(int i=1; i<=n; i++)
			{	
				int z=n;
				int t=1;
				for(int j=n; j>1; j--)
				{	
					
					if(bd3.b[z][i] == 0)//
					{	
						for(int k=z; k>1; k--)
							bd3.b[k][i]=bd3.b[k-1][i];

						bd3.b[t][i]=0;
						if(t<j)
							t++;
					}
					else
						z--;
				}
				z=n;
				t=1;
				for(int j=n; j>1; j--)
				{	
					if(bd3.b[j][i] == bd3.b[j-1][i])
					{
						bd3.b[j][i] *= 2;
						bd3.b[j-1][i] = 0;
						j--;
					}
				}
				
				for(int j=n; j>1; j--)
				{	
					
					if(bd3.b[z][i] ==0)
					{
						for(int k=z; k>1; k--)
							bd3.b[k][i] = bd3.b[k-1][i];
		
						bd3.b[t][i]=0;
						if(t<j)			
						t++;
					}
					else
						z--;
				}
			}

			for(int i=1; i<=n; i++)
			{	
				int z=1;
				int t=n;
				for(int j=1; j<n; j++)
				{	
					
					if(bd4.b[z][i] == 0)
					{	
						for(int k=z; k<n; k++)
							bd4.b[k][i]=bd4.b[k+1][i];

						bd4.b[t][i]=0;
						if(t>=j)
						t--;
					}
					else
						z++;
				}
				z=1;
				t=n;
				for(int j=1; j<n; j++)
				{	
					if(bd4.b[j][i] == bd4.b[j+1][i])
					{
						bd4.b[j][i] *= 2;
						bd4.b[j+1][i] = 0;
						j++;
					}
				}
				for(int j=1; j<n; j++)
				{	
					
					if(bd4.b[z][i] ==0)
					{
						for(int k=z; k<n; k++)
							bd4.b[k][i] = bd4.b[k+1][i];

						bd4.b[t][i]=0;
						if(t>=j)
						t--;
					}
					else
						z++;
				}
			}
			bd1.depth = bd1.depth + 1;
			bd2.depth = bd2.depth + 1;
			bd3.depth = bd3.depth + 1;
			bd4.depth = bd4.depth + 1;
	/*		
		cout << endl << "left" << endl;	
		for(int i=1 ; i<=n; i++){
			cout << endl;
			for(int j=1; j<=n; j++)
				cout << bd1.b[i][j] << " ";
		}
		cout << endl << "right" << endl;	
		for(int i=1 ; i<=n; i++){
			cout << endl;
			for(int j=1; j<=n; j++)
				cout << bd2.b[i][j] << " ";
		}
		cout << endl << "down" << endl;	
		for(int i=1 ; i<=n; i++){
			cout << endl;
			for(int j=1; j<=n; j++)
				cout << bd3.b[i][j] << " ";
		}
		cout << endl << "up" << endl;	
		for(int i=1 ; i<=n; i++){
			cout << endl;
			for(int j=1; j<=n; j++)
				cout << bd4.b[i][j] << " ";
		}
		*/
			q.push(bd1);
			q.push(bd2);
			q.push(bd3);
			q.push(bd4);
		}
		if(q.empty())
			break;
	}
	cout << result << endl;

	return 0;
}	
