#include<iostream>
#include<string>
using namespace std;

int main(void)
{
	char *s1 = (char*)malloc(sizeof(char));
	char *s2 = (char*)malloc(sizeof(char));
	
	cin >> s1;

	char s1s1[strlen(s1)*2+1];
	strcpy(s1s1,s1);
	s1s1[strlen(s1)+1]='\0';
	strcat(s1s1,s1);
	cout << s1s1;
	return 0;
}

