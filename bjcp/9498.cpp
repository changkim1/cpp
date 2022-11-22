#include <iostream>

using namespace std;

int main(void)
{
	int inp;
	char score;
	cin >> inp;
	if (inp >= 90)
		score = 'A';
	else if (inp >= 80)
		score = 'B';
	else if (inp >= 70)
		score = 'C';
	else if (inp >= 60)
		score = 'D';
	else
		score = 'F';
	cout << score << '\n';
}