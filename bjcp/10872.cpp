#include <iostream>

using namespace std;

int n;
int ans = 1;

void	solve(int cnt)
{
	if (cnt == n + 1)
	{
		cout << ans << '\n';
		return ;
	}
	ans *= cnt;
	solve(cnt + 1);
}

int main(void)
{
	cin >> n;
	solve(1);
}