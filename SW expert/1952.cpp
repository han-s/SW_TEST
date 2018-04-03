#include<iostream>

using namespace std;

int T;
int price[4];
int month[13];
int total_money=1000000;

void DFS(int mon, int money);

int main(void)
{
	cin >> T;
	for(int t=0; t<T; t++)
	{

		for(int i=0; i<4; i++)
			cin >> price[i];

		for(int i=1; i<13; i++)
			cin >> month[i];

		total_money = price[3];					
		DFS(1,0);

		
		cout << "#" <<t+1<< " " <<total_money << endl;
	}
}

void DFS(int mon, int money)
{
	if(mon>12)
	{
		if(total_money > money)
			total_money = money;

		return;
	}
	
	if(money > total_money)
		return;

	int temp;

	for(int i=0; i<4; i++)
	{
		temp = money;
		
		if(i==0)
		{
			temp = temp + month[mon] * price[i];
			DFS(mon+1, temp);
		}
		else if(i==1)
		{
			temp = temp + price[i];
			DFS(mon+1, temp);
		}
		else if(i==2)
		{
			temp = temp + price[i];
			DFS(mon+3, temp);
		}
	}
}
