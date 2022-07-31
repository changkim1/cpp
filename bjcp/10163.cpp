#include <iostream>
using namespace std;

#define MAX 101
pair<pair<int, int>, pair<int, int>> conf[MAX];
int map[1001][1001];
int n;
int res[MAX];

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> conf[i].first.first;
		cin >> conf[i].first.second;
		cin >> conf[i].second.first;
		cin >> conf[i].second.second;
		for (int j = conf[i].first.first; j < conf[i].first.first + conf[i].second.first; j++)
		{
			for (int k = conf[i].first.second; k < conf[i].first.second + conf[i].second.second; k++)
			{
				map[j][k] = i;
			}
		}
	}
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 1001; j++)
		{
			res[map[i][j]]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << res[i] << '\n';
	}
}