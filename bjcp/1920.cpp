#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int num[100001];

void	binary_search(int inp)
{
	int l, r, mid;
	l = 0;
	r = n-1;
	mid = (l + r) / 2;
	while (l + 1 < r)
	{
		if (num[l] == inp || num[r] == inp || num[mid] == inp)
		{
			cout << "1" << '\n';
			return ;
		}
		else if (num[mid] > inp)
		{
			r = mid;
			mid = (l + r) / 2;
		}
		else
		{
			l = mid;
			mid = (l + r) / 2;
		}
	}
	cout << "0" << '\n';
}

int	compare(int a, int b)
{
	return (a < b);
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	int inp;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	sort(num, num + n, compare);
	cin >> m;
	for (int j = 0; j < m; j++)
	{
		cin >> inp;
		binary_search(inp);
	}
}