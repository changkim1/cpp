#include <iostream>
#include <deque>
#define MAX 1001

using namespace std;

typedef struct node
{
	int x, y;
}	node;

deque<node> dq;

int n, m, day;
node now;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int map[MAX][MAX];
int vis[MAX][MAX];
int dep[MAX][MAX];

int is_valid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < m && y < n);
}

void bfs(void)
{
	int nx, ny;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1 && !vis[i][j])
			{
				dq.push_back({j, i});
				vis[i][j] = 1;
			}
		}
	}
	while (!dq.empty())
	{
		now = dq.front();
		dq.pop_front();
		for (int i = 0; i < 4; i++)
		{
			nx = now.x + dx[i];
			ny = now.y + dy[i];
			if (is_valid(nx, ny))
			{
				if (map[ny][nx] == 0 && !vis[ny][nx])
				{
					dq.push_back({nx, ny});
					vis[ny][nx] = 1;
					dep[ny][nx] = dep[now.y][now.x] + 1;
					map[ny][nx] = 1;
					if (dep[ny][nx] > day)
						day = dep[ny][nx];
				}
			}
		}
	}
}

int main(void)
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	bfs();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				cout << "-1" << '\n';
				return (0);
			}
		}
	}
	cout << day << '\n';
}