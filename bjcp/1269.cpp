#include <iostream>
#include <map>
#include <string>
using namespace std;

int n, m;
map<int, int> a;
map<int, int> b;

int main(void)
{
	int tmp, ab;
	ab = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		a.insert({i, tmp});
	}
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		b.insert({tmp, i});
	}
	for (int i = 0; i < n; i++)
	{
		tmp = a[i];
		if (b.find(tmp) != b.end())
			ab++;
	}
	int res = n + m - (2 * ab);
	cout << res << '\n';
}