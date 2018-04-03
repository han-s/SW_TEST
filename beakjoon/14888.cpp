#include<iostream>

using namespace std;

int N;
int op[4]; // [ + - * / ] 
int res_op[11]; //연산자 순서
long max_result=-1000000001;
long min_result=1000000001;
int num[12];

long operation();
void dfs(int n);

int main(void)
{
	cin >> N ;
	for(int i=1; i<= N ; i++)
		cin >> num[i];
	
	for(int i=0; i<4; i++)
		cin >> op[i] ;

	dfs(1);
	
	cout << max_result << endl << min_result << endl;

}

void dfs(int n)
{
	if(n == N)
	{
		long result = operation();
		if(result > max_result)
			max_result = result;
		if(result < min_result)
			min_result = result;

		return;
	}
	
	for(int j=0; j<4; j++)
	{
		if(op[j] == 0)
			continue;			
		res_op[n] = j;
		op[j]--;
		dfs(n+1);
		op[j]++;
	}
}		
	
long operation()
{
	long r,r2;
	long result;
	for(int i=1 ; i<N ;i++)
	{
		if(i == 1)
		{
			r = num[i];
			r2 = num[i+1];
		}
		else
		{
			r = result;
			r2 = num[i+1];
		}
		if(res_op[i] == 0)
			result = r + r2;
		if(res_op[i] == 1)
			result = r - r2;
		if(res_op[i] == 2)
			result = r * r2;
		if(res_op[i] == 3)
			result = r/r2;
	}
	return result;
}
			
