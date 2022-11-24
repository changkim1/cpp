#include <iostream>

using namespace std;

typedef struct goods
{
	int w, v;
}	goods;

int dp[100001];
int n, k;

goods g[101];

int	yang(int a)
{
	if (a < 0)
		return (0);
	return (a);
}

int main(void)
{
	int a, b;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> g[i].w >> g[i].v;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			while (j - g[i].w < 0)
				j++;
			if (dp[j] < g[i].v + dp[yang(j - g[i].w)])
				dp[j] = g[i].v + dp[yang(j - g[i].w)];
		}
		printf("%d\n", i);
		for (int j = 1; j <= k; j++)
			printf("%d ", dp[j]);
		printf("\n");
	}
}