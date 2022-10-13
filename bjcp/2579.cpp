#include <iostream>
#define MAX(a, b) a > b ? a : b

using namespace std;

int dp[301];
int arr[301];

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[0] = 0;
	arr[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++)
	{
		dp[i] = MAX(dp[i-3] + arr[i-1], dp[i-2]) + arr[i];
	}
	printf("%d\n", dp[n]);
}