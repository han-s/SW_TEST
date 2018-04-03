#include<iostream>

using namespace std;
//북서남동
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
void segment_(int i, int x1, int x2, int y1, int y2);
//뱀의 위치
typedef struct s_pos{
	long long x;
	long long y;
	int dir;
	long long len;
}s_pos;

typedef struct segment{
	long long x1,x2,y1,y2;
}segment;
int main(void)
{
	int L; // 보드의 크기 - 2L + 1
	int N; // 머리의 방향 회전수
	cin >> L >> N;
	int time;// 시간
	char c_dir;// 방향_문자

	s_pos pos[N+2];
	pos[0].x = 0;
	pos[0].y = 0;
	pos[0].dir = 3;
	for(int i=1; i<=N; i++){
		cin >> time >> c_dir;
		pos[i-1].len = time;
		if(c_dir == 'L')
			pos[i].dir = (pos[i-1].dir+1) % 4;
		if(c_dir == 'R')
			pos[i].dir = (pos[i-1].dir+3) % 4;
	
		for(int j=0; j<3 ;j++)
		{
			if(j == dir[i-1])
			{
				pos[i].x = pos[i-1].x + dx[j]*time;
				pos[j].y = pos[j-1].y + dy[j]*time;
			}
		}
	}
	segment seg[N+5];
	
	segment_(0,-L,L,-L,-L);
	segment_(1,L,L,-L,L);
	segment_(2,L,-L,L,L);
	segment_(3,-L,-L,L,-L);
	
	
}

void segment_(int i, int x1, int x2, int y1, int y2)
{
	seg[i].x1 = x1;
	seg[i].x2 = x2;
	seg[i].y1 = y1;
	seg[i].y2 = t2;
}
