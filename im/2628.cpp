#include <iostream>

using namespace std;

int l, r, u, d;


void	solve_one_time(int wh, int num)
{
	if (wh == 1)
	{
		if (num < l || num > r)
			return ;
		if (num - l >= r - num)
			r = num;
		else
			l = num;
	}
	else
	{
		if (num < u || num > d)
			return ;
		if (num - u >= d - num)
			d = num;
		else
			u = num;
	}
}

int main(void)
{
	int wh, num;
	cin >> r >> d;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> wh >> num;
		solve_one_time(wh, num);
	}
	int ans = (r - l) * (d - u);
	printf("%d\n", ans);
}