#include <iostream>

using namespace std;

int n;
int f[21];

void	solve(int cnt)
{
	if (cnt == n + 1)
		return ;
	f[cnt] = f[cnt - 1] + f[cnt - 2];
	solve(cnt + 1);
}

int main(void)
{
	f[0] = 0;
	f[1] = 1;
	cin >> n;
	if (n == 0 || n == 1)
	{
		cout << f[n] << '\n';
		return 0;
	}
	solve(2);
	cout << f[n] << '\n';
}