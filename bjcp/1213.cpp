#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string inp;
string split[27];
string ans;


int main(void)
{
	int odd_idx = -1;
	cin >> inp;
	sort(inp.begin(), inp.end());
	int j = 0;
	for (int i = 0; i < inp.size(); i++)
	{
		split[j].push_back(inp[i]);
		if (inp[i] != inp[i + 1])
		{
			if (split[j].size() % 2 == 1)
			{
				if (inp.size() % 2 == 1)
				{
					if (odd_idx == -1)
						odd_idx = j;
					else
					{
						cout << "I'm Sorry Hansoo" << endl;
						return 0;
					}
				}
				else
				{
					cout << "I'm Sorry Hansoo" << endl;
					return 0;
				}
			}
			j++;
		}
	}
	for (int i = 0; i < j; i++)
	{
		for (int a = 0; a < split[i].size() / 2; a++)
			ans += split[i][0];
	}
	if (odd_idx != -1)
		ans += split[odd_idx][0];
	for (int i = j - 1; i >= 0; i--)
	{
		for (int a= 0; a< split[i].size() / 2; a++)
			ans += split[i][0];
	}
	cout << ans << endl;
}