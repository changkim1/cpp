#include <iostream>
#define endl '\n'
using namespace std;

int t, n, mx;
int ans[50][2];

void solve(int a)
{
	for (int i = 2; i <= a; i++)
	{
		if (ans[i][0] != 0 || ans[i][1] != 0)
			continue ;
		ans[i][0] = ans[i - 1][0] + ans[i - 2][0];
		ans[i][1] = ans[i - 1][1] + ans[i - 2][1];
	}
	cout << ans[a][0] << ' ' << ans[a][1] << endl;
}

int main(void)
{
	int num;
	cin >> t;
	ans[0][0] = 1;
	ans[0][1] = 0;
	ans[1][0] = 0;
	ans[1][1] = 1;
	for (int i = 0; i < t; i++)
	{
		cin >> num;
		solve(num);
	}

}