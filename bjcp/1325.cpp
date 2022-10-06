#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<short> dq, ans;

vector<short> v[10001];
char vis[10001];
int n, m;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.first == b.first)
		{
			return (a.second > b.second);
		}
		else
			return (a.first < b.first);
	}
};

void	bfs(void)
{
	short now, size, max_size = 0;
	for (short i = 1; i <= n; i++)
	{
		size = 0;
		if (vis[i] != '1')
		{
			dq.push_back(i);
			vis[i] = '1';
		}
		while (!dq.empty())
		{
			now = dq.front();
			dq.pop_front();
			size++;
			for (short j = 0; j < (int)v[now].size(); j++)
			{
				dq.push_back(v[now][j]);
			}
		}
		if (size > max_size)
		{
			ans.clear();
			ans.push_back(i);
			max_size = size;
		}
		else if (size == max_size)
			ans.push_back(i);
	}
}

int main(void)
{
	short a, b;
	cin >> n >> m;
	for (short i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[b].push_back(a);
	}
	bfs();
	cout << endl;
	while (!ans.empty())
	{
		cout << ans.front() << ' ';
		ans.pop_front();
	}
}