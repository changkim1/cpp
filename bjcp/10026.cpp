#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#define MAX 101

using namespace std;

typedef struct node
{
	int x, y;
} node;

deque<node> dq;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n;

char map1[MAX][MAX];
char map2[MAX][MAX];
int vis[MAX][MAX];
string inp;

int cnt1, cnt2;

int is_valid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < n && y < n);
}

void	bfs(int checker)
{
	node now;
	int nx, ny;
	dq.clear();
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j])
			{
				dq.push_back({j, i});
				vis[i][j] = 1;
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
							if (checker == 1)
							{
								if (map1[ny][nx] == map1[now.y][now.x] && !vis[ny][nx])
								{
									dq.push_back({nx, ny});
									vis[ny][nx] = 1;
								}
							}
							else
							{
								if (map2[ny][nx] == map2[now.y][now.x] && !vis[ny][nx])
								{
									dq.push_back({nx, ny});
									vis[ny][nx] = 1;
								}
							}
						}
					}
				}
				if (checker == 1)
					cnt1++;
				else
					cnt2++;
			}
		}
	}
	if (checker == 1)
		cout << cnt1 << ' ';
	else
		cout << cnt2 << '\n';
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		for (int j = 0; j < n; j++)
		{
			map1[i][j] = inp[j];
			if (inp[j] == 'R')
				map2[i][j] = 'G';
			else
				map2[i][j] = inp[j];
		}
	}
	bfs(1);
	bfs(2);
}