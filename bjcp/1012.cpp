#include <iostream>
#include <queue>
#include <cstring>
#define MAX 51
#define endl '\n'

using namespace std;

int map[MAX][MAX];
queue<pair<int, int>> q;
int vis[MAX][MAX];

int t, n, m, k, cnt;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void	BFS(void)
{
	pair<int, int> tmp;
	int nx, ny;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && vis[i][j] != 1)
			{
				q.push({i, j});
				vis[i][j] = 1;
				cnt++;
			}
			while (!q.empty())
			{
				tmp = q.front();
				q.pop();
				for (int a = 0; a < 4; a++)
				{
					nx = dx[a] + tmp.second;
					ny = dy[a] + tmp.first;
					if (nx >= 0 && nx < m && ny >= 0 && ny < n)
					{
						if (map[ny][nx] == 1 && vis[ny][nx] != 1)
						{
							q.push({ny, nx});
							vis[ny][nx] = 1;
						}
					}
				}
			}
		}
	}
}

void	solve()
{
	int x, y;
	cnt = 0;
	memset(map, 0, sizeof(map));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		map[y][x] = 1;
	}
	BFS();
	printf("%d\n", cnt);
}

int main(void)
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		solve();
	}
}