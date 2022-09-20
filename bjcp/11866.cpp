#include <iostream>
#include <queue>

using namespace std;
int n, k;
queue<int> q, ans;
int main(void)
{
	int count, tmp;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		q.push(i+1);
	while (!q.empty())
	{
		for (count = k-1; count > 0; count--)
		{
			tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		ans.push(q.front());
		q.pop();
	}
	cout << '<';
	while (!ans.empty())
	{
		cout << ans.front();
		ans.pop();
		if (!ans.empty())
			cout << ", ";
	}
	cout << '>';
}