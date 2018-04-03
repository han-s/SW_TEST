#include<iostream>
#include<map>

using namespace std;

int main(void)
{
	int n, a;
	map<int,int> bs;
	cin >> n;
	for(int i=1; i<=n;i++)
	{
		cin >> a;
		bs[a]=i;
	}
	cin >>a;
	if(bs.find(a)!= bs.end())
		cout<<bs[a] <<endl;
	else
		cout<<"not found"<<endl;
	return 0;
}
