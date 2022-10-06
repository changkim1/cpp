#include <iostream>

using namespace std;

int n, cnt, idx;
int inp[11];
int line[11];

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inp[i];	
	}
	for (int i = 0; i < n; i++)
	{
		cnt = inp[i];
		idx = 0;
		if (cnt == 0)
		{
			while (line[idx] != 0)
				idx++;
		}
		while (cnt > 0)
		{
			while (line[idx] != 0)
			{
				idx++;
			}
			idx++;
			cnt--;
		}
		while (line[idx] != 0)
		{
			idx++;
		}
		line[idx] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << line[i] << ' ';
	}
	printf("\n");
}