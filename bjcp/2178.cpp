#include <iostream>
#include <cstring>
#include <queue>

#define MAX 101

using namespace std;

queue<pair<int, int>> que;
int visit[MAX][MAX];
char map[MAX][MAX];
int count[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m;

void BFS()
{
	int nx, ny;
	pair<int, int> tmp;

	while (!que.empty())
	{
		tmp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = dx[i] + tmp.first;
			ny = dy[i] + tmp.second;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (map[nx][ny] == '1' && visit[nx][ny] == 0)
				{
					que.push({nx, ny});
					count[nx][ny] = count[tmp.first][tmp.second] + 1;
					visit[nx][ny] = 1;
				}
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	que.push({0, 0});
	count[0][0]++;
	BFS();
	cout << count[n - 1][m - 1];
}