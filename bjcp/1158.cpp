#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<pair<int, int>> v;
deque<int> dq;
int n, k;

int main(void)
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		v.push_back({i + 1, 0});
	int cnt = 0;
	int i = 0;
	while (dq.size() != n)
	{
		if (i >= n)
			i = 0;
		if (v[i].second == 1)
		{
			i++;
			continue ;
		}
		else
		{
			cnt++;
			if (cnt == k)
			{
				dq.push_back(v[i].first);
				v[i].second = 1;
				cnt = 0;
			}
			i++;
		}
	}
	printf("<");
	while (!dq.empty())
	{
		printf("%d", dq.front());
		dq.pop_front();
		if (!dq.empty())
			printf(", ");
	}
	printf(">\n");
}