#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void divide_num(int num);
int D(int num);
int S(int num);
int L();
int R();
int combine();

int before[10000]={0,};
char result[10000]={0,};
int temp[5] ={0,};
bool check[10000] = {0,};

int main(void)
{
	int T,A,B;
	cin >> T;
	int num=0;
	int B_reg=0;
	vector<char> v;
	queue<int> q;
	for(int i=0; i<T; i++)
	{	
		cin >> num;
		cin >> B_reg;
		q.push(num);
		check[num] =true;
		
		int tmp,tmp2;
		while(1)
		{
			tmp=q.front();
			tmp2=q.front();
			q.pop();
			if(tmp == B_reg)
				break;
			
			if(!check[D(tmp)]){
				tmp2 = D(tmp);
				check[tmp2] = true;
				result[tmp2] ='D';
				q.push(tmp2);
				before[tmp2] = tmp;
				tmp2 = tmp;
				
			}
			if(!check[S(tmp)]){
				tmp2 = S(tmp);
				check[tmp2] = true;
				result[tmp2] = 'S';
				q.push(tmp2);
				before[tmp2] = tmp;
				tmp2 = tmp;
			}
			divide_num(tmp);
			tmp2 = L();
			if(!check[tmp2]){
				
				check[tmp2] = true;
				result[tmp2] = 'L';
				q.push(tmp2);
				before[tmp2] = tmp;
				tmp2 = tmp;
			}
			divide_num(tmp);
			tmp2 = R();
			if(!check[tmp2]){
				check[tmp2] = true;
				result[tmp2] = 'R';
				q.push(tmp2);
				before[tmp2] = tmp;
				tmp2 = tmp;
			}
		}
		
		while(num != tmp)
		{
			v.push_back(result[tmp]);
			tmp = before[tmp];
		}
		while(!q.empty())q.pop();
		for(int j=0; j<10000;j++)
		{
			before[j] = 0;
			result[j] = 0;
			check[j] = false;
		}
		for(int j=v.size()-1; j>=0; j--)
			cout << v[j];
	
		cout << endl;
		v.clear();
	}
	/*
	for(int i=0; i<T; i++)
	{
			for(int j=v[i].size()-1; j>=0; j--)
				cout << v[i][j];
	
			cout << endl;
			
	}
	*/		
}	

void divide_num(int num)
{
	for(int i=4; i>=1; i--)
	{
		temp[i] = num%10;
		num = num/10;
	}
}

int D(int num)
{	
	if(num*2 >= 10000)
		return (num*2)%10000;
	return num*2;
}

int S(int num)
{
	if(num == 0)
		return 9999;
	return num-1;
}

int L()
{
	int tmp = temp[1];
	for(int i=1; i<=3;i++)
		temp[i] = temp[i+1];
	temp[4] = tmp;
	return combine(); 
}

int R()
{
	int tmp = temp[4];
	for(int i=4; i>=2; i--)
		temp[i] =temp[i-1];
	temp[1] = tmp;
	return combine();
}

int combine()
{
	int result=0;
	for(int i=1; i<=4; i++)
		result = result*10 + temp[i];
	return result;
}

