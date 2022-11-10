#include <iostream>

using namespace std;

int n;

int main(void)
{
	int cnt = 0;
	cin >> n;
	int change = 1000 - n;
	while (change > 0)
	{
		if (change >= 500)
		{
			change -= 500;
			cnt++;
		}
		else if (change >= 100)
		{
			change -= 100;
			cnt++;
		}
		else if (change >= 50)
		{
			change -= 50;
			cnt++;
		}
		else if (change >= 10)
		{
			change -= 10;
			cnt++;
		}
		else if (change >= 5)
		{
			change -= 5;
			cnt++;
		}
		else if (change >= 1)
		{
			change -= 1;
			cnt++;
		}
	}
	cout << cnt << '\n';
}