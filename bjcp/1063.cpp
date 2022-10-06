#include <iostream>
#include <string>
using namespace std;

pair<char, int> king;
pair<char, int> stone;

int map[10][10];

int is_valid(char a, char b, int c, int d)
{
	return (a + b >= 'A' && a + b <= 'H' && c + d >= 1 && c + d <= 8);
}

void	action(string inp)
{
	pair<int, int> coo;
	if (inp == "R")
		coo = {1, 0};
	else if (inp == "L")
		coo = {-1, 0};
	else if (inp == "B")
		coo = {0, -1};
	else if (inp == "T")
		coo = {0, 1};
	else if (inp == "RT")
		coo = {1, 1};
	else if (inp == "LT")
		coo = {-1, 1};
	else if (inp == "RB")
		coo = {1, -1};
	else if (inp == "LB")
		coo = {-1, -1};
	if (is_valid(coo.first, king.first, coo.second, king.second))
	{
		king.first += coo.first;
		king.second += coo.second;
		if (king == stone)
		{
			if (is_valid(coo.first, stone.first, coo.second, stone.second))
			{
				stone.first += coo.first;
				stone.second += coo.second;
			}
			else
			{
				king.first -= coo.first;
				king.second -= coo.second;
			}
		}
	}
}

int main(void)
{
	int n;
	string inp;
	cin >> inp;
	king.first = inp[0];
	king.second = inp[1] - '0';
	cin >> inp;
	stone.first = inp[0];
	stone.second = inp[1] - '0';
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		action(inp);
	}
	cout << king.first << king.second << endl;
	cout << stone.first << stone.second << endl;
}