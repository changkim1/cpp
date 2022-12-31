#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> v;
vector<int> nan;

void	solve(int idx, int start)
{
	if (v.size() == 7)
	{
		if (accumulate(v.begin(), v.end(), 0) == 100)
		{
			sort(v.begin(), v.end());
			for (int i = 0; i < 7; i++)
				printf("%d\n", v[i]);
			exit(0);
		}
		return ;
	}
	if (idx >= 9)
		return ;
	v.push_back(nan[idx]);
	solve(idx + 1, start);
	v.pop_back();
	solve(idx + 1, start);
}

int main(void)
{
	int num;
	for (int i = 0; i < 9; i++)
	{
		cin >> num;
		nan.push_back(num);
	}
	for (int i = 0; i < 3; i++)
	{
		solve(i, i);
	}
}