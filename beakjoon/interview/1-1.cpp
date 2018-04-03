#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

int main(void)
{
	vector<char> v;
	char *c = (char*)malloc(sizeof(char));
	cin >> c;
	int len = strlen(c);
	int result = -1;
	for(int i=0; i<len; i++)
	{
		if(v.empty())
		{
			v.push_back(c[i]);
		}
		else
		{
			for(int j=0; j<v.size(); j++)
				if(v[j]==c[i])
				{
					result = i;
					break;
				}
			v.push_back(c[i]);
		}
		if(result == i)
			break;
	}
	cout << c[result] << endl;
	return 0;
}
