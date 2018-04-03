#include<iostream>

using namespace std;

int N,M;
int board[501][501];

int oneToFour();
int twoToThree(int);
int twoToTwo(int);
int square(int);

int main(void)
{
	int i, j, result=0;
	cin >> N >> M;

	for(i=1; i<=N; i++)
		for(j=1; j<=M; j++)
			cin >> board[i][j];

	result = oneToFour();
	result = twoToThree(result);
	result = twoToTwo(result);and
	result = square(result);

	cout << result <<endl;

}

int oneToFour()
{	
	int result=0;
	for(int i=1; i<=N; i++)
	{
		for(int j=1; j<=M-3; j++)
		{
			if(result < board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3])
				result = board[i][j] + board[i][j+1] + board[i][j+2] + board[i][j+3];
		}
	}

	for(int i=1; i<=M; i++)
	{
		for(int j=1; j<=N-3; j++)
		{
			if(result < board[j][i]+board[j+1][i]+board[j+2][i]+board[j+3][i])
				result = board[j][i] + board[j+1][i] + board[j+2][i] + board[j+3][i];
		}
	}
	
	return result;

}

int twoToThree(int temp)
{
	int result = temp;
	for(int i=1; i<=N-1; i++)
		for(int j=1; j<=M-2; j++)
		{
			if(result < board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j])
				result = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j];

			if(result < board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1])
				result = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+1];

			if(result < board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+2])
				result = board[i][j] + board[i][j+1] + board[i][j+2] + board[i+1][j+2];
			
			if(result < board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+1][j+2])
				result = board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j];

			if(result < board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+1])
				result = board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+1];

			if(result < board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+2])
				result = board[i+1][j] + board[i+1][j+1] + board[i+1][j+2] + board[i][j+2];
		}

	for(int i=1; i<=M-1; i++)
		for(int j=1; j<=N-2; j++)
		{
			if(result < board[j][i] + board[j+1][i] + board[j+2][i] + board[j][i+1])
				result = board[j][i] + board[j+1][i] + board[j+2][i] + board[j][i+1];

			if(result < board[j][i] + board[j+1][i] + board[j+2][i] + board[j+1][i+1])
				result = board[j][i] + board[j+1][i] + board[j+2][i] + board[j+1][i+1];

			if(result < board[j][i] + board[j+1][i] + board[j+2][i] + board[j+2][i+1])
				result = board[j][i] + board[j+1][i] + board[j+2][i] + board[j+2][i+1];
			
			if(result < board[j][i] + board[j][i+1] + board[j+1][i+1] + board[j+2][i+1])
				result = board[j][i+1] + board[j+1][i+1] + board[j+2][i+1] + board[j][i];

			if(result < board[j][i+1] + board[j+1][i+1] + board[j+2][i+1] + board[j+1][i])
				result = board[j][i+1] + board[j+1][i+1] + board[j+2][i+1] + board[j+1][i];

			if(result < board[j][i+1] + board[j+1][i+1] + board[j+2][i+1] + board[j+2][i])
				result = board[j][i+1] + board[j+1][i+1] + board[j+2][i+1] + board[j+2][i];
		}
	return result;
}
			
int twoToTwo(int temp)
{
	int result = temp;
	for(int i=1; i<=N-1; i++)
		for(int j=1; j<=M-2; j++)
		{
			if(result < board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+1][j+2])
				result = board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+1][j+2];

			if(result < board[i+1][j] + board[i+1][j+1] + board[i][j+1] + board[i][j+2])
				result = board[i+1][j] + board[i+1][j+1] + board[i][j+1] + board[i][j+2];
		}
	for(int i=1; i<=M-1; i++)
		for(int j=1; j<=N-2; j++)
		{
			if(result < board[j][i] + board[j+1][i] + board[j+1][i+1] + board[j+2][i+1])
				result = board[j][i] + board[j+1][i] + board[j+1][i+1] + board[j+2][i+1];

			if(result < board[j][i+1] + board[j+1][i+1] + board[j+1][i] + board[j+2][i])
				result = board[j][i+1] + board[j+1][i+1] + board[j+1][i] + board[j+2][i];
		}

	return result;
}

int square(int temp)
{
	int result = temp;
	for(int i=1; i<=N-1; i++)
		for(int j=1; j<=M-1; j++)
		{
			if(result < board[i][j] + board[i][j+1] + board[i+1][j] + board[i+1][j+1])
				result = board[i][j] + board[i][j+1] + board[i+1][j] + board[i+1][j+1];
		}
	return result;
}



			


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
