#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main()
{
	int t, num;
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> num;
			pq.push(num);
		}
		printf("#%d %d\n", a + 1, pq.top());
		while (!pq.empty())
			pq.pop();
	}
}