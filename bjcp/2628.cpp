#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int res;
vector<int> hi;
vector<int> wid;

int main(void)
{
	int n, m, cut, check, num;

	cin >> n >> m >> cut;
	for (int i = 0; i < cut; i++)
	{
		cin >> check >> num;
		if (check == 0)
			hi.push_back(num);
		else
			wid.push_back(num);
	}
	hi.insert(hi.begin(), 0);
	wid.insert(wid.begin(), 0);
	hi.insert(hi.end(), m);
	wid.insert(wid.end(), n);
	sort(hi.begin(), hi.end());
	sort(wid.begin(), wid.end());
	for (int i = 1; i < hi.size(); i++)
	{
		for (int j = 1; j < wid.size(); j++)
		{
			if (res < (hi[i] - hi[i - 1]) * (wid[j] - wid[j - 1]))
				res = (hi[i] - hi[i - 1]) * (wid[j] - wid[j - 1]);
		}
	}
	cout << res << endl;
}