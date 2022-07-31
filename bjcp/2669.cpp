#include <iostream>

using namespace std;

int main(void)
{
	int map[101][101] = { 0 };
	int count = 0;
	pair<int, int> start;
	pair<int, int> end;
	for (int a = 0; a < 4; a++)
	{
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;
		for (int i = start.first; i < end.first; i++)
		{
			for (int j = start.second; j < end.second; j++)
			{
				map[i][j] = 1;
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
	cout << count << endl;
}