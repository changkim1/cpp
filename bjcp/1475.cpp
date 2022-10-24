#include <iostream>
#include <string>

using namespace std;

int num[11];

int main(void)
{
	string inp;
	int six_size = 0, size = 0, idx = 0;
	cin >> inp;
	for (int i = 0; i < (int)inp.size(); i++)
	{
		int tmp = inp[i] - '0';
		num[tmp]++;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (i == 6 || i == 9)
			six_size += num[i];
		else if (num[i] > size)
		{
			size = num[i];
			idx = i;
		}
	}
	six_size = (six_size + 1) / 2;
	if (six_size > size)
		cout << six_size << endl;
	else
		cout << size << '\n';
}