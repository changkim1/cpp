#include <iostream>
#include <string>

using namespace std;

int num, n;
char b[10];

int main(void)
{
	int ans, ans_h, is_broken, tmp, idx;
	cin >> num;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	ans_h = abs(num - 100);
	ans = 500000;
	for (int i = 0; i < 1000000; i++)
	{
		is_broken = 0;
		for (int j = 0; j < n; j++)
		{
			if (to_string(i).find(b[j]) != string::npos)
			{
				is_broken = 1;
				break ;
			}
		}
		if (is_broken == 1)
			continue ;
		tmp = abs(num - i);
		if (tmp < ans)
		{
			ans = tmp;
			idx = i;
		}
	}
	ans = ans + (int)to_string(idx).size();
	if (ans_h < ans)
	{
		cout << ans_h << '\n';
		return (0);
	}
	printf("%d\n", ans);
}