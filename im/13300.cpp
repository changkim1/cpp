#include <iostream>

using namespace std;

int n, k;
int boy[6];
int girl[6];

int main(void)
{
	int cnt = 0;
	int s, y;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s == 0)
		{
			cin >> y;
			girl[y-1]++;
		}
		else
		{
			cin >> y;
			boy[y-1]++;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		if (girl[i] % k == 0)
			cnt += girl[i] / k;
		else if (girl[i] % k != 0)
			cnt += ((girl[i] / k) + 1);
		if (boy[i] % k == 0)
			cnt += boy[i] / k;
		else if (boy[i] % k != 0)
			cnt += ((boy[i] / k) + 1);
	}
	cout << cnt << '\n';
}