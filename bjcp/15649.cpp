#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

priority_queue<string> pq;
string tmp;
map<int, int> map_;
int board[9];

int n, m;

int	is_okay(int line)
{
	for (int i = 0; i < m; i++)
	{
		if (i == line)
			continue ;
		if (board[i] == board[line])

	}
}

void	solve(int line)
{
	if (line == m)
		return ;
	for (int i = 1; i <= n; i++)
	{
		;
	}
}

int main(void)
{
	
}