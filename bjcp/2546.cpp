#include <iostream>
#include <cmath>

using namespace std;

double c_iq, e_iq;
int n, m;

int main(void)
{
	double t, hap, inp;
	char blank[2];
	cin >> t;
	for (int a = 0; a < t; a++)
	{
		cin.getline(blank, 1);
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> inp;
			hap += inp;
		}
		c_iq = hap / n;
		hap = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> inp;
			hap += inp;	
		}
		e_iq = hap / m;
	}
}