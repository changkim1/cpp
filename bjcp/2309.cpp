#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int num[10];

int main(void)
{
	int tmp = 0;
	for (int i = 0; i < 9; i++)
		cin >> num[i];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			tmp = 0;
			if (j == i)
				continue ;
			for (int k = 0; k < 9; k++)
			{
				if (k == i || k == j)
					continue ;
				tmp += num[k];
				pq.push(num[k]);
			}
			if (tmp == 100)
			{
				while (!pq.empty())
				{
					cout << pq.top() << endl;
					pq.pop();
				}
				return 0;
			}
			while (!pq.empty())
				pq.pop();
		}
	}
}