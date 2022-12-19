#include <iostream>

using namespace std;

int x, y;
int p1, p2;

int main(void)
{
	int nx, ny;
	cin >> x >> y >> p1 >> p2;
	int cnt = 0;
	nx = p1;
	ny = p2;
	while (cnt < 100)
	{
		if (nx == ny)
		{
			cout << nx << '\n';
			break ;
		}
		if (nx > ny)
			ny += y;
		else
			nx += x;
		cnt++;
	}
	if (nx != ny)
		cout << "-1" << '\n';
}