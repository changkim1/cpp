#include <iostream>
#include <stack>

using namespace std;

int seq[1000001];
int ans[1000001];

int main(void)
{
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];
	for (int i = n - 1; i >= 0; i--)
	{
		if (!s.empty())
		{
			while (!s.empty())
			{
				if (seq[i] > s.top())
					s.pop();
				else
					break ;
			}
			if (!s.empty())
				ans[i] = s.top();
			else
				ans[i] = -1;
		}
		else
			ans[i] = -1;
		s.push(seq[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << ' ';	
	}
	cout << '\n';
}