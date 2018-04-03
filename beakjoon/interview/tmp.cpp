#include<iostream>

using namespace std;

int main(void)
{	
	char c = 'A';
	int q[300] = {1,};
	cout << c;
	q[c] = 3;
	cout << q[c] << endl;

}
