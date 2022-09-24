#include <iostream>
#define MAX(a, b) a > b ? a : b
using namespace std;

int p, q, r, s, w, n;
int a_price, b_price;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> q >> r >> s >> w;
		a_price = w * p;
		if (w > r)
			b_price = ((w - r) * s) + q;
		else
			b_price = q;
		cout << "#" << i+1 << ' ' << min(a_price, b_price) << '\n';
	}
}