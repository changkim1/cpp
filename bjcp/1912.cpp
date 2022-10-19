#include <iostream>
#include <queue>

using namespace std;

int n, num[100001];
int max_, dp[100001];

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	dp[0] = num[0];
	max_ = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = dp[i-1] + num[i] > num[i] ? dp[i-1] + num[i] : num[i];
		if (dp[i] > max_)
			max_ = dp[i];
	}
	cout << max_ << '\n';
}