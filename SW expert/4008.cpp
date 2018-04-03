#include<iostream>

using namespace std;

int operate[4];
long num[12];
int N,T;
long Max=-100000001;
long Min=100000000;
int expression[11];
void DFS(int depth);
long operation();

int main(void)
{
	cin >> T;
	for(int t=1; t<=T; t++)
	{	
		cin >> N;
		Max=-100000001;
		Min=100000000;

		for(int i=0; i<4; i++)
			cin >> operate[i];
		
		for(int i=0; i<N; i++)
			cin >> num[i];

		DFS(0);
		cout << "#" << t << " " << Max-Min << endl;
		
	}
}

void DFS(int depth)
{	
	if(depth == N-1)
	{	
		long tmp = operation();
		if(tmp>Max)
			Max =tmp;
	
		if(tmp<Min)
			Min = tmp;
		
	}
	for(int i=0; i<4; i++)
	{
		if(operate[i])
		{
			operate[i]--;
			expression[depth] = i;
			DFS(depth+1);
			operate[i]++;
		}
	}
}

long operation()
{	
	long result = num[0];
	for(int i=0; i<N-1; i++)
	{
		if(expression[i] == 0)
			result = result + num[i+1];
		if(expression[i] == 1)
			result = result - num[i+1];
		if(expression[i] == 2)
			result = result * num[i+1];
		if(expression[i] == 3)
			result = result / num[i+1];
	}
	return result;
}
