#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

vector<double> v;

int main(void)
{
	int t, num, ans;
	double hap;
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> num;
			v.push_back(num);
		}
		hap = accumulate(v.begin(), v.end(), 0);
		hap /= 10;
		ans = round(hap);
		v.clear();
		printf("#%d %d\n", a+1, ans);
	}
}