#include <iostream>

using namespace std;

int n, m;
int vis[9] = {0, };
int arr[9] = {0, };


void	dfs(int cnt, int tmp)
{
	if (cnt == m)
	{
		for (int i = 0; i < cnt; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] && tmp < i)
		{
			vis[i] = 1;
			arr[cnt] = i;
			dfs(cnt + 1, i);
			vis[i] = 0;
		}
	}
}


int main(void)
{
	cin >> n >> m;
	dfs(0, 0);
}