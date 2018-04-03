#include<iostream>
using namespace std;

int main(void)
{
	int n=0, b=0, c=0;
	long long total = 0;
	cin >> n;
	int exam[n+1];
	for(int i=1; i<=n; i++)
		cin >> exam[i];

	cin >> b >> c;

	for(int i=1; i<=n; i++)
	{
		exam[i]=exam[i]-b;

		if(exam[i]%c!=0 && exam[i]>=0)
			exam[i] = exam[i]/c +1;
		else if(exam[i]%c == 0 && exam[i] >=0)
			exam[i] = exam[i]/c;
		
		if(exam[i] >= 0)
			total = total + exam[i] + 1;
		else
			total = total + 1 ;
	}

	cout << total <<endl;
}
