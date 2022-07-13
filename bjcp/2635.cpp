#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100

using namespace std;

int n, len;
int res[MAX];

int	solve(int second)
{
	int i = 2;
	int tmp;

	res[0] = n;
	res[1] = second;
	tmp = n - second;
	while (tmp >= 0)
	{
		res[i] = tmp;
		tmp = res[i - 1] - res[i];
		i++;
	}
	len = i;
	return (i);
}

int main(void)
{
	int ans = 0;
	int tmp;
	int second;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		memset(res, 0, sizeof(res));
		tmp = solve(i);
		if (ans < tmp)
		{
			ans = tmp;
			second = i;
		}
	}
	ans = solve(second);
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++)
		printf("%d ", res[i]);
	printf("\n");
}