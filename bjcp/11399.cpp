#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int n;
int p[MAX];
int ans;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		p[i] += p[i - 1];
	for (int i = 0; i < n; i++)
		ans += p[i];
	cout << ans << endl;
}