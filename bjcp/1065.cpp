#include <iostream>
#include <string>

using namespace std;

int n;
string inp;
int cnt;

void	solve(string inp)
{
	
	int interval = inp[0] - inp[1];
	int tmp, i = 1;
	while (inp[i + 1])
	{
		if (inp[i] - inp[i+1] != interval)
			return ;
		i++;
	}
	cnt++;
}

int main(void)
{
	cin >> n;
	if (n < 100)
	{
		cout << n << endl;
		return 0;
	}
	cnt = 99;
	for (int i = 100; i <= n; i++)
	{
		inp = to_string(i);
		solve(inp);
	}
	cout << cnt << endl;
}