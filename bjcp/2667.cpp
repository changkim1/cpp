#include <iostream>
#include <deque>
#include <queue>
#include <string>

using namespace std;

deque<pair<int, int>> dq;
int inp[26][26];
int vis[26][26];
priority_queue<int, vector<int>, greater<int>> pq;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n;

int is_valid(int nx, int ny)
{
	return (nx >= 0 && ny >= 0 && nx < n && ny < n);
}

int	bfs(void)
{
	pair<int, int> now;
	int nx, ny, cnt, num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (inp[i][j] && !vis[i][j])
			{
				dq.push_back({j, i});
				vis[i][j] = 1;
				num++;
				cnt = 1;
				while (!dq.empty())
				{
					now = dq.front();
					dq.pop_front();
					for (int a = 0; a < 4; a++)
					{
						nx = now.first + dx[a];
						ny = now.second + dy[a];
						if (is_valid(nx, ny))
						{
							if (!vis[ny][nx] && inp[ny][nx])
							{
								dq.push_back({nx, ny});
								vis[ny][nx] = 1;
								cnt++;
							}
						}
					}
				}
				pq.push(cnt);
			}
		}
	}
	return (num);
}

int main(void)
{
	string tmp;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = 0; j < n; j++)
		{
			inp[i][j] = tmp[j] - '0';
		}
	}
	num = bfs();
	printf("%d\n", num);
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}