#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int k;
	vector<pair<int, int>> v;

	cin >> k;
	int d, m, w = 0, h = 0;
	int wi, hi;
	for (int i = 0; i < 6; i++)
	{
		cin >> d >> m;
		if (d <= 2)
		{
			if (m > w)
			{
				w = m;
				wi = i;
			}
		}
		else
		{
			if (m > h)
			{
				h = m;
				hi = i;
			}
		}
		v.push_back({d, m});
	}
	int tmp = wi;
	if (wi + 1 == hi || hi == 0 && wi == 5)
		tmp = hi;
	int res;
	res = ((v[wi].second * v[hi].second) - (v[(tmp + 3) % 6].second * v[(tmp + 2) % 6].second)) * k;
	cout << res;
}