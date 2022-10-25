#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> m;

int main(void)
{
	int n, check, cnt = 0;
	string inp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		check = 0;
		m.clear();
		for (int j = 1; j < inp.size(); j++)
		{
			if (m.find(inp[j]) != m.end())
			{
				check = 1;
				break ;
			}
			if (inp[j - 1] != inp[j])
				m.insert({inp[j-1], j});
		}
		if (check == 0)
			cnt++;
	}
	cout << cnt << endl;
}