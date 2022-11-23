#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct node
{
	int x, y;
}	node;

int n;
int map[26][26];
int vis[26][26];
int dep[400];

stack<node> s;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool	is_valid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < n &&y < n);
}

void	solve(int depth)
{
	node now;
	int nx, ny;
	now = s.top();
	s.pop();
	dep[depth]++;
	for (int i = 0; i < 4; i++)
	{
		nx = now.x + dx[i];
		ny = now.y + dy[i];
		if (is_valid(nx, ny) && !vis[ny][nx] && map[ny][nx])
		{
			s.push({nx, ny});
			vis[ny][nx] = 1;
			solve(depth);
		}
	}
}

void	dfs(void)
{
	int depth = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] && !vis[i][j])
			{
				s.push({j, i});
				vis[i][j] = 1;
				solve(depth);
				depth++;
			}
		}
	}
	cout << depth << '\n';
	sort(dep, dep + depth);
	for (int i = 0; i < depth; i++)
	{
		cout << dep[i] << '\n';
	}
}

int main(void)
{
	string inp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = inp[j] - '0';
		}
	}
	dfs();
}