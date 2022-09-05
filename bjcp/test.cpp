#include <iostream>
#include <string>
#include <map>
using namespace std;

int arry[1000][1000];

int main()
{
	string tmp;
	map<string, int> test;
	string one = "one";
	string two = "two";
	string three = "three";
	test.insert({one, 1});
	test.insert({two, 2});
	test.insert({three, 3});
	cin >> tmp;
	cout << test[tmp];
}