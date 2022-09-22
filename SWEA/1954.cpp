#include <iostream>
#include <cstring>

using namespace std;

int n;
int x, y;
int ans[11][11];

int main(void)
{
	int t;
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		memset(ans, 0, sizeof(ans));
		x = 0;
		y = 0;
		pair<int, int> cnt;
		int x_move = 1, y_move = 1;
		int circle;
		cin >> n;
		circle = n;
		int i = 1;
		while (i <= n * n)
		{
			cnt.first = circle - 1;
			cnt.second = circle - 1;
			if (cnt.first == 0 && i == n * n)
			{
				ans[y][x] = i;
				break ;
			}
			while (cnt.first > 0 && i <= n*n)
			{
				ans[y][x] = i;
				x += x_move;
				cnt.first--;
				i++;
			}
			x_move *= -1;
			while (cnt.second > 0 && i <= n*n)
			{
				ans[y][x] = i;
				y += y_move;
				cnt.second--;
				i++;
			}
			y_move *= -1;
			cnt.first = circle - 1;
			cnt.second = circle - 1;
			while (cnt.first > 0 && i <= n*n)
			{
				ans[y][x] = i;
				x += x_move;
				cnt.first--;
				i++;
			}
			x_move *= -1;
			while (cnt.second > 0 && i <= n*n)
			{
				ans[y][x] = i;
				cnt.second--;
				if (cnt.second != 0)
					y += y_move;
				i++;
			}
			y_move *= -1;
			x += x_move;
			circle -= 2;
		}
		printf("#%d\n", a + 1);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << ans[i][j] << ' ';
			}
			if (i != n - 1)
				cout << '\n';
		}
		printf("\n");
	}
}