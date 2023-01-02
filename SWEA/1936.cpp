#include <iostream>

using namespace std;

// 1 < 2 < 3 < 1

int main()
{
	int a, b;
	char ans;
	cin >> a >> b;
	if (a != 1 && b != 1)
	{
		ans = a > b ? 'A' : 'B';
	}
	else if (a == 1 || b == 1)
	{
		if (a == 1 && b == 3)
			ans = 'A';
		else if (b == 1 && a == 3)
			ans = 'B';
	}
	cout << ans << '\n';
}