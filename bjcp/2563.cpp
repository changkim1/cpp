#include <iostream>

using namespace std;

int main(void)
{
	int n, count = 0;
	pair<int, int> paper;
	int map[101][101] = { 0 };
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> paper.first >> paper.second;
		for (int j = paper.first; j < paper.first + 10; j++)
		{
			for (int k = paper.second; k < paper.second + 10; k++)
			{
				map[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1)
				count++;
		}
	}
	cout << count;
}