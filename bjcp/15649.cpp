#include <iostream>
#define MAX 9

using namespace std;

int n, m;
int arr[MAX] = {0, };
int vis[MAX] = {0, };

void	dfs(int cnt)
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
		if (vis[i] == 1)
			continue ;
		vis[i] = 1;
		arr[cnt] = i;
		dfs(cnt + 1);
		vis[i] = 0;
	}
}


int main(void)
{
	cin >> n >> m;
	dfs(0);
}