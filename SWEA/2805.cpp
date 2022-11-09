#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int map[50][50];

void	solve(int n)
{
	int ans = 0;
	int st = n / 2;
	int pass_idx;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = 0;
			pass_idx = abs(st - i);
			while (tmp < pass_idx)
			{
				tmp++;
				j++;
			}
			ans += map[i][j];
			printf("(%d, %d) = %d += %d\n", i, j, map[i][j], ans);
		}	
	}
	cout << ans << '\n';
}

int main(void)
{
	int n, t;
	cin >> t;
	string inp;
	for (int a = 0; a < t; a++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> inp;
			for (int j = 0; j < n; j++)
			{
				map[i][j] = inp[j] - '0';
			}
		}
		solve(n);
	}
}