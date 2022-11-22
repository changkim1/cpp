#include <iostream>
#include <algorithm>
using namespace std;

int map[1001];
int dp[1001];

bool compare(int x, int y)
{
	return (x > y);
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
		dp[i] = map[i];	
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (map[j] < map[i])
			{
				if (dp[i] < dp[j] + map[i])
				{
					dp[i] = dp[j] + map[i];
				}
			}
		}
	}
	sort(dp, dp +n, compare);
	printf("%d\n", dp[0]);
}