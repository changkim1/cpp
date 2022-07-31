#include <iostream>
#include <cstring>
#define MAX 101

using namespace std;

int n, m;
int a[5];
int b[5];

void	winner_print(int check)
{
	if (check > 0)
		cout << 'A' << '\n';
	else if (check < 0)
		cout << 'B' << '\n';
	else
		cout << 'D' << '\n';
}

void	solve(void)
{
	if (a[4] != b[4])
	{
		winner_print(a[4] - b[4]);
		return ;
	}
	else
	{
		if (a[3] != b[3])
		{
			winner_print(a[3] - b[3]);
			return ;
		}
		else
		{
			if (a[2] != b[2])
			{
				winner_print(a[2] - b[2]);
				return ;
			}
			else
			{
				winner_print(a[1] - b[1]);
				return ;
			}
		}
	}
}

int main(void)
{
	int tmp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			a[tmp]++;			
		}
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			b[tmp]++;
		}
		solve();
	}
}