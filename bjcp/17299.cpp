#include <iostream>
#include <stack>
#define MAX 1000001

using namespace std;

int seq[MAX];
int ans[MAX];
int cnt[MAX];
stack<int> s;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
		cnt[seq[i]]++;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (!s.empty())
		{
			while (!s.empty())
			{
				if (cnt[seq[i]] >= cnt[s.top()])
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