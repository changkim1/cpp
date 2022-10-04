#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> dq;
int map[101][101];
int vis[101][101];

int n, m, k, max_size;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int is_valid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < m && y < n);
}

void bfs(void)
{
	int nx, ny, size;
	pair<int, int> now;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			size = 0;
			if (map[i][j] == 1 && vis[i][j] == 0)
			{
				dq.push_back({j, i});
				vis[i][j] = 1;
			}
			while (!dq.empty())
			{
				now = dq.front();
				dq.pop_front();
				for (int a = 0; a < 4; a++)
				{
					nx = now.first + dx[a];
					ny = now.second + dy[a];
					if (is_valid(nx, ny))
					{
						if (map[ny][nx] && !vis[ny][nx])
						{
							dq.push_back({nx, ny});
							vis[ny][nx] = 1;
						}
					}
				}
				size++;
			}
			if (max_size < size)
				max_size = size;
		}
	}
}

int main(void)
{
	int a, b;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
	}
	bfs();
	cout << max_size << endl;
}