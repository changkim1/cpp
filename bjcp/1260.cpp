#include <iostream>
#include <deque>
#include <stack>
#include <cstring>

#define MAX 1001

using namespace std;

deque<int> dq;
stack<int> s;
int n, m, v;
int map[MAX][MAX];
int vis[MAX];

void	dfs(void)
{
	int tmp;

	while (s.empty() == 0)
	{
		tmp = s.top();
		s.pop();
		printf("%d ", tmp);
		for (int i = 1; i <= n; i++)
		{
			if (map[tmp][i] && !vis[i])
			{
				s.push(i);
				vis[i] = 1;
				dfs();
			}
		}
	}
}

void	bfs(void)
{
	int tmp;
	dq.clear();
	dq.push_back(v);

	vis[v] = 1;
	while (!dq.empty())
	{
		tmp = dq.front();
		dq.pop_front();
		printf("%d ", tmp);
		for (int i = 1; i <= n; i++)
		{
			if (map[tmp][i] && !vis[i])
			{
				dq.push_back(i);
				vis[i] = 1;
			}
		}
	}
	printf("\n");
}

int main(void)
{
	int x, y;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	s.push(v);
	vis[v] = 1;
	dfs();
	printf("\n");
	memset(vis, 0, sizeof(vis));
	bfs();
}