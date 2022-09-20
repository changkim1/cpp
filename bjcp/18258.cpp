#include <iostream>
#include <queue>

using namespace std;

queue<int> que;
queue<int> ans;
int n;

int main(void)
{
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ios::sync_with_stdio(false);
	string tmp;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp[1] == 'u')
		{
			cin >> num;
			que.push(num);
		}
		else if (tmp[0] == 'p')
		{
			if (que.empty())
			{
				cout << "-1" << '\n';
				continue ;
			}
			cout << que.front() << '\n';
			que.pop();
		}
		else if (tmp[0] == 's')
		{
			cout << que.size() << '\n';
		}
		else if (tmp[0] == 'e')
		{
			if (!que.empty())
				cout << '0' << '\n';
			else
				cout << '1' << '\n';
		}
		else if (tmp[0] == 'f')
		{
			if (que.empty())
			{
				cout << "-1" << '\n';
				continue ;
			}
			cout << que.front() << '\n';
		}
		else if (tmp[0] == 'b')
		{
			if (que.empty())
			{
				cout << "-1" << '\n';
				continue ;
			}
			cout << que.back() << '\n';
		}
	}
}