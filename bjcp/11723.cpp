#include <iostream>
#include <map>
#include <string>

using namespace std;

map<int, int> S, tmp;
int n;
string com;
int num, idx;

void	add(int num)
{
	S.insert({num, idx});
	idx++;
}

void	remove(int num)
{
	S.erase(num);
	idx--;
}

void	check(int num)
{
	if (S.find(num) == S.end())
		cout << '0' << '\n';
	else
		cout << '1' << '\n';
}

void	toggle(int num)
{
	if (S.find(num) == S.end())
		add(num);
	else
		remove(num);
}

void	all(void)
{
	copy(tmp.begin(), tmp.end(), inserter(S, S.begin()));
	idx = 20;
}

void	empty(void)
{
	S.clear();
	idx = 0;
}

int main(void)
{
	cin >> n;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for (int i = 0; i < 20; i++)
	{
		tmp.insert({i+1, i+1});
	}
	for (int i = 0; i < n; i++)
	{
		cin >> com;
		if (!com.compare("add"))
		{
			cin >> num;
			add(num);
		}
		else if (!com.compare("remove"))
		{
			cin >> num;
			remove(num);
		}
		else if (!com.compare("check"))
		{
			cin >> num;
			check(num);
		}
		else if (!com.compare("toggle"))
		{
			cin >> num;
			toggle(num);
		}
		else if (!com.compare("all"))
			all();
		else if (!com.compare("empty"))
			empty();
	}
}