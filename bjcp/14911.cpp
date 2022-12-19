#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int goal;

int main(void)
{
	int inp, cnt = 0;
	vector<int> v;
	while (scanf("%d", &inp) != EOF)
		v.push_back(inp);
	goal = v.back();
	v.pop_back();
	sort(v.begin(), v.end());
	map<pair<int, int>, int> vis;
	for (int i = 0; i < (int)v.size(); i++)
	{
		for (int j = i + 1; j < (int)v.size(); j++)
		{
			if (v[i] + v[j] == goal && vis.find({v[i], v[j]}) == vis.end())
			{
				cout << v[i] << ' ' << v[j] << '\n';
				cnt++;
				vis.insert({{v[i], v[j]}, 1});
			}
		}
	}
	cout << cnt << '\n';
}