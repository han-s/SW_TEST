#include<iostream>
#include<stdio.h>
int recursiveMap(int r, int c);
char map[11][11];
int loop[11][11]={0,};
int cnt=0;
int count_loop=0;

using namespace std;
int main(void)
{
	int r=0,c=0,s=0;
	int result=0;
	cin >> r >> c >> s;

	for(int i=1; i<=r;i++)
		for(int j=1; j<=c;j++)
			cin >> map[i][j];

	result=recursiveMap(1,s);
	
	if(result==0)
		printf("%d step(s) to exit\n", cnt);
	else if(result==100)
		printf("%d step(s) before a loop of %d step(s)\n", cnt-count_loop, count_loop);
}

int recursiveMap(int r, int c){
	
	int result=0;
	if(loop[r][c] == 0){
		loop[r][c] =1;
		if(map[r][c]=='\0'){
			return 0;
		}
		cnt++;
	}
	else{
		count_loop++;
		loop[r][c]=100;
		return 0;
	}
	
	switch(map[r][c]){
		case 'N':
			result = recursiveMap(r-1,c);
			break;
		case 'S':
			result = recursiveMap(r+1,c);
			break;
		case 'W':
			result = recursiveMap(r,c-1);
			break;
		case 'E':
			result = recursiveMap(r,c+1);
			break;
	}
	if(result==100)
		return 100;

	if(loop[r][c]==100)
		return 100;
	else
		count_loop++;

	return 0;
}
	
