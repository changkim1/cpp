#include <iostream>
using namespace std;

int call, count, call_count;
int map[5][5];
int call_map[25];

void	wid_check(void)
{
	int check = 0;

	for (int i = 0; i < 5; i++)
	{
		check = 0;
		for (int j = 0; j < 5; j++)
		{
			if (map[i][j] == 0)
				continue ;
			else
			{
				check = 1;
				break ;
			}
		}
		if (check == 0)
			count++;
	}
}

void hi_check(void)
{
	int check = 0;

	for (int i = 0; i < 5; i++)
	{
		check = 0;
		for (int j = 0; j < 5; j++)
		{
			if (map[j][i] == 0)
				continue ;
			else
			{
				check = 1;
				break ;
			}
		}
		if (check == 0)
			count++;
	}
}

void	dig_check(void)
{
	int i;
	int check = 0;

	if (map[2][2] != 0)
		return ;
	for (int i = 0; i < 5; i++)
	{
		if (map[i][i] == 0)
			continue ;
		else
		{
			check = 1;
			break ;
		}
	}
	if (check == 0)
		count++;
	check = 0;
	for (int i = 0; i < 5; i++)
	{
		if (map[4 - i][i] == 0)
			continue ;
		else
		{
			check = 1;
			break ;
		}
	}
	if (check == 0)
		count++;
}

int	check_bingo(void)
{
	count = 0;
	wid_check();
	hi_check();
	dig_check();
	return (count);
}

void	check_call(int number)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (map[i][j] == number)
			{
				map[i][j] = 0;
				return ;
			}
		}
	}
}

int main(void)
{
	int bingo_count;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 25; i++)
		cin >> call_map[i];
	for (int i = 0; i < 25; i++)
	{
		call_count++;
		check_call(call_map[i]);
		bingo_count = check_bingo();
		if (bingo_count >= 3)
		{
			cout << call_count;
			break ;
		}
	}
}