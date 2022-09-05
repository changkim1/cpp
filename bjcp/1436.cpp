#include <iostream>
#include <string>
using namespace std;

int n;

int main(void)
{
	int 	idx;
	int 	num;
	string	tmp;

	num = 1;
	idx = 0;
	cin >> n;
	while (idx != n)
	{
		tmp = to_string(num);
		if (tmp.find("666") != string::npos)
			idx++;
		num++;
	}
	cout << num - 1 << '\n';
}