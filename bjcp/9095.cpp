#include <iostream>

using namespace std;

int n, t;
int ans[12];

void	solve(void)
{
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	for (int i = 4; i < 11; i++)
	{
		for (int j = i-3; j<i;j++)
			ans[i] += ans[j];
	}
}

int main(void)
{
	cin >> t;
	solve();
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << ans[n] << endl;
	}
}