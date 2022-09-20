#include <iostream>
#define MAX 80001
using namespace std;

pair<int, int> now;
int w, h, p, q, t;
int x_rout[MAX];
int y_rout[MAX];
int main(void)
{
	int x_move, y_move;

	cin >> w >> h;
	cin >> p >> q;
	cin >> t;
	now.first = p;
	now.second = q;
	if (p == 0)
		x_move = -1;
	else
		x_move = 1;
	if (q == 0)
		y_move = -1;
	else
		y_move = 1;
	for (int i = 0; i < 2 * w; i++)
	{
		if (now.first == 0 || now.first == w)
			x_move *= -1;
		now.first += x_move;
		x_rout[(i + 1) % (2 * w)] = now.first;
	}
	for (int i = 0; i < 2 * h; i++)
	{
		if (now.second == 0 || now.second == h)
			y_move *= -1;
		now.second += y_move;
		y_rout[(i + 1) % (2*h)] = now.second;
	}
	cout << x_rout[t % (2*w)] << ' ' << y_rout[t % (2*h)] << '\n';
}