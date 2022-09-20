#include <iostream>
#include <stack>

using namespace std;

stack<char> stk;

int		pop_check(char c)
{
	if (c == ']')
	{
		if (!stk.empty() && stk.top() == '[')
			return (1);
	}
	else if (c == ')')
	{
		if (!stk.empty() && stk.top() == '(')
			return (1);
	}
	return (0);
}

void	solve(string tmp)
{
	int i;

	i = 0;
	while (tmp[i] != '.')
	{
		if (tmp[i] == '(' || tmp[i] == '[')
			stk.push(tmp[i]);
		else if (tmp[i] == ')' || tmp[i] == ']')
		{
			if (pop_check(tmp[i]))
				stk.pop();
			else
			{
				cout << "no" << endl;
				return ;
			}
		}
		i++;
	}
	if (stk.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

int main(void)
{
	string tmp;
	getline(cin, tmp);
	while (tmp.compare("."))
	{
		solve(tmp);
		while (!stk.empty())
			stk.pop();
		getline(cin, tmp);
	}
}