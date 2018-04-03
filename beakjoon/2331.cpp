#include<iostream>
#include<math.h>
using namespace std;

void DFS(int a, int n);


typedef struct seq
{
	bool check=false;
	int num=0;
}seq;

int A, P;
seq s[1000000];

int main(void)
{
	cin >> A >> P;
	DFS(A,1);
}

void DFS(int a, int n)
{
	if(s[a].check)
	{
		cout << s[a].num-1 << endl;
		return;
	}
	s[a].check =true;
	s[a].num =n;
	int total=0;
	while(a>0)
	{
		total = total + pow(a%10,P);
		a=a/10;
	}
	DFS(total, n+1);
}
