#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

queue<int> q;

int map[MAX][MAX];
int vis[MAX];

int n, m, cnt;

int main(void)
{
	int a, b, tmp;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	q.push(1);
	vis[1] = 1;
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (map[tmp][i] == 1 && !vis[i])
			{
				q.push(i);
				vis[i] = 1;
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}