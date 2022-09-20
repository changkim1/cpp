#include <iostream>
#define MAX 5001
using namespace std;

int n;
int solve[MAX];

int main(void)
{
	cin >> n;
	for (int i = 1; i < 6; i++)
	{
		if (i == 3 || i == 5)
			solve[i] = 1;
		else
			solve[i] = -1;
	}
	for (int i = 6; i <= n; i++)
	{
		if (solve[i - 3] == -1 && solve[i - 5] == -1)
			solve[i] = -1;
		else
		{
			if (solve[i - 3] == -1)
				solve[i] = solve[i - 5] + 1;
			else if (solve[i - 5] == -1)
				solve[i] = solve[i - 3] + 1;
			else if (solve[i - 3] > solve[i - 5])
				solve[i] = solve[i - 5] + 1;
			else
				solve[i] = solve[i - 3] + 1;
		}
	}
	cout << solve[n] << '\n';
}