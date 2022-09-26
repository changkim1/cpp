#include <iostream>
#include <deque>
#include <cstring>
#define MAX 101

using namespace std;

typedef struct coor
{
	int h, y, x;
}	coor;

deque<coor> dq;

int map[MAX][MAX][MAX];
int vis[MAX][MAX][MAX];
int dep[MAX][MAX][MAX];
int n, m, h, day;

int dx[6] = {0 , 1, 0, -1, 0, 0};
int dy[6] = {1, 0, -1, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

int	valid_check(int x, int y, int f)
{
	if (x >= 0 && y >= 0 && f >= 0 && x < m && y < n && f < h)
		return (1);
	else
		return (0);
}

void	bfs(void)
{
	int nx, ny, nh;
	coor now;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (map[i][j][k] == 1 && !vis[i][j][k])
				{
					dq.push_back({i, j, k});
					vis[i][j][k] = 1;
				}
			}
		}
	}
	while (!dq.empty())
	{
		now = dq.front();
		dq.pop_front();
		for (int a = 0; a < 6; a++)
		{
			nx = now.x + dx[a];
			ny = now.y + dy[a];
			nh = now.h + dh[a];
			if (valid_check(nx, ny, nh) == 1)
			{
				if (map[nh][ny][nx] == 0 && !vis[nh][ny][nx])
				{
					dq.push_back({nh, ny, nx});
					vis[nh][ny][nx] = 1;
					map[nh][ny][nx] = 1;
					dep[nh][ny][nx] = dep[now.h][now.y][now.x] + 1;
					if (day < dep[nh][ny][nx])
						day = dep[nh][ny][nx];
				}
			}
		}
	}
}

int main(void)
{
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
				cin >> map[i][j][k];
		}
	}
	bfs();
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (map[i][j][k] == 0)
				{
					cout << "-1" << '\n';
					return (0);
				}
			}
		}
	}
	cout << day << '\n';
}