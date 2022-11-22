#include <iostream>
#include <deque>

using namespace std;

deque<char> dq1;
deque<char> dq2;

void	L(void)
{
	char c;
	if (dq1.empty())
		return ;
	c = dq1.back();
	dq1.pop_back();
	dq2.push_front(c);
}

void	D(void)
{
	char c;
	if (dq2.empty())
		return ;
	c = dq2.front();
	dq2.pop_front();
	dq1.push_back(c);
}

void	B(void)
{
	if (dq1.empty())
		return ;
	dq1.pop_back();
}

void	P(char c)
{
	dq1.push_back(c);
}

int main(void)
{
	int n;
	string inp;
	char c;
	cin >> inp;
	for (int i = 0; i < (int)inp.size(); i++)
		dq1.push_back(inp[i]);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		if (inp[0] == 'L')
			L();
		else if (inp[0] == 'D')
			D();
		else if (inp[0] == 'B')
			B();
		else if (inp[0] == 'P')
		{
			cin >> c;
			P(c);
		}
	}
	while (!dq1.empty())
	{
		cout << dq1.front();
		dq1.pop_front();
	}
	while (!dq2.empty())
	{
		cout << dq2.front();
		dq2.pop_front();
	}
}