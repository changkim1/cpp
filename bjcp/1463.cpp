#include <iostream>
#define MAX 1000001

using namespace std;

int	ans[MAX];
int n;

int main(void)
{
	int tmp;
	cin >> n;
	ans[2] = 1;
	ans[3] = 1;
	ans[1] = 0;
	for (int i = 4; i <= n; i++)
	{
		if (i % 3 != 0 && i % 2 == 0)
			ans[i] = ans[i/2] < ans[i-1] ? ans[i/2] + 1: ans[i-1] + 1;
		else if (i % 2 != 0 && i % 3 == 0)
			ans[i] = ans[i/3] < ans[i-1] ? ans[i/3] + 1 : ans[i-1] + 1;
		else if (i % 2 != 0 && i % 3 != 0)
			ans[i] = ans[i-1] + 1;
		else
		{
			tmp = ans[i/2] < ans[i/3] ? ans[i/2] : ans[i/3];
			ans[i] = tmp < ans[i-1] ? tmp + 1 : ans[i-1] + 1;
		}
	}
	cout << ans[n] << '\n';
}