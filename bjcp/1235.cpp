#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
string inp[1001];
int n, ans;

int main(void)
{
	string tmp;
	int size;
	ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inp[i];
	}
	size = inp[0].size();
	while (ans < size)
	{
		m.clear();
		for (int i = 0; i < n; i++)
		{
			inp[i].erase(0, 1);
			if (m.find(inp[i]) != m.end())
			{
				cout << size - ans + 1 << endl;
				return 0;
			}
			m.insert({inp[i], i});
		}
		ans++;
	}
	cout << "1" << endl;
}