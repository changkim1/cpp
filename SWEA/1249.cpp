#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#define MAX 101
#define Min(a, b) a < b ? a : b
using namespace std;

typedef struct node
{
	int x, y;
}	node;

queue<node> q;

int map[MAX][MAX];
int vis[MAX][MAX];
int dp[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, t;

bool	valid_(int x, int y)
{
	return (x >= 0 && y >= 0 && x < n && y < n);
}

void	bfs(int a)
{
	int nx, ny;
	node now;
	memset(vis, 0, sizeof(vis));
	memset(dp, 0, sizeof(dp));
	q.push({0, 0});
	vis[0][0] = 1;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = dx[i] + now.x;
			ny = dy[i] + now.y;
			if (valid_(nx, ny))
			{
				if (!vis[ny][nx] || (dp[ny][nx] > dp[now.y][now.x] + map[ny][nx]))
				{
					q.push({nx, ny});
					vis[ny][nx] = 1;
					dp[ny][nx] = dp[now.y][now.x] + map[ny][nx];
				}
			}
		}
	}
	printf("#%d %d\n", a + 1, dp[n - 1][n - 1]);
}

int main(void)
{
	string inp;
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		cin >> n;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++)
		{
			cin >> inp;
			for (int j = 0; j < n; j++)
				map[i][j] = inp[j] - '0';
		}
		bfs(a);
	}
}