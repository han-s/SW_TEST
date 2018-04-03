#include<iostream>
#include<math.h>

using namespace std;

int main(void)
{	
	bool check1=true, check2=true;
	int N, L, result=0;
	int k=0;
	cin >> N >> L;
	int load[N+1][N+1];
	bool check_load[N+1][N+1]={0,};
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			cin >> load[i][j];
	
	for(int i=1; i<=N; i++)
	{	
		check1 = true;
		check2 = true;

		for(int j=1; j<N; j++)
		{
			if(abs(load[i][j]-load[i][j+1]) > 1)
			{
				check1 = false;
				break;
			}
			if(load[i][j]>load[i][j+1])
			{	
				if(j+L > N)
				{
					check1 =false;
					break;
				}
				if(check_load[i][j+1])
				{
					check1 = false;
					break;
				}
				else
					check_load[i][j+1] = true;

				for(int k = j+1 ; k<j+L; k++)
				{	
					if(load[i][k] != load[i][k+1] || check_load[i][k+1])
					{	
						check2 = false;
						break;
					}
					check_load[i][k+1]=true;
				}
			}
			else if(load[i][j]<load[i][j+1])
			{	
				if((j-L+1) < 1)
				{
					check1 = false;
					break;
				}
				if(check_load[i][j])
				{
					check1 = false;
					break;
				}
				else
					check_load[i][j] = true;

				for(k=j; k>j-L+1; k--)
				{	
					if(load[i][k] != load[i][k-1]  || check_load[i][k-1])
					{	
						check2 = false;
						break;
					}
					check_load[i][k-1] = true;
				}
			}
			if(!check2)
			{
				check1 = false;
				break;
			}
		}
		if(check1)
		{
			result++;
		}
	}

	for(int i=0 ;i<=N; i++)
		for(int j=0; j<=N; j++)
			check_load[i][j] = false;

	for(int i=1; i<=N; i++)
	{	
		check1 = true;
		check2 = true;

		for(int j=1; j<N; j++)
		{
			if(abs(load[j][i]-load[j+1][i]) > 1)
			{
				check1 = false;
				break;
			}
			if(load[j][i]>load[j+1][i])
			{	
				if(j+L > N)
				{
					check1 =false;
					break;
				}
				if(check_load[j+1][i])
				{
					check1 = false;
					break;
				}
				else
					check_load[j+1][i] = true;

				for(int k = j+1 ; k<j+L; k++)
				{	
					if(load[k][i] != load[k+1][i] || check_load[k+1][i])
					{
						check2 = false;
						break;
					}
					check_load[k+1][i]=true;
				}
			}
			else if(load[j][i]<load[j+1][i])
			{	
				if((j-L+1) < 1)
				{
					check1 = false;
					break;
				}
				if(check_load[j][i])
				{
					check1 = false;
					break;
				}
				else
					check_load[j][i] = true;
				for(k=j; k>j-L+1; k--)
				{	
					if(load[k][i] != load[k-1][i]  || check_load[k-1][i])
					{
						check2 = false;
						break;
					}
					check_load[k-1][i] = true;
				}
			}
			if(!check2)
			{
				check1 = false;
				break;
			}
		}
		if(check1)
		{	
			result++;
		}
	}
	cout << result << endl;
	return 0;
}




