#include <iostream>
#include <deque>

using namespace std;

int n, m, cnt;
char map[51][51];
int vis[51][51];

deque<pair<int, int>> dq;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int	is_valid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < m && y < n);
}

void	bfs(char teil)
{
	int nx, ny, a;
	pair<int, int> now;
	dq.clear();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == teil && !vis[i][j])
			{
				dq.push_back({j, i});
				vis[i][j] = 1;
				cnt++;
			}
			while (!dq.empty())
			{
				now = dq.front();
				dq.pop_front();
				if (teil == '-')
					a = 1;
				else
					a = 0;
				while (a < 4)
				{
					nx = now.first + dx[a];
					ny = now.second + dy[a];
					if (is_valid(nx, ny) && !vis[ny][nx] && map[ny][nx] == teil)
					{
						dq.push_back({nx, ny});
						vis[ny][nx] = 1;
					}
					a += 2;
				}
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	bfs('-');
	bfs('|');
	cout << cnt << endl;
}