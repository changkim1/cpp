#include <iostream>
#include <string>
#include <stack>

using namespace std;

string inp;
stack<char> s;

int main(void)
{
	getline(cin, inp);
	inp += ' ';
	for (int i = 0; i < (int)inp.size(); i++)
	{
		if (inp[i] == ' ' || inp[i] == '<')
		{
			while (!s.empty())
			{
				cout << s.top();
				s.pop();
			}
			if (inp[i] == '<')
			{
				while (inp[i] != '>')
				{
					cout << inp[i];
					i++;
				}
				cout << inp[i];
				continue ;
			}
			cout << ' ';
		}
		else
			s.push(inp[i]);
	}
	cout << '\n';
}