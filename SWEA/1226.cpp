#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

typedef struct node
{
	int x;
	int y;
}	node;

queue<node> q;
int map[17][17];
int vis[17][17];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int valid_(int x, int y)
{
	return (x >= 0 && y >= 0 && x < 16 && y < 16);
}

void	bfs(node start, node goal, int t)
{
	node now;
	int nx, ny, check = 0;
	q.push(start);
	vis[start.y][start.x] = 1;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if (now.x == goal.x && now.y == goal.y)
			check = 1;
		for (int i = 0; i < 4; i++)
		{
			nx = now.x + dx[i];
			ny = now.y + dy[i];
			if (valid_(nx, ny) && (map[ny][nx] == 0 || map[ny][nx] == 3) && !vis[ny][nx])
			{
				q.push({nx, ny});
				vis[ny][nx] = 1;
			}
		}
	}
	printf("#%d ", t + 1);
	printf("%d\n", check);
}

int main(void)
{
	int n = 16;
	node start, goal;
	string inp;
	for (int t = 0; t < 10; t++)
	{
		memset(vis, 0, sizeof(vis));
		memset(map, 0, sizeof(map));
		cin >> inp;
		for (int i = 0; i < n; i++)
		{
			cin >> inp;
			for (int j = 0; j < n; j++)
			{
				map[i][j] = inp[j] - '0';
				if (map[i][j] == 2)
				{
					start.x = j;
					start.y = i;
				}
				else if (map[i][j] == 3)
				{
					goal.x = j;
					goal.y = i;
				}
			}
		}
		bfs(start, goal, t);
	}
}