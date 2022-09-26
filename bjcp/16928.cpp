#include <iostream>
#include <deque>

using namespace std;


int map[101][101];
int vis[101][101];
int dep[101];
int f[101];
int n, m;
deque<int> dq;


void bfs(void)
{
	int now;

	dq.push_back(1);
	while (!dq.empty())
	{
		now = dq.front();
		dq.pop_front();
		for (int i = 1; i <= 100; i++)
		{
			if (map[now][i] == 1 && !vis[now][i])
			{
				dq.push_back(i);
				vis[now][i] = 1;
				if (dep[i] == 0 || dep[i] >= dep[now] + 1)
				{
					if (f[now] == 1)
						dep[i] = dep[now];
					else
						dep[i] = dep[now] + 1;
				}
			}
		}
	}
	cout << dep[100] << endl;
}

int main(void)
{
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		f[a] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		f[a] = 1;
	}
	for (int i = 0; i < 100; i++)
	{
		if (f[i] == 1)
			continue ;
		for (int j = 1; j <= 6; j++)
		{
			if (i + j <= 100)
				map[i][i + j] = 1;
		}
	}
	bfs();
}