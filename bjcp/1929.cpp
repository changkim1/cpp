#include <iostream>

using namespace std;



int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++)
	{
		int idx = 2;
		if (i == 1)
			continue ;
		while (idx * idx <= i)
		{
			if (i % idx == 0)
				break ;
			idx++;
		}
		if (idx * idx > i)
			cout << i << '\n';
	}
}