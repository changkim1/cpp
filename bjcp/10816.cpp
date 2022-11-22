#include <iostream>
#include <algorithm>
#include <map>
#define MAX 500001

using namespace std;

int n, m;
int num[20000005];

map<int, int> map_;

int main(void)
{
	cin.tie(NULL);
	int inp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;
		num[inp + 10000000]++;
	}
	cin >> m;
	for (int j = 0; j < m; j++)
	{
		cin >> inp;
		cout << num[inp + 10000000] << ' ';
	}
}