#include <iostream>
#include <stdlib.h>

#define MAX 51

using namespace std;

char map[MAX][MAX];
int n, m;

char	**make_answer_map(char c1)
{
	char	**tmp_map;
	char	c2;

	tmp_map = (char **)malloc(sizeof(char *) * 9);
	if (c1 == 'W')
		c2 = 'B';
	else
		c2 = 'W';
	for (int i = 0; i < 9; i++)
	{
		tmp_map[i] = (char *)malloc(9);
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
				tmp_map[i][j] = c1;
			else
				tmp_map[i][j] = c2;
		}
	}
	return (tmp_map);
}

int	solve(int i, int j)
{
	int 	res;
	int		tmp;
	int		c, d;
	char	**tmp_w;
	char	**tmp_b;

	c = i;
	tmp = 0;
	res = 0;
	tmp_w = make_answer_map('W');
	tmp_b = make_answer_map('B');
	for (int a = 0; a < 8; a++)
	{
		d = j;
		for (int b = 0; b < 8; b++)
		{
			if (map[c][d] != tmp_w[a][b])
				tmp++;
			d++;
		}
		c++;
	}
	c = i;
	for (int a = 0; a < 8; a++)
	{
		d = j;
		for (int b = 0; b < 8; b++)
		{
			if (map[c][d] != tmp_b[a][b])
				res++;
			d++;
		}
		c++;
	}
	if (res > tmp)
		res = tmp;
	return (res);
}

int main(void)
{
	int tmp;
	int res;

	res = MAX * MAX;
	tmp = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{
			tmp = solve(i, j);
			if (tmp < res)
				res = tmp;
		}
	}
	cout << res << '\n';
	return (0);
}