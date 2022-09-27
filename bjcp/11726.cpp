#include <iostream>
#define MAX 1001
using namespace std;

long long ans[MAX];
int n;

int main(void)
{
	cin >> n;
	ans[1] = 1;
	ans[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		ans[i] = ans[i - 1] + ans[i - 2];
		if (ans[i] > 10007)
			ans[i] = ans[i] % 10007;
	}
	cout << (ans[n]) << '\n';
}