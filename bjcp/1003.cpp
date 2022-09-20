#include <iostream>
#define endl '\n'
using namespace std;

int t, n, max;

int	solve(int a)
{
	if (a == 1)
	{
		ans[1]++;
		return (1);
	}
	else if (a == 0)
	{
		ans[0]++;
		return (0);
	}
	else
		return (solve(a-1) + solve(a-2));
}

int main(void)
{
	cin >> t;
	pair<int, int> ans;
	for (int i = 0; i < t; i++)
	{
		
	}
}