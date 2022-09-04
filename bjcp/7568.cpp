#include <iostream>
#define MAX 205

using namespace std;

pair<int, int> man[MAX];
int ranking[MAX];
int n;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> man[i].first >> man[i].second;
		ranking[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue ;
			if (man[i].first < man[j].first)
			{
				if (man[i].second < man[j].second)
					ranking[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ranking[i]);	
	}
	printf("\n");
}