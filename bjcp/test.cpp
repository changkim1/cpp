#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

stack<int> stk;
int main()
{
	stk.push(1);
	cout << stk.top();
	stk.pop();
}