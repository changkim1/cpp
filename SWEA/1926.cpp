#include <iostream>
#include <string>

using namespace std;

int n;
string num;
string ans;
int check;

void	solve(string num)
{
	check = 0;
	ans.clear();
	for (int i = 0; i < (int)num.size(); i++)
	{
		if (num[i] == '3' || num[i] == '6' || num[i] == '9')
		{
			ans += '-';
			check = 1;
		}
	}
	if (check == 1)
		cout << ans << ' ';
	else
		cout << num << ' ';
}

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		num = to_string(i);
		solve(num);
	}
}