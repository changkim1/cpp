#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

stack<int> s;
queue<int> q;

int vis[1001];
int map[1001][1001];

int n, m, v, a, b;

void	bfs(void)
{
	int now;
	q.push(v);
	vis[v] = 1;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		cout << now << ' ';
		for (int i = 1; i <= n; i++)
		{
			if (map[now][i] == 1 && vis[i] == 0)
			{
				q.push(i);
				vis[i] = 1;
			}
		}
	}
}

void	solve(void)
{
	int now = s.top();
	s.pop();
	cout << now << ' ';
	for (int i = 1; i <= n; i++)
	{
		if (map[now][i] == 1 && vis[i] == 0)
		{
			s.push(i);
			vis[i] = 1;
			solve();
		}
	}
}

void	dfs(void)
{
	s.push(v);
	vis[v] = 1;
	solve();
}

int main(void)
{
	cin >> n >> m >> v;
	for (int j = 0; j < m; j++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs();
	cout << '\n';
	memset(vis, 0, sizeof(vis));
	bfs();
}