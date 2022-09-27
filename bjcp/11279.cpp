#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;
int n, num;

int main(void)
{
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 0)
		{
			if (pq.empty())
			{
				cout << "0" << '\n';
				continue ;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else
			pq.push(num);
	}
}