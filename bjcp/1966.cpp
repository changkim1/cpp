#include <iostream>
#include <queue>
#include <map>
using namespace std;

int k, n, m;
queue<pair<int, int>> q; // first == idx, second == priority

int	bigger_check(int idx, int pri) // X == 1, O == 0
{
	queue<pair<int, int>> tmp;
	tmp = q;
	while (!tmp.empty())
	{
		if (idx == tmp.front().first)
		{
			tmp.pop();
			continue ;
		}
		if (pri < tmp.front().second)
			return (0);
		tmp.pop();
	}
	return (1);
}

int main(void)
{
	int pri, cnt;
	pair<int, int> tmp;

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cnt = 1;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> pri;
			q.push({i, pri});	
		}
		while (!q.empty())
		{
			if (bigger_check(q.front().first, q.front().second) == 1)
			{
				if (q.front().first == m)
				{
					cout << cnt << '\n';
					while (!q.empty())
						q.pop();
					break ;
				}
				q.pop();
				cnt++;
			}
			else
			{
				tmp = q.front();
				q.pop();
				q.push(tmp);
			}
		}
	}
}