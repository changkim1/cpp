#include <iostream>
#include <queue>

using namespace std;

int num[101][101];
priority_queue<int> pq;

int main(void)
{
	int t, w, h, x, y;
	for (int a = 0; a < 10; a++)
	{
		cin >> t;
		for (int i = 0; i < 100; i++)
		{
			w = 0;
			for (int j = 0; j < 100; j++)
			{
				cin >> num[i][j];
				w += num[i][j];
			}
			pq.push(w);
		}
		for (int i = 0; i < 100; i++)
		{
			h = 0;
			for (int j = 0; j < 100; j++)
			{
				h += num[j][i];
			}
			pq.push(h);
		}
		x = 0;
		y = 0;
		for (int i = 0; i < 100; i++)
		{
			x += num[i][i];
			y += num[i][99-i];
		}
		pq.push(x);
		pq.push(y);
		cout << "#" << t << ' ' << pq.top() << '\n';
		while (!pq.empty())
			pq.pop();
	}
}