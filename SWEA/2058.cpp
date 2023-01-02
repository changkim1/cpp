#include <iostream>

using namespace std;

int main()
{
	string n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n.size(); i++)
		ans += (n[i] - '0');
	cout << ans << '\n';
}