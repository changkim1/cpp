#include <iostream>
#include <map>
#define MAX 10001

using namespace std;

map<string, int> set;
int ans;
int n, m;

int main(void)
{
	string	tmp;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		set.insert({tmp, i});
	}
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (set.find(tmp) != set.end())
			ans++;
	}
	cout << ans << '\n';
}