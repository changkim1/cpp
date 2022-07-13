#include <iostream>
using namespace std;

int main(void)
{
	int h, m, t;

	cin >> h >> m >> t;
	cout << (((m + t) / 60) + h) % 24 << ' ';
	cout << (m + t) % 60;
}