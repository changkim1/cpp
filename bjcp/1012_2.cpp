#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int t, n, m, k;

int map[51][51];
int vis[51][51];
int cnt;

typedef struct node
{
	int x, y;
}	node;

stack<node> s;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool is_valid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < m && y < n);
}

void	dfs(void)
{
	node now;
	now = s.top();
	s.pop();
	int nx, ny;
	for (int i = 0; i < 4; i++)
	{
		nx = now.x + dx[i];
		ny = now.y + dy[i];
		if (is_valid(nx, ny) && map[ny][nx] & !vis[ny][nx])
		{
			s.push({nx, ny});
			vis[ny][nx] = 1;
			dfs();
		}
	}
}

int main(void)
{
	int a, b;
	cin >> t;
	for (int z = 0; z < t; z++)
	{
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;
			map[b][a] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] && !vis[i][j])
				{
					s.push({j, i});
					vis[i][j] = 1;
					dfs();
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}