#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int map[1005][1005];

int main(void)
{
	int x, y;
	int c, r;
	int k, d = 0;
	cin >> c >> r >> k;
	if (k > c * r)
	{
		cout << '0' << '\n';
		return 0;
	}
	if (k == 1)
	{
		cout << '1' << ' ' << '1' << '\n';
		return 0;
	}
	x = 1, y = 1;
	k--;
	for (int i = 0; i <= c; i++)
	{
		map[0][i] = 1;
		map[r + 1][i] = 1;
	}
	for (int i = 0; i <= r; i++)
	{
		map[i][0] = 1;
		map[i][c + 1] = 1;
	}
	for (int i = 0; i <= c * r; i++)
	{
		map[y][x] = 1;
		x += dx[d];
		y += dy[d];
		k--;
		if (map[y + dy[d]][x + dx[d]])
			d = (d + 1) % 4;
		if (k == 0)
			break ;
	}
	cout << x << ' ' << y << '\n';
}