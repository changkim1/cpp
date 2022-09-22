#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <deque>
using namespace std;

deque<int> dq;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		while (i < 5)
			i++;
		printf("%d ", i);	
	}
}