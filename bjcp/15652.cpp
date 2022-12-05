#include <iostream>

using namespace std;

int n, m;
int arr[9];

void	solve(int idx, int tmp)
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
		if (tmp <= i)
		{
			arr[idx] = i;
			solve(idx + 1, i);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	solve(0, 0);
}