#include<iostream>

using namespace std;

int main(void)
{
	double n;
	cin >> n;
	int c[32] = {0, };
	int count =0;
	while(1)
	{	
		if(count == 32){
			cout << "error" ;
			return 0;
		}

		n *=2;
		if(n>=1)
		{
			c[count++] = 1;
			n -= 1 ;
			//cout << n << endl;
			if(n == 0.0)
				break;
		}
		else
		{
			c[count++] = 0;
		}
		
	}
	for(int i=0; i<count; i++)
		cout << c[i] ;

	cout << endl;
	return 0;
}

		
		
