#include<iostream>
#include<string.h>
using namespace std;

void changeChar(char c[], int len);
int main(void)
{
	char c[10];
	cin.getline(c,10,'\n');
	changeChar(c,10);
}
void changeChar(char c[], int len)
{
	int charlen = strlen(c);
	int temp = len-1;

	for(int i=charlen-1; i>=0; i--)
	{
		if(c[i] == ' ')
		{
			c[temp--] = '0';
			c[temp--] = '2';
			c[temp--] = '%';
			continue;
		}

		c[temp--] = c[i];
	}
	for(int i=0; i<len;i++)
		cout << c<< endl;
}


