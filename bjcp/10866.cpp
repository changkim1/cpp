#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int n;

int main(void)
{
	string tmp;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == "push_front")
		{
			cin >> num;
			dq.push_front(num);
		}
		else if (tmp == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}
		else if (tmp == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << "-1" << '\n';
		}
		else if (tmp == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << "-1" << '\n';
		}
		else if (tmp == "size")
			cout << dq.size() << '\n';
		else if (tmp == "empty")
		{
			if (dq.empty())
				cout << "1" << '\n';
			else
				cout << "0" << '\n';
		}
		else if (tmp == "front")
		{
			if (dq.empty())
				cout << "-1" << '\n';
			else
				cout << dq.front() << '\n';
		}
		else if (tmp == "back")
		{
			if (dq.empty())
				cout << "-1" << '\n';
			else
				cout << dq.back() << '\n';
		}
	}	
}