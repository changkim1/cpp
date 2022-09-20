#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int> stk;
queue<char> ans;
int n;
int arr[1000001];

int main(void)
{
	int	num;

	num = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int i;
	i = 0;
	while (i < n)
	{
		if (stk.empty())
		{
			stk.push(num);
			ans.push('+');
			num++;
			continue ;
		}
		while (stk.top() < arr[i])
		{
			stk.push(num);
			ans.push('+');
			num++;
		}
		if (stk.top() == arr[i])
		{
			stk.pop();
			ans.push('-');
			i++;
		}
		else if (stk.top() > arr[i])
		{
			cout << "NO" << '\n';
			return (0);
		}
	}
	while (!ans.empty())
	{
		cout << ans.front() << '\n';
		ans.pop();
	}
}