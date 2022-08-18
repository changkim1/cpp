#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int n, k;

int	temp[MAX];
int	add[MAX];

int main(void)
{
	int	tmp;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> temp[i];
	for (int i = 0; i < k; i++)
		add[0] += temp[i];
	for (int i = 1; i < n - k + 1; i++)
	{
		add[i] = add[i - 1] - temp[i - 1] + temp[i + k - 1];
	}
	sort(add, add + n - k + 1);
	cout << add[n - k] << endl;
}