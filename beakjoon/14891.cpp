#include<iostream>
#include<queue>

using namespace std;

typedef struct wheel
{
	bool wh[5][9];
	int t_tmp[4] = {3, };
}wheel;

typedef struct turn
{
	int dir;
	int num;
}turn;

int cnt=1;
wheel w;
turn t[k+1];
bool ox[4];
int main(void)
{
	wheel w;
	int k;
	int cnt=1;
	for(int i=1; i<=4 ; i++)
		for(int j=1; j<=8; j++)
			cin >> w.wh[i][j];

	cin >> k;
	turn t[k+1];
	for(int i=1; i<=k; i++)
	{
		cin >> t[i].num >> t[i].dir ;
		dfs(num);
	}	
}

void dfs(int num, int k)
{
	if(n==5)
		return;

}

void cha(int num)
{
	if(num==1)
	{
		if(w.wh[0][tmp] == w.wh[1][(tmp+4)%9])
		{
			tmp[0] = tmp[0] - t[cnt].dir;
			cnt++;
		}
		else
		{
			tmp[0] = tmp[0] - t[cnt].dir;
			tmp[1] = tmp[1] + t[cnt].dir;

		}
	}
}
void check()
{
	if(w.wh[0][tmp] == w.wh[0][(tmp+4)%9])
		ox[0] = 
}






