#include <iostream>
#include <deque>

using namespace std;

int map[10001];
int vis[10001];
int dep[10001];

deque<int> dq;
int n, a, b, chk;

void	bfs(void)
{
	int nx;
	int now;
	dq.push_back(a);
	vis[a] = 1;
	while (!dq.empty())
	{
		now = dq.front();
		dq.pop_front();
		if (now == b)
		{
			cout << dep[now] << endl;
			return ;
		}
		else
		{
			for (int i = 1; now + i * map[now] <= n; i++)
			{
				nx = now + (i * map[now]);
				if (vis[nx] == 0)
				{
					printf("now = %d\n", nx);
					dq.push_back(nx);
					vis[nx] = 1;
					if (dep[nx] == 0 || dep[nx] > dep[now] + 1)
						dep[nx] = dep[now] + 1;
				}
			}
		}
	}
	cout << "-1" << endl;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i+1];
	cin >> a >> b;
	bfs();
}