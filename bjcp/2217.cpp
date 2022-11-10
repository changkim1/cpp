#include <iostream>
#include <algorithm>

using namespace std;

int rope[100001];
int n;

bool compare(int a, int b)
{
	return (a < b);
}

int main(void)
{
	int max_, i, rem, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> rope[i];
	}
	sort(rope, rope + n, compare);
	max_ = rope[n-1];
	i = 0;
	rem = n;
	int j;
	while (i < n)
	{
		tmp = rem * rope[i];
		if (tmp > max_)
			max_ = tmp;
		j = i;
		while (rope[j] == rope[i])
		{
			j++;
			rem--;
		}
		i = j;
	}
	cout << max_ << '\n';
}