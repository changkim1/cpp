#include <iostream>
#include <string>
#include <stack>
using namespace std;

string	cmd;
int	n;
stack<int> stk;

int main(void)
{
	string	tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp.compare("push") == 0)
		{
			cin >> tmp;
			stk.push(stoi(tmp));
		}
		else if (tmp.compare("pop") == 0)
		{
			if(!stk.empty())
			{
				cout << stk.top() << '\n';
				stk.pop();
			}
			else
				cout << "-1" << '\n';
		}
		else if (!tmp.compare("top"))
		{
			if (!stk.empty())
				cout << stk.top() << '\n';
			else
				cout << "-1" << '\n';
		}
		else if (!tmp.compare("size"))
		{
			cout << stk.size() << '\n';
		}
		else if (!tmp.compare("empty"))
		{
			if (stk.empty())
				cout << '1' << '\n';
			else
				cout << '0' << '\n';
		}
	}
}