#include <iostream>

using namespace std;

int main(void)
{
	int c, r, k, count;
	int coor[2] = {1, 0};

	cin >> c >> r >> k;
	if (c * r < k)
	{
		printf("0\n");
		return (0);
	}
	else
	{
		int med;

		med = 1;
		count = 0;
		while (1)
		{
			for (int i = 0; i < r; i++)
			{
				count++;
				coor[1] += med;
				if (count == k)
				{
					cout << coor[0] << " " << coor[1] << endl;
					return 0;
				}
			}
			c--;
			for (int i = 0; i < c; i++)
			{
				count++;
				coor[0] += med;
				if (count == k)
				{
					cout << coor[0] << " " << coor[1] << endl;
					return 0;
				}
			}
			med *= -1;
			r--;
		}
	}
	return (0);
}