#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

int n;
queue<int> q;

int main(void)
{
	int tmp;

	cin >> n;
	for (int i = 0; i < n; i++)
		q.push(i + 1);
	while (q.size() != 1)
	{
		q.pop();
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << q.front() << endl;
}