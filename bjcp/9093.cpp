#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char>	s;

int main(void)
{
	int n;
	string inp;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, inp);
		inp += ' ';
		for (int j = 0; j < (int)inp.size(); j++)
		{
			if (inp[j] == ' ')
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << inp[j];
			}
			else
				s.push(inp[j]);
		}
		cout << '\n';
	}
}