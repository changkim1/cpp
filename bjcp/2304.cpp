#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int n;
pair<int, int> max_hi;
pair<int, int> wei;
int pil[MAX];
int roof[MAX];

int main(void)
{
	int cur_max_hi;
	pair<int, int> tmp;
	int ans;

	wei.first = MAX;
	wei.second = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp.first >> tmp.second;
		if (max_hi.second < tmp.second)
		{
			max_hi.first = tmp.first;
			max_hi.second = tmp.second;
		}
		if (tmp.first < wei.first)
			wei.first = tmp.first;
		else if (tmp.first > wei.second)
			wei.second = tmp.first;
		pil[tmp.first] = tmp.second;
	}
	if (n == 1)
	{
		cout << pil[wei.first] << endl;
		return (0);
	}
	cur_max_hi = pil[wei.first];
	for (int i = wei.first; i < max_hi.first; i++)
	{
		if (pil[i] > cur_max_hi)
			cur_max_hi = pil[i];
		roof[i] = cur_max_hi;
	}
	roof[max_hi.first] = max_hi.second;
	cur_max_hi = pil[wei.second];
	for (int i = wei.second; i > max_hi.first; i--)
	{
		if (pil[i] > cur_max_hi)
			cur_max_hi = pil[i];
		roof[i] = cur_max_hi;
	}
	ans = 0;
	for (int i = wei.first; i <= wei.second; i++)
		ans += roof[i];
	cout << ans << endl;
}