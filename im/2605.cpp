#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int> s1, s2;
int n, cnt;

int main(void)
{
	cin >> n >> cnt;
	s1.push(1);
	for (int i = 1; i < n; i++)
	{
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(i + 1);
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	while (!s1.empty())
	{
		s2.push(s1.top());
		s1.pop();
	}
	while (!s2.empty())
	{
		cout << s2.top() << ' ';
		s2.pop();
	}
	cout << '\n';
}
