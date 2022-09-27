#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <deque>
using namespace std;

deque<int> dq;

int main()
{
	string test;
	cin >> test;
	if (test.compare("ok") == 1)
		cout << "OK\n";
	else
		cout << "NO\n";
}