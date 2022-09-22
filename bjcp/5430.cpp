#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

deque<char> com;
deque<int> num;
int n, t, r_c;
string inp, tmp;

void	solve()
{
	char c;
	r_c = 1;
	while (!com.empty())
	{
		c = com.front();
		com.pop_front();
		if (c == 'R')
			r_c *= -1;
		else if (c == 'D')
		{
			if (num.empty())
			{
				cout << "error" << '\n';
				return ;
			}
			if (r_c == -1)
				num.pop_back();
			else
				num.pop_front();
		}
	}
	printf("[");
	if (r_c == 1)
	{
		for (int i = 0; i < (int)num.size(); i++)
		{
			printf("%d", num[i]);
			if (i + 1 < (int)num.size())
				printf(",");
		}
	}
	else
	{
		for (int i = (int)num.size() - 1; i >= 0; i--)
		{
			printf("%d", num[i]);
			if (i != 0)
				printf(",");
		}
	}
	printf("]\n");
}

int main(void)
{
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		cin >> tmp;
		com.clear();
		num.clear();
		for (int i = 0; i < (int)tmp.size(); i++)
			com.push_back(tmp[i]);
		cin >> n;
		cin >> tmp;
		for (int i = 0; i < (int)tmp.size(); i++)
		{
			if (!isdigit(tmp[i]))
				continue ;
			inp.clear();
			while (isdigit(tmp[i]))
			{
				inp += tmp[i];
				i++;
			}
			num.push_back(stoi(inp));
		}
		solve();
	}
}