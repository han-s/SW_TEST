#include<iostream>
#include<list>

using namespace std;

int main(void)
{
	list<int> l1,l2;
	list<int> result;
	int temp=0, cnt=0;
	l1.push_back(3);
	l1.push_back(6);
	l1.push_back(9);
	l1.push_back(1);

	l2.push_back(6);
	l2.push_back(3);
	l2.push_back(4);
	
	list<int>::iterator iter1=l1.begin();
	list<int>::iterator iter2=l2.begin();

	while(l1.end()!=iter1 || l2.end() !=iter2)
	{
		if(l1.end() == iter1)
		{	
			list<int>::iterator end=result.end();
			result.insert(result.end(),*end+(*iter2));
			iter2++;
			cnt++;
		}
		else if(l2.end() == iter2)
		{
			list<int>::iterator end=result.end();
			result.insert(result.end(),*end+(*iter1));
			iter1++;
			cnt++;
		}
		else
		{
			temp=*iter1+*iter2;
			if(temp>=10)
			{	
				result.push_back(temp-10);
				result.push_back(1);
				cnt++;
				cnt++;
			}
			else
			{
				result.push_back(temp);
				cnt++;
			}
			iter1++;
			iter2++;
		}
	}
}

