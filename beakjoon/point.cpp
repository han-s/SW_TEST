#include<iostream>
#include<math.h>

using namespace std;
int search_com_div(int width, int height);

int main(void)
{
	int common_div;
	int x1,x2;
	int y1,y2;

	cin >> x1 >> y1 >> x2>> y2;

	int width = abs(x1-x2);
	int height = abs(y1-y2);
	common_div = search_com_div(width,height);

	cout <<common_div+1 << endl;

	return 0;
}

int search_com_div(int width, int height)
{
	int result =0;
	if(width>height)
	{
		for(int i=1; i<height; i++)
		{
			if(width % i == 0 && height % i == 0)
				result = i;
		}
	}
	else
	{
		for(int i=1; i<width; i++)
		{
			if(width %i == 0 && height % i == 0)
				result = i;
		}
	}

	return result;
}
