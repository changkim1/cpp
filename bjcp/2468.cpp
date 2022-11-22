#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int max_cnt, max_hi;

typedef struct node
{
	int x, y;
}	node;

queue<node> q;

int map[101][101];
int vis[101][101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool	valid_(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < n);
}

void	bfs(int hi)
{
	node now;
	int nx, ny, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] > hi && !vis[i][j])
			{
				q.push({j, i});
				vis[i][j] = 1;
				cnt++;
			}
			while (!q.empty())
			{
				now = q.front();
				q.pop();
				for (int a = 0; a < 4; a++)
				{
					nx = now.x + dx[a];
					ny = now.y + dy[a];
					if (valid_(nx, ny))
					{
						if (map[ny][nx] > hi && !vis[ny][nx])
						{
							q.push({nx, ny});
							vis[ny][nx] = 1;
						}
					}
				}
			}
		}	
	}
	if (cnt > max_cnt)
		max_cnt = cnt;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] > max_hi)
				max_hi = map[i][j];
		}	
	}
	for (int i = 0; i < max_hi; i++)
	{
		memset(vis, 0, sizeof(vis));
		bfs(i);
	}
	cout << max_cnt << '\n';
}