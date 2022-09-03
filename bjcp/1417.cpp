#include <iostream>
#include <algorithm>

using namespace std;

int	hum[51];
int n;

int	is_finish(int dasom)
{
	int	i;

	i = 0;
	while (i < n-1)
	{
		if (dasom <= hum[i])
			return (0);
		i++;
	}
	return (1);
}

int main(void)
{
	int	dasom;
	int	ans;
	int i;

	i = 0;
	ans = 0;
	cin >> n;
	cin >> dasom;
	for (int i = 0; i < n - 1; i++)
		cin >> hum[i];
	while (!is_finish(dasom))
	{
		sort(hum, hum + n - 1, greater<>());
		if (dasom <= hum[0])
		{
			dasom++;
			hum[0]--;
			ans++;
		}
	}
	cout << ans << endl;
}