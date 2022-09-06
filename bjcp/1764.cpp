#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<int, string> d_man;
map<string, int> b_man;
string result[500001];
int n, m;


int main(void)
{
	string tmp;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		d_man.insert({i, tmp});
	}
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		b_man.insert({tmp, i});
	}
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		tmp = d_man.at(i);
		if (b_man.find(tmp) != b_man.end())
		{
			result[j] = tmp;
			j++;
		}
	}
	sort(result, result + j);
	cout << j << '\n';
	for (int i = 0; i < j; i++)
	{
		cout << result[i] << '\n';
	}
}