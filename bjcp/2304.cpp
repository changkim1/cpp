#include <iostream>
#include <deque>
#define MAX 1001
using namespace std;

// MAX 왼쪽 , (MAX 사이), MAX 오른쪽
// 왼쪽 : max_hi 갱신시키면서 높이를 쌓아감
// 사이 : max_hi * 가로길이
// 오른쪽 : 뒤에서부터 max_hi 갱신시키면서 높이 쌓아감.

deque<int> dq;
int map[MAX]; // idx == x, value == y
int n;
int max_idx[2];
int max_hi;
int max_wi;
int ans;

void	solve_left()
{
	int tmp_max;
	tmp_max = 0;
	for (int i = 0; i < max_idx[0]; i++)
	{
		if (tmp_max < map[i])
			tmp_max = map[i];
		ans += tmp_max;
	}
}

void	solve_mid()
{
	for (int i = max_idx[0]; i <= max_idx[1]; i++)
		ans += max_hi;
}

void	solve_right()
{
	int tmp_max;
	tmp_max = 0;
	for (int i = max_wi; i > max_idx[1]; i--)
	{
		if (tmp_max < map[i])
			tmp_max = map[i];
		ans += tmp_max;
	}
}

int main(void)
{
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		cin >> map[tmp];
		if (map[tmp] > max_hi)
			max_hi = map[tmp];
		if (tmp > max_wi)
			max_wi = tmp;
	}
	max_idx[1] = -1;
	for (int i = 0; i <= max_wi; i++)
	{
		if (map[i] == max_hi)
		{
			if (max_idx[0] == 0)
				max_idx[0] = i;
			else
				max_idx[1] = i;
		}
	}
	if (max_idx[1] == -1)
		max_idx[1] = max_idx[0];
	solve_left();
	solve_mid();
	solve_right();
	cout << ans << '\n';
}