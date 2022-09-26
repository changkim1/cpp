#include <iostream>
#include <queue>
#define MAX 200010
#define min(a, b) (a < b ? a : b)

using namespace std;

int n, k;

queue<int> q;
int vis[2 * MAX];
int dep[2 * MAX];

int solve()
{
	int tmp;

	q.push(n);
	vis[n] = 1;
	dep[n] = 0;
	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		if (tmp == k)
			return (dep[tmp]);
		if (tmp > 0 && (tmp - 1) < MAX && !vis[tmp - 1])
		{
			q.push(tmp - 1);
			vis[tmp - 1] = 1;
			dep[tmp - 1] = dep[tmp] + 1;
		}
		if ((tmp + 1) < MAX && !vis[tmp + 1])
		{
			q.push(tmp + 1);
			vis[tmp + 1] = 1;
			dep[tmp + 1] = dep[tmp] + 1;
		}
		if ((2 * tmp) < MAX && !vis[2 * tmp])
		{
			q.push(2 * tmp);
			vis[2 * tmp] = 1;
			dep[2 * tmp] = dep[tmp] + 1;
		}
	}
	return (-1);
}

int main(void)
{
	int ans;
	cin >> n >> k;
	ans = solve();
	cout << ans << '\n';
}