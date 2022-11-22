#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int map[50][50];

void	solve(int n, int a)
{
	int ans = 0;
	int st = n / 2;
	int pass_idx;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pass_idx = abs(st - i);
			if (j < pass_idx || j >= n - pass_idx)
				continue ;
			ans += map[i][j];
		}	
	}
	printf("#%d %d\n", a + 1, ans);
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
		solve(n, a);
	}
}