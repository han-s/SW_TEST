#include<iostream>
#include<queue>

bool check();

using namespace std;

int board[3][3];
int main(void)
{
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			cin >> board[i][j];


}

bool check()
{	
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			if(board[i][j] != i*3 + j + 1)
				return false;

	return true;
}
