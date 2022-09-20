#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

string	input;
map<string, int> res;

int main(void)
{
	cin >> input;
	int n = input.size();
	string	tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			tmp = input.substr(i, j - i + 1);
			res.insert({tmp, i});
		}
	}
	cout << res.size();
}