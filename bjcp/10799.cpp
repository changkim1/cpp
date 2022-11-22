#include <iostream>
#include <stack>

using namespace std;

stack<char> s;

int main(void)
{
	int cnt = 0;
	string inp;
	cin >> inp;
	for (int i = 0; i < (int)inp.size(); i++)
	{
		if (inp[i] == '(')
			s.push(inp[i]);
		else if (inp[i] == ')')
		{
			s.pop();
			if (inp[i - 1] == '(')
				cnt += (int)s.size();
			else if (inp[i - 1] == ')')
			{
				cnt += 1;
			}
		}
	}
	cout << cnt << '\n';
}