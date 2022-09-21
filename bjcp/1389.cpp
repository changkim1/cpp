#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

int n, m;
int map[MAX][MAX];
int vis[MAX];
int dep[MAX];
int ans[MAX];

queue<int> q;

int main(void)
{
	int a, b;
	int depth, tmp;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		memset(dep, 0, sizeof(dep));
		depth = 1;
		vis[i] = 1;
		for (int j = 0; j <= n; j++)
		{
			if (map[i][j] == 1 && !vis[j])
			{
				q.push(j);
				vis[j] = 1;
				dep[j] = depth;
			}
		}
		while (!q.empty())
		{
			tmp = q.front();
			q.pop();
			for (int j = 1; j <= n; j++)
			{
				if (map[tmp][j] == 1 && !vis[j])
				{
					q.push(j);
					vis[j] = 1;
					dep[j] = dep[tmp] + 1;
				}
			}
		}
		for (int j = 1; j <= n; j++)
			ans[i] += dep[j];
	}
	int min_idx = 1;
	int min_val = ans[1];
	for (int i = 1; i <= n; i++)
	{
		if (min_val > ans[i])
		{
			min_val = ans[i];
			min_idx = i;
		}
	}
	cout << min_idx << '\n';
}