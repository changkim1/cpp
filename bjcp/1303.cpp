#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<pair<int, int>> dq;
char map[101][101];
int vis[101][101];

int n, m;
int w_power, b_power;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int	is_valid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < n && y < m);
}

void	bfs(char color)
{
	int nx, ny, size;
	pair<int, int> now;
	dq.clear();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			size = 0;
			if (map[i][j] == color && !vis[i][j])
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
					if (is_valid(nx, ny) && map[ny][nx] == color && !vis[ny][nx])
					{
						dq.push_back({nx, ny});
						vis[ny][nx] = 1;
					}
				}
				size++;
			}
			if (color == 'W')
				w_power += size * size;
			else
				b_power += size * size;
		}
	}
}

int main(void)
{
	string inp[101];
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> inp[i];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[i][j] = inp[i][j];
		}
	}
	bfs('W');
	bfs('B');
	cout << w_power << ' ' << b_power << '\n';
}