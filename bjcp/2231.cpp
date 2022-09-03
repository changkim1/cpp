#include <iostream>

using namespace std;

int	num[1000005];

void	solve(int n)
{
	int	cre;
	int tmp;

	cre = n;
	tmp = n;
	while (n > 0)
	{
		cre += n % 10;
		n /= 10;
	}
	num[tmp] = cre;
}

int main(void)
{
	int n;

	cin >> n;
	for (int i = 1; i < n; i++)
		solve(i);
	for (int i = 1; i < n; i++)
	{
		if (num[i] == n)
		{
			printf("%d\n", i);
			return (0);
		}
	}
	printf("0\n");
}