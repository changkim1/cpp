#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, hap, max_ = -4001, min_ = 4001, max_cnt;
int cnt[8005];
int num[500000];

bool	compare(int a, int b)
{
	return (a < b);
}

int main(void)
{
	double a;
	int b, c, d, inp, check = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		cnt[inp+4000]++;
		num[i] = inp;
		hap += inp;
		if (inp > max_)
			max_ = inp;
		if (inp < min_)
			min_ = inp;
	}
	sort(num, num+n, compare);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
	a = round(hap / n);
	b = num[n / 2];
	printf("%d %d\n", num[n/`2], hap);
	for (int i = 0; i < max_ + 4000; i++)
	{
		if (cnt[i] == 0)
			continue ;
		if (max_cnt < cnt[i])
			max_cnt = cnt[i];
	}
	for (int i = 0; i < max_ + 4000; i++)
	{
		if (cnt[i] == max_cnt)
		{
			if (check == 1)
			{
				c = i - 4000;
				break ;
			}
			else
				check = 1;
		}
	}
	d = max_ - min_;
	printf("a %d\nb %d\nc %d\nd %d\n", a, b, c, d);
}