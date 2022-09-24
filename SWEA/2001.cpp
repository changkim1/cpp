#include <iostream>
#include <cstring>
using namespace std;

int fly[16][16];
int n, m, t;

void	solve()
{
	int tmp = 0;
	int ans = 0;
	for (int i = 0; i < n - m + 1; i++)
	{
		for (int j = 0; j < n - m + 1; j++)
		{
			tmp = 0;
			for (int a = 0; a < m; a++)
			{
				for (int b = 0; b < m; b++)
					tmp += fly[i+a][j+b];
			}
			if (tmp > ans)
				ans = tmp;
		}
	}
	cout << ans << '\n';
}

int main(void)
{
	cin >> t;
	for (int a= 0; a < t; a++)
	{
		cin >> n >> m;
		memset(fly, 0, sizeof(fly));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> fly[i][j];
		}
		cout << "#" << a + 1 << ' ';
		solve();
	}
}