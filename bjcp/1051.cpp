#include <iostream>
#include <string>

using namespace std;

int map[51][51];

int n, m;
int size_;

int	check(int i, int j, int x, int y)
{
	return (map[i][j] == map[i][x] && map[i][j] == map[y][j] && map[i][j] == map[y][x]);
}

int main(void)
{
	int x, y, tmp;
	string inp;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = inp[j];	
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x = j;
			y = i;
			while (y < n && x < m)
			{
				if (check(i, j, x, y))
				{
					tmp = (x - j + 1) * (x - j + 1);
					if (tmp > size_)
						size_ = tmp;
				}
				x++;
				y++;
			}
		}
	}
	cout << size_ << '\n';
}