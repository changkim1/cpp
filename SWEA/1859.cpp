#include <iostream>
#include <deque>
using namespace std;

int	n, t;
deque<int> dq;

int	find_max_idx(deque<int> dq)
{
	int	max, idx;
	max = dq.front();
	idx = 0;
	for (int i = 0; i < (int)dq.size(); i++)
	{
		if (dq[i] > max)
		{
			max = dq[i];
			idx = i;
		}
	}
	return (idx);
}

int main(void)
{
	int tmp;
	int	max_idx;
	long long	profit;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		profit = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			dq.push_back(tmp);
		}
		while (!dq.empty())
		{
			max_idx = find_max_idx(dq);
			for (int i = 0; i < max_idx; i++)
				profit += (dq[max_idx] - dq[i]);
			for (int i = 0; i <= max_idx; i++)
				dq.pop_front();
		}
		cout << '#' << i + 1 << ' ' << profit << '\n';
	}
}