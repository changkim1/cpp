#include <iostream>

using namespace std;

int main(void)
{
	bool check[10] = { false };
	for (int i = 0; i < 10; i++)
		cout << check[i] << '\n';
	check[1] = true;
	for (int i = 0; i < 10; i++)
		cout << check[i] << '\n';
	fill_n(check, 10, false);
	for (int i = 0; i < 10; i++)
		cout << check[i] << '\n';
}