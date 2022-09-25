#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> dq;

bool comp(int a, int b)
{
	return (a > b);
}

int main(void)
{
	int tmp, cnt;
	for (int t = 0; t < 10; t++)
	{
		dq.clear();
		cin >> cnt;
		for (int i = 0; i < 100; i++)
		{
			cin >> tmp;
			dq.push_back(tmp);
		}
		sort(dq.begin(), dq.end(), comp);
		for (int i = 0; i < cnt; i++)
		{
			if (dq.front() - dq.back() <= 1)
				break;
			dq.front()--;
			dq.back()++;
			sort(dq.begin(), dq.end(), comp);
		}
		printf("#%d %d\n", t + 1, dq.front() - dq.back());
	}
}