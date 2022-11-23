#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int map[101][101];
int vis[101];
int n, m, cnt = -1;


void	dfs(void)
{
	int now;
	if (vis[1] == 0)
	{
		s.push(1);
		vis[1] = 1;
	}
	now = s.top();
	s.pop();
	cnt++;
	for (int i = 1; i <= n; i++)
	{
		if (map[now][i] == 1 && vis[i] == 0)
		{
			s.push(i);
			vis[i] = 1;
			dfs();
		}
	}
}

int main(void)
{
	int a, b;
	cin >> n >> m;
	for (int j = 0; j < m; j++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs();
	cout << cnt << endl;
}