#include <iostream>
#include <queue>

using namespace std;

string input;
queue<int> q;
queue<char> sq;

int main(void)
{
	int i = 0;
	int first;
	int first_check = 0;
	int num;
	char sign;
	string tmp;
	cin >> input;
	input += '.';
	while (input[i])
	{
		if (input[i] == '-' || input[i] == '+' || input[i] == '.')
		{
			if (!first_check)
			{
				first = stoi(tmp);
				first_check = 1;
			}
			else
				q.push(stoi(tmp));
			tmp.clear();
			sq.push(input[i]);
		}
		else
			tmp.push_back(input[i]);
		i++;
	}
	int save;
	while (!sq.empty())
	{
		save = 0;
		sign = sq.front();
		sq.pop();
		if (sign == '+')
		{
			num = q.front();
			q.pop();
			first += num;
		}
		else if (sign == '-')
		{
			num = q.front();
			q.pop();
			save += num;
			sign = sq.front();
			while (sign == '+')
			{
				sq.pop();
				num = q.front();
				q.pop();
				save += num;
				sign = sq.front();
			}
			first -= save;
		}
		else
			continue ;
	}
	cout << first << '\n';
}