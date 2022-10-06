#include <iostream>

using namespace std;

int n, s, p;
int score[51];

int main(void)
{
	int rank;
	cin >> n >> s >> p;
	if (n == 0)
	{
		cout << "1" << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}
	if (n < p)
	{
		for (int i = n; i < p; i++)
			score[i] = -1;
	}
	for (int i = 0; i < p; i++)
	{
		rank = i;
		if (s == score[i])
		{
			while (s == score[i])
				i++;
		}
		if (s >= score[i] && i < p)
		{
			cout << rank + 1 << '\n';
			return 0;
		}
	}
	cout << "-1" << endl;
}