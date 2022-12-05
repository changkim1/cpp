#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

typedef struct node
{
	int x, y;
}	node;

int map[51][51];
int vis[51][51];
int dep[51][51];

int n, m;
int ans;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<node> q;

bool	valid_(int x, int y)
{
	return (x >= 0 && x < m && y >= 0 && y < n);
}

void	bfs(void)
{
	node now;
	int nx, ny;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'L' && !vis[i][j])
			{
				q.push({j, i});
				vis[i][j] = 1;
				while (!q.empty())
				{
					now = q.front();
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						nx = dx[i] + now.x;
						ny = dy[i] + now.y;
						if (valid_(nx, ny) && map[ny][nx] == 'L' && !vis[ny][nx])
						{
							q.push({nx, ny});
							vis[ny][nx] = 1;
							dep[ny][nx] = dep[now.y][now.x] + 1;
							if (dep[ny][nx] > ans)
								ans = dep[ny][nx];
						}
					}
				}
				memset(vis, 0, sizeof(vis));
				memset(dep, 0, sizeof(dep));
			}
		}
	}
}

int main(void)
{
	string inp;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		for (int j = 0; j < m; j++)
			map[i][j] = inp[j];
	}
	bfs();
	cout << ans << '\n';
}