#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(void)
{
	char *arr1 = (char*)malloc(sizeof(char));
	char *arr2 = (char*)malloc(sizeof(char));
	int i,j=0, cnt=1;
	
	cin >> arr1;

	for(i=0; arr1[i]; i++)
	{
		if(arr1[i]==arr1[i+1])
			cnt++;
		else
		{
			arr2[j++] = arr1[i];
			sprintf(&arr2[j++], "%d", cnt);
			cnt=1;
		}
	}

	if(strlen(arr1)<=strlen(arr2))
		cout << arr1<<endl;
	else
		cout << arr2<<endl;
}
	
