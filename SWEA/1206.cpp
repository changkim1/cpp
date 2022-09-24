#include <iostream>
#include <cstring>
using namespace std;

int map[1050];
int n;

int dx[4] = {-2, -1, 1, 2};

int	solve(int idx)
{
	int ret = 0;
	int tmp_max = 0;
	int tmp;

	for (int i = 0; i < 4; i++)
	{
		tmp = map[idx+dx[i]];
		if (tmp > tmp_max)
			tmp_max = tmp;
	}
	if (map[idx] - tmp_max > 0)
		ret = map[idx] - tmp_max;
	return (ret);
}

int main(void)
{
	int cnt, ans;
	for (int i = 0; i < 10; i++)
	{
		cnt = 0;
		ans = 0;
		memset(map, 0, sizeof(map));
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> map[i];
		for (int i = 2; i < n - 2; i++)
		{
			cnt = solve(i);
			ans += cnt;
		}
		printf("#%d %d\n", i+1, ans);
	}
}