#include <iostream>
#include <cstring>
#include <deque>
#define MAX 301
using namespace std;

typedef struct node
{
	int x;
	int y;
}	node;

int vis[MAX][MAX];
int dep[MAX][MAX];

deque<node> dq;

int n, t;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int	valid_(int x, int y, int n)
{
	return (x >= 0 & y >= 0 && x < n && y < n);
}

void	bfs(node start, node goal, int n)
{
	node now;
	int nx, ny;
	dq.clear();
	memset(vis, 0, sizeof(vis));
	memset(dep, 0, sizeof(dep));
	dq.push_back(start);
	vis[start.y][start.x] = 1;
	dep[start.y][start.x] = 0;
	while (!dq.empty())
	{
		now = dq.front();
		dq.pop_front();
		if (now.y == goal.y && now.x == goal.x)
		{
			cout << dep[now.y][now.x] << '\n';
			return ;
		}
		for (int i = 0; i < 8; i++)
		{
			nx = now.x + dx[i];
			ny = now.y + dy[i];
			if (valid_(nx, ny, n) && !vis[ny][nx])
			{
				dq.push_back({nx, ny});
				vis[ny][nx] = 1;
				dep[ny][nx] = dep[now.y][now.x] + 1;
			}
		}
	}
}

int main(void)
{
	node start;
	node goal;
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		cin >> n;
		cin >> start.x >> start.y;
		cin >> goal.x >> goal.y;
		bfs(start, goal, n);
	}

}