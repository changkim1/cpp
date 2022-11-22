#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef struct node
{
	int idx;
	int num;
}	node;

int a[51];
int b[51];

int n;

priority_queue<int, vector<int>, greater<int>> pq_a;
priority_queue<int> pq_b;

int main(void)
{
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		pq_a.push(a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		pq_b.push(b[i]);
	}
	for (int i = 0; i < n; i++)
	{
		ans += (pq_a.top() * pq_b.top());
		pq_a.pop();
		pq_b.pop();
	}
	cout << ans << '\n';
}