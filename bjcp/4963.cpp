#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

deque<pair<int, int>> dq;

int map[51][51];
int vis[51][51];

int w, h, cnt;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int	is_valid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < w && y < h);
}

void	bfs(void)
{
	int nx, ny;
	pair<int, int> now;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (vis[i][j] == 0 && map[i][j])
			{
				dq.push_back({j, i});
				vis[i][j] = 1;
				cnt++;
			}
			while (!dq.empty())
			{
				now = dq.front();
				dq.pop_front();
				for (int a = 0; a < 8; a++)
				{
					nx = now.first + dx[a];
					ny = now.second + dy[a];
					if (is_valid(nx, ny))
					{
						if (vis[ny][nx] == 0 && map[ny][nx])
						{
							dq.push_back({nx, ny});
							vis[ny][nx] = 1;
						}
					}
				}
			}
		}
	}
}

int main(void)
{
	while (1)
	{
		dq.clear();
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		bfs();
		cout << cnt << '\n';
	}
}