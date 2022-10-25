#include <iostream>
#include <string>

using namespace std;

int num[10001];

int main(void)
{
	string tmp;
	int idx;
	for (int i = 1; i <= 10000; i++)
	{
		idx = 0;
		tmp = to_string(i);
		for (int j = 0; j < (int)tmp.size(); j++)
		{
			idx += (tmp[j] - '0');
		}
		idx += i;
		num[idx]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if(num[i] == 0)
		{
			cout << i << '\n';
		}
	}
}