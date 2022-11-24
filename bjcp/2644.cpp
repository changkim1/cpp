#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int map[101][101];
int vis[101];
int dep[101];

int n, m, x, y, start, goal;

stack<int> s;

void	dfs(void)
{
	int now = s.top();
	s.pop();
	for (int i = 1; i <= n; i++)
	{
		if ((map[now][i] || map[i][now]) && !vis[i])
		{
			s.push(i);
			vis[i] = 1;
			dep[i] = dep[now] + 1;
			// printf("n %d i %d d %d\n", now, i, dep[i]);
			// printf("top = %d\n\n", s.top());
			dfs();
		}
	}
}

int main(void)
{
	cin >> n;
	cin >> start >> goal;
	cin >> m;
	memset(dep, -1, sizeof(dep));
	for (int j = 0; j < m; j++)
	{
		cin >> x >> y;
		map[x][y] = 1;
	}
	s.push(start);
	vis[start] = 1;
	dfs();
	if (start == goal)
		cout << "0" << '\n';
	else if (dep[goal] == -1)
		cout << "-1" << '\n';
	else
		cout << dep[goal] + 1 << '\n';
}