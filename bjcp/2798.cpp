#include <iostream>

using namespace std;

int main(void)
{
	int	n;
	int	m;
	int	card[101];
	int	result;
	int	hap;

	result = 0;
	hap = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				hap = card[i] + card[j] + card[k];
				if (hap <= m && hap > result)
					result = hap;
			}
		}
	}
	cout << result << endl;
}