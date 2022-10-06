#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

string ans;

deque<pair<string, int>> dq;
map<string, int> v;

string A(string num)
{
	char tmp;
	for (int i = 0; i < 4; i++)
	{
		tmp = num[i];
		num[i] = num[7 - i];
		num[7 - i] = tmp;
	}
	return num;
}

string B(string num)
{
	char tmp, tmp1;
	tmp = num[3];
	tmp1 = num[4];
	for (int i = 0; i < 3; i++)
	{
		num[3 - i] = num[2 - i];
		num[i + 4] = num[i + 5];
	}
	num[0] = tmp;
	num[7] = tmp1;
	return num;
}

string C(string num)
{
	char tmp;
	tmp = num[1];
	num[1] = num[2];
	num[2] = num[5];
	num[5] = num[6];
	num[6] = tmp;
	return num;
}

string	D(string num)
{
	char tmp;
	tmp = num[0];
	num[0] = num[4];
	num[4] = tmp;
	return num;
}

string action(string now, int idx)
{
	string tmp;
	if (idx == 0)
		tmp = A(now);
	else if (idx == 1)
		tmp = B(now);
	else if (idx == 2)
		tmp = C(now);
	else if (idx == 3)
		tmp = D(now);
	return tmp;
}

void	bfs(string num)
{
	pair<string, int> now, tmp;
	int cnt = 0;
	dq.push_back({num, 0});
	v.insert({num, 0});
	while (!dq.empty())
	{
		now = dq.front();
		dq.pop_front();
		for (int i = 0; i < 4; i ++)
		{
			tmp.first = action(now.first, i);
			tmp.second = now.second + 1;
			if (tmp.first == ans)
			{
				cout << tmp.second << endl;
				return ;
			}
			if (v.find(tmp.first) != v.end())
				continue ;
			else
			{
				dq.push_back(tmp);
				v.insert({tmp.first, 0});
			}
		}
	}
}

int main(void)
{
	char c;
	string num;
	for (int i = 0; i < 8; i++)
	{
		cin >> c;
		ans += c;
		num += (i + '1');
	}
	if (num == ans)
	{
		cout << "0" << endl;
		return 0;
	}
	bfs(num);
}