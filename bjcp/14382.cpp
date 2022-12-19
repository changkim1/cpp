#include <iostream>
#include <string>

using namespace std;

int n;
int t, cnt;
bool check[10];

int main(void)
{
	long long nn;
	cin >> t;
	string tmp;
	for (int a = 0; a < t; a++)
	{
		cin >> n;
		if (n == 0)
		{
			printf("Case #%d: INSOMNIA\n", a + 1);
			continue ;
		}
		cnt = 0;
		fill_n(check, 10, false);
		for (int i = 1; i <= 100; i++)
		{
			nn = n * i;
			tmp = to_string(nn);
			for (int i = 0; i < (int)tmp.size(); i++)
			{
				if (check[tmp[i] - '0'] == false)
				{
					check[tmp[i] - '0'] = true;
					cnt++;
				}
			}
			if (cnt == 10)
			{
				printf("Case #%d: %lld\n", a + 1, nn);
				break ;
			}
		}
	}
}