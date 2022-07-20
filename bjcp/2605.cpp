#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	vector<int> stud;
	vector<int> count;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		stud.push_back(i + 1);	
	}
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		count.push_back(tmp);
	}
	for (int i = 1; i < n; i++)
	{
		stud.insert(stud.begin() + i - count[i], stud[i]);
		stud.erase(stud.begin() + i + 1);
	}
	for (int i = 0; i < n; i++)
	{
		cout << stud[i] << ' ';
	}
}