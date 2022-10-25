#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <deque>
using namespace std;

deque<int> dq;

int main()
{
	int i;
	string tmp;
	i = 100;
	tmp = to_string(i);
	int idx;
	idx = tmp[0] - '0';
	int num[2];
	num[idx] = 100;
	printf("%d\n", num[1]);
}