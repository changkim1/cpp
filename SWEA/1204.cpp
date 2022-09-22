#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int n;
int score[105];
deque<int> ans;

int main(void)
{
	int num, test, max_score;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		memset(score, 0, sizeof(score));
		cin >> test;
		for (int j = 0; j < 1000; j++)
		{
			cin >> num;
			score[num]++;
		}
		max_score = 0;
		for (int i = 1; i < 100; i++)
		{
			if (score[max_score] <= score[i+1])
				max_score = i + 1;
		}
		ans.push_back(max_score);
	}
	for (int i = 0; i < (int)ans.size(); i++)
		printf("#%d %d\n", i+1, ans[i]);
}