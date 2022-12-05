#include <iostream>

using namespace std;

int arr[8];
int n, m;

void	solve(int idx)
{
	if (idx == m)
	{
		for (int i = 0; i < idx; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[idx] = i;
		solve(idx + 1);
	}
}

int main(void)
{
	cin >> n >> m;
	solve(0);
}