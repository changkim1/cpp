#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int n, m;

int map[1001][1001];
int vis[1001];
int cnt;

void	bfs(void)
{
	int now;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dq.push_back(i);
			vis[i] = 1;
			cnt++;
		}
		while (!dq.empty())
		{
			now = dq.front();
			dq.pop_front();
			for (int j = 1; j <= n; j++)
			{
				if (!vis[j] && map[now][j])
				{
					dq.push_back(j);
					vis[j] = 1;
				}
			}
		}
		
	}
	cout << cnt << endl;
}

int main(void)
{
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	bfs();
}