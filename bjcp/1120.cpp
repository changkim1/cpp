#include <iostream>
#include <string>
using namespace std;

string a, b;

int main(void)
{
	int len, j = 0;
	cin >> a >> b;
	len = (int)b.size() - (int)a.size();
	int sub = 51, tmp = 0;
	while (len >= 0)
	{
		tmp = 0;
		for (int i = 0; i < (int)a.size(); i++)
		{
			if (a[i] != b[j + i])
				tmp++;
		}
		if (tmp < sub)
			sub = tmp;
		len--;
		j++;
	}
	cout << sub << '\n';
}