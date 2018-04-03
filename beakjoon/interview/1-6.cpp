#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
char* str_compress(char s[]);

int main(void)
{
	char c[100]={'\0',};
	cin >> c;
	char *newstr = str_compress(c);
	for(int i=0; i<strlen(c); i++)
		cout << newstr[i];
	cout << endl;
	return 0;
}

char* str_compress(char s[])
{
	int len = strlen(s);
	char *newStr = (char*)malloc(sizeof(char));
	char num[10];
	int count=1;
	int temp=0;
	for(int i=0; i<len-1; i++)
	{
		if(s[i] == s[i+1])
		{
			count++;
			if(i!=(len-2))
				continue;
		}
		newStr[temp++] = s[i];
		sprintf(num,"%d",count);
		for(int j=0; j<strlen(num); j++)
			newStr[temp++] = num[j];
		memset(num,0,sizeof(char)*10);
		count=1;
	}
	return len<=strlen(newStr) ? s : newStr;
}


