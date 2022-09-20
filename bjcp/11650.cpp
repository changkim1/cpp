#include <iostream>
#include <algorithm>
#define MAX 100001
#define endl '\n'

using namespace std;

int n;
pair<int, int> coo[MAX];

int	compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return (a.second < b.second);
	return (a.first < b.first);
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> coo[i].first >> coo[i].second;
	sort(coo, coo + n, compare);
	for (int i = 0; i < n; i++)
		cout << coo[i].first << ' ' << coo[i].second << endl;
}