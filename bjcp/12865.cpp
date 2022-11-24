#include <iostream>

using namespace std;

typedef struct goods
{
	int w, v;
}	goods;

int dp[101][100001];
int n, k;

goods g[101];

int main(void)
{
	int a, b;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> g[i].w >> g[i].v;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - g[i].w >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j - g[i].w] + g[i].v);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[n][k] << '\n';
}