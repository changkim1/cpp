#include <iostream>
#include <map>
#include <iterator>

#define MAX 100001

using namespace std;

int n, m;
map<string, int> pok;
string	name[MAX];
string	ans[MAX];

int main(void)
{
	cin.tie(0);
	string tmp;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		pok.insert({tmp, i});
		name[i] = tmp;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (isdigit(tmp[0]))
			ans[i] = name[stoi(tmp) - 1];
		else
			ans[i] = to_string(pok[tmp] + 1);
	}
	for (int i = 0; i < m; i++)
	{
		cout << ans[i] << '\n';
	}
}