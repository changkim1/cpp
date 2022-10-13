#include <iostream>
#include <cmath>
#include <unistd.h>

using namespace std;

int n, x, y, ans;

void	solve(int circle)
{
	if (circle == 0)
		return ;
	int quad;
	if (x <= ((int)pow(2, circle))/2)
	{
		if (y <= (int)pow(2, circle)/2)
			quad = 1;
		else
			quad = 3;
	}
	else
	{
		if (y <= (int)pow(2, circle)/2)
			quad = 2;
		else
			quad = 4;
	}
	ans += (int)pow(4, circle - 1) * (quad - 1);
	if (quad == 3 || quad == 4)
	{
		y -= (int)pow(2, circle - 1);
	}
	if (quad == 2 || quad == 4)
		x -= (int)pow(2, circle - 1);
	solve(circle - 1);
}

int main(void)
{
	int max_, circle;
	cin >> n >> y >> x;
	x++;
	y++;
	max_ = x > y ? x : y;
	if (max_ == 1)
		circle = 1;
	for (int i = 1; i <= n; i++)
	{
		if ((int)pow(2, i - 1) < max_ && max_ <= (int)pow(2, i))
		{
			circle = i;
			break ;
		}
	}
	solve(circle);
	cout << ans << endl;
}