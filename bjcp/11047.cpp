#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int price[11];

int compare(int a, int b)
{
	return (a > b);
}

int main(void)
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	sort(price, price + n, compare);
	int tmp, i, cnt;
	cnt = 0;
	tmp = k;
	i = 0;
	while (tmp > 0)
	{
		while (price[i] != 0 && price[i] > tmp)
			i++;
		while (tmp > price[i])
		{
			tmp = tmp - price[i];
			cnt++;
		}
		if (tmp == price[i])
		{
			cnt++;
			break ;
		}
	}
	cout << cnt << endl;
}