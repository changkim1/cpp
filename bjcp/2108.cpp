#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
using namespace std;


bool compare(int a, int b)
{
	return (a < b);
}

int main(void)
{
	int n;
	int bin[8001], bin_cnt = 0;
	int max_ = -4001, min_ = 4001;
	double hap = 0;
	int jung[500001];
	int inp, check = 0;
	double pyeong;
	int jungang, choibin, beom;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		bin[inp + 4000]++;
		jung[i] = inp;
		bin_cnt = MAX(bin[inp + 4000], bin_cnt);
		max_ = MAX(inp, max_);
		min_ = MIN(inp, min_);
		hap += inp;
	}
	sort(jung, jung + n, compare);
	pyeong = hap / n;
	jungang = jung[n / 2];
	beom = max_ - min_;
	for (int i = 0; i <= 8000; i++)
	{
		if (check == 1 && bin_cnt == bin[i])
		{
			choibin = i - 4000;
			break ;
		}
		if (check == 0 && bin_cnt == bin[i])
		{
			choibin = i - 4000;
			check = 1;
		}
	}
	pyeong = round(pyeong);
	int tmp = (int)pyeong;
	printf("%d\n%d\n%d\n%d\n", tmp, jungang, choibin, beom);
}