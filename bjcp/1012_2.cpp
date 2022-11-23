#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int t, n, m, k;

int map[51][51];
int vis[51][51];
int cnt;

typedef struct node
{
	int x, y;
}	node;

stack<node> s;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool is_valid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < m && y < n);
}

int main(void)
{
	int a, b;
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;
			map[a][b] = 1;
		}
	}
}