#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <map>

using namespace std;

stack<double> s;
string inp;

map<char, double> m;

int main(void)
{
	int n, num;
	char c = 'A';
	cin >> n;
	cin >> inp;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		m.insert({c, num});
		c++;
	}
	for (int i = 0; i < (int)inp.size(); i++)
	{
		if (isalpha(inp[i]))
		{
			auto tmp = m.find(inp[i]);
			s.push(tmp->second);
		}
		else
		{
			double tmp = s.top();
			s.pop();
			if (inp[i] == '+')
				tmp += s.top();
			else if (inp[i] == '-')
				tmp = s.top() - tmp;
			else if (inp[i] == '*')
				tmp *= s.top();
			else if (inp[i] == '/')
				tmp = s.top() / tmp;
			s.pop();
			s.push(tmp);
		}
	}
	printf("%.2f\n", s.top());
}