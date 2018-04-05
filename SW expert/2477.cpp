#include<iostream>
#include<queue>

using namespace std;

int N,M,T,K,A,B;
int reception_time[21];
int reception_tmp[21];
int repair_time[21];
int repair_tmp[21];
int reception_customer[21];
int repair_customer[21];
int person_start[1001];
int using_desk[1001][2];
int result = 0;
queue<int> q;
queue<int> q2;

void DFS(int time);

int main(void)
{
	cin >> T;
	result = 0;
	for(int t=1; t<=T; t++)
	{
		result = 0;
		cin >> N >> M >> K >> A >> B;
		for(int i=1; i<=N; i++)
		{
			cin >> reception_time[i];
			reception_tmp[i] = reception_time[i];
		}
		for(int i=1; i<=M; i++)
		{
			cin >> repair_time[i] ;
			repair_tmp[i] = repair_time[i];
		}
		for(int i=1; i<=K;i++)
			cin >> person_start[i];
		
		DFS(0);
		for(int i=1; i<=K; i++)
			if(using_desk[i][0] == A && using_desk[i][1] == B)
				result = result + i;
		if(result == 0)
			result = -1;
		cout << "#" <<t<< " " << result << endl;
	}
}

void DFS(int time)
{
	for(int i=1; i<=K; i++)
	{
		if(time == person_start[i])
		{
			q.push(i);
		}
	}
	for(int i=1 ;i<=M; i++)
	{
		if(repair_customer[i] == 0)
			continue;

		if(repair_time[i] > 0)
			repair_time[i]--;
		
		if(repair_time[i] ==0)
		{
			using_desk[repair_customer[i]][1] =	i;
			repair_customer[i]=0;
		}
	}
	for(int i=1 ; i<=N; i++)
	{
		if(reception_customer[i] == 0)
			continue;

		if(reception_time[i] > 0)
			reception_time[i]--;
		
		if(reception_time[i] ==0)
		{
			using_desk[reception_customer[i]][0] =i;
			q2.push(reception_customer[i]);
			reception_customer[i]=0;
		}
	}
	int tmp=0;
	bool ox = true;
	while(!q.empty())
	{	
		ox = true;
		tmp=q.front();
		for(int i=1; i<=N; i++)
		{	

			if(reception_customer[i] == 0)
			{
				reception_customer[i] = tmp;
				reception_time[i] = reception_tmp[i];
				q.pop();
				ox = false;
				break;
			}
		}
		if(ox)
			break;
	}

	while(!q2.empty())
	{	
		ox=true;	
		tmp=q2.front();
		for(int i=1; i<=M; i++)
		{	

			if(repair_customer[i] == 0)
			{
				repair_customer[i] = tmp;
				repair_time[i] = repair_tmp[i];
				q2.pop();
				ox = false;
				break;
			}
		}
		if(ox)
			break;
	}
	
	ox = true;
	bool ox2 = true;
	for(int i=1; i<=N; i++)
	{
		if(reception_customer[i]!=0)
		{
			ox = false;
			break;
		}
	}
	for(int i=1; i<=M; i++)
	{
		if(repair_customer[i]!=0)
		{
			ox = false;
			break;
		}
	}
	
	if(ox && ox2 && q.empty() && q2.empty() && person_start[K] <= time)
		return;
	
	DFS(time+1);
}
