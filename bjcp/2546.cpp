#include <iostream>
#include <cstring>
using namespace std;

int c[200001];
double c_iq, e_iq;
int n, m;

int main(void)
{
	int cnt;
	double t, hap, inp;
	char blank[2];
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		cnt = 0;
		memset(c, 0, sizeof(c));
		cin.getline(blank, 1);
		cin >> n >> m;
		hap = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> c[i];
			hap += c[i];
		}
		c_iq = hap / n;
		hap = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> inp;
			hap += inp;
		}
		e_iq = hap / m;
		for (int i = 0; i < n; i++)
		{
			if (c[i] < c_iq)
			{
				if (c[i] > e_iq)
					cnt++;
			}
		}
		cout << cnt << '\n';
	}
}