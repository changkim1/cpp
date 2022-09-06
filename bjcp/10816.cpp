#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;

int 	n, m;

int	under_bound(int num, int *set)
{
	int i = 0;
	int mid, end;
	end = n - 1;
	while (i < end)
	{
		mid = (i + end) / 2;
		if (set[mid] >= num)
			end = mid;
		else
			i = mid;
	}
}

int	upper_bound(int num, int *set)
{
	int i = 0;
	while (i < n && set[i] <= num)
		i++;
	return (i);
}

int main(void)
{
	int tmp, under, upper;
	cin >> n;
	int *set = new int[n];
	for (int i = 0; i < n; i++)
		cin >> set[i];
	sort(set, set + n);
	cin >> m;
	int *result = new int[m];
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (n == 1)
			result[i] = set[i];
		else
		{
			under = under_bound(tmp, set);
			upper = upper_bound(tmp, set);
			result[i] = upper - under;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << result[i] << ' ';
	}
	printf("\n");
}