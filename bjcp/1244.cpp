#include <iostream>
#define MAX 101

#define ON 1
#define OFF 0
#define BOY 1
#define GIRL 2

using namespace std;

int swch, stud;
int on_off[MAX];

pair<int, int> student;


void	do_boy(int number)
{
	for (int i = number; i <= swch; i += number)
	{
		if (on_off[i] == ON)
			on_off[i] = OFF;
		else
			on_off[i] = ON;
	}
}

void	do_girl(int number)
{
	int left, right;

	left = number, right = number;
	while (left > 0 && right <= swch)
	{
		if (on_off[left] == on_off[right])
		{
			if (on_off[left] == ON)
			{
				on_off[left] = OFF;
				on_off[right] = OFF;
			}
			else
			{
				on_off[left] = ON;
				on_off[right] = ON;
			}
			left--;
			right++;
		}
		else
			break ;
	}
}

int main(void)
{
	cin >> swch;
	for (int i = 1; i <= swch; i++)
	{
		cin >> on_off[i];
	}
	cin >> stud;
	for (int i = 0; i < stud; i++)
	{
		cin >> student.first >> student.second;
		if (student.first == BOY)
			do_boy(student.second);
		else
			do_girl(student.second);
	}
	for (int i = 1; i <= swch; i++)
	{
		cout << on_off[i];
		if (i % 20 == 0)
			cout << '\n';
		else
			cout << ' ';
	}
}