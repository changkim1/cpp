#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int n, num;
	int inp[1001];
	double ave, ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		int hap = 0, cnt = 0;
		ans = 0;
		for (int j = 0; j < num; j++)
		{
			cin >> inp[j];
			hap += inp[j];
		}
		ave = hap / num;
		for (int j = 0; j < num; j++)
		{
			if (inp[j] > ave)
				cnt++;
		}
		ans = ((double)cnt / (double)num) * 100;
		printf("%.3f%%\n", ans);
	}
}