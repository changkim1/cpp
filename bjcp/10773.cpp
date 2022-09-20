#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
int	k;

int main(void)
{
	int tmp;
	int res;

	cin >> k;
	res = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		if (tmp == 0)
			stk.pop();
		else
			stk.push(tmp);
	}
	while (!stk.empty())
	{
		tmp = stk.top();
		stk.pop();
		res += tmp;
	}
	cout << res << endl;
}