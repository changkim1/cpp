#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<char> stk;
int	n;

void	solve(string tmp)
{
	for (int i = 0; i < (int)tmp.length(); i++)
	{
		if (tmp[i] =='(')
			stk.push(tmp[i]);
		else
		{
			if (stk.empty() || stk.top() != '(')
			{
				cout << "NO" << endl;
				return ;
			}
			else
				stk.pop();
		}
	}
	if (stk.empty())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main(void)
{
	string tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		solve(tmp);
		while (!stk.empty())
			stk.pop();
	}
}