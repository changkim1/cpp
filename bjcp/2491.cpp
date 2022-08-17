#include <iostream>

using namespace std;

int len;
int n;
int num[100001];
int	dif[100001];
int stat[100001];

void	solve()
{
	int tmp = 1;
	int	sig;

	for (int i = 0; i < n - 1; i++)
	{
		dif[i] = num[i] - num[i + 1];
		if (dif[i] != 0)
			stat[i] = dif[i] / abs(dif[i]);
		else
			stat[i] = 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (stat[i] == 0)
		{
			tmp++;
			continue ;
		}
		for (int j = 0; i + j < n; j++)
		{
			if (abs(stat[i] - stat[i + j]) == 2 || i + j == n - 1)
			{
				if (tmp > len)
					len = tmp;
				tmp = 1;
				break ;
			}
			else
				tmp++;
		}
	}
	if (tmp > len)
		len = tmp;
}

int main(void)
{
	len = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	if (n == 1)
	{
		cout << len << endl;
		return (0);
	}
	solve();
	cout << len << endl;
}