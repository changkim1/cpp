#include <iostream>
#include <map>

#define MAX 500001

using namespace std;

int n, m;
map<int, int> card;
int	ans[MAX];

int main(void)
{
	int tmp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		card.insert({tmp, i});
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (card.find(tmp) == card.end())
			ans[i] = 0;
		else
			ans[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << endl;
}