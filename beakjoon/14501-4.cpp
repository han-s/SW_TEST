#include<iostream>
int dp[25];

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i=0; i<n;i++)
	{
		int t,p;
		cin >> t >> p;

		if(dp[i] > dp[i+1])
			dp[i+1] = dp[i];
		if(dp[i+t] < dp[i] + p)
			dp[i+t] = dp[i] +p;
	}

	cout << dp[n] << endl;
	return 0;
}
