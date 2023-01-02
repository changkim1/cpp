#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cout << v[n / 2] << '\n';
}