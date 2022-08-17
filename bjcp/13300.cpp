#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001
#define BOY 1
#define GIRL 0

int n, k;
pair<int, int> stud[MAX]; // stud.first == sex , stud.second == grade
pair<int, int> room[MAX]; // room.first == boy, room.second == girl
int main(void)
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> stud[i].first >> stud[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		if (stud[i].first == BOY)
			room[stud[i].second].first++;
		else if (stud[i].first == GIRL)
			room[stud[i].second].second++;
	}
	int i = 1;
	int count = 0;
	while (i < 7)
	{
		if (room[i].first != 0)
		{
			count += (room[i].first / k);
			if (room[i].first % k != 0)
				count++;
		}
		if (room[i].second != 0)
		{
			count += (room[i].second / k);
			if (room[i].second % k != 0)
				count++;
		}
		i++;
	}
	cout << count << '\n';
}