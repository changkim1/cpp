#include <iostream>
#include <deque>
#include <queue>
#define MAX 101

using namespace std;

typedef struct node
{
	int x;
	int y;
}	node;

deque<node> dq;

int map[MAX][MAX];
bool vis[MAX][MAX];

int n, m, k; // m = y, n = x
int cnt;
priority_queue<int, vector<int>, greater<int>> pq;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int valid_(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void	bfs(void)
{
	node now;
	int nx, ny, size;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0 && !vis[i][j])
			{
				dq.push_back({j, i});
				vis[i][j] = 1;
				cnt++;
			}
			size = 0;
			while (!dq.empty())
			{
				now = dq.front();
				dq.pop_front();
				size++;
				for (int a = 0; a < 4; a++)
				{
					nx = now.x + dx[a];
					ny = now.y + dy[a];
					if (valid_(nx, ny) && !map[ny][nx] && !vis[ny][nx])
					{
						dq.push_back({nx, ny});
						vis[ny][nx] = 1;
					}
				}
			}
			if (size != 0)
				pq.push(size);
		}
	}
}

int main(void)
{
	node st;
	node end;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> st.x >> st.y;
		cin >> end.x >> end.y;
		for (int x = st.x; x < end.x; x++)
		{
			for (int y = st.y; y < end.y; y++)
				map[y][x] = 1;
		}
	}
	bfs();
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
	{
		cout << pq.top() << ' ';
		pq.pop();
	}
}