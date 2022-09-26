#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n;
int inp;
string s_inp;
int broken[11];

int main(void)
{
	int ans, tmp;

	cin >> inp >> n;
	s_inp = to_string(inp);
	for (int i = 0; i < n; i++)
	{
		cin >> 	tmp;
		broken[tmp] = 1;
	}
	ans = abs(n - 100);
	
}