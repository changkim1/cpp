#include <iostream>
#include <cmath>

using namespace std;

int n, m, _max, cnt;

void	solve(int dis)
{
	int ans;
	_max = (int)sqrt(dis);
	ans = 2 * _max - 1;
	if (dis > _max * _max)
		ans++;
	if (dis > (_max+1) * (_max+1) - (_max + 1))
		ans++;
	cout << ans << endl;
}

int main(void)
{
	int t, dis;
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		cin >> n >> m;
		dis = m - n;
		solve(dis);
	}
}