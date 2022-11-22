#include <iostream>
#include <algorithm>
using namespace std;

int day[1001];
int price[1001];
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
		cin >> day[i];
		cin >> price[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i + day[i] > n)
			continue ;
		else
		{
			if (price[i] > dp[i])
				dp[i] = price[i];
		}
		for (int j = i + 1; j < n; j++)
		{
			if (j < i + day[i] || j + day[j] > n)
				continue ;
			if (dp[j] < dp[i] + price[j])
				dp[j] = dp[i] + price[j];
		}
	}
	sort(dp, dp + n, compare);
	printf("%d\n", dp[0]);
}