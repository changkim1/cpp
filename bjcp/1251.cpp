#include <iostream>
#include <queue>

using namespace std;

string inp;
string split[3];
string tmp;
priority_queue<string, vector<string>, greater<string>> pq;

string	swaping(int idx)
{
	char tmp;
	for (int i = 0; i < split[idx].size() / 2; i++)
	{
		tmp = split[idx][i];
		split[idx][i] = split[idx][split[idx].size() -1 - i];
		split[idx][split[idx].size() -1 - i] = tmp;
	}
	return split[idx];
}

int main(void)
{
	int i = 0;
	cin >> inp;
	for (int sep1 = 1; sep1 <= inp.size() - 2; sep1++)
	{
		for (int sep2 = sep1 + 1; sep2 <= inp.size() - 1; sep2++)
		{
			i = 0;
			tmp.clear();
			while (i < sep1)
			{
				split[0] += inp[i];
				i++;
			}
			while (i < sep2)
			{
				split[1] += inp[i];
				i++;
			}
			while (i < inp.size())
			{
				split[2] += inp[i];
				i++;
			}
			for (int idx = 0; idx < 3; idx++)
			{
				tmp += swaping(idx);
				split[idx].clear();
			}
			pq.push(tmp);
		}
	}
	cout << pq.top() << endl;
}