#include <iostream>

using namespace std;

int a, b, c, d;
int map[101][101];

int main(void)
{
    int mx = 0, my = 0;
    for (int z = 0; z < 4; z++)
    {
        cin >> a >> b >> c >> d;
        mx = max(c, mx);
        my = max(d, my);
        for (int i = b; i < d; i++)
        {
            for (int j = a; j < c; j++)
            {
                map[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i <= my; i++)
    {
        for (int j = 0; j <= mx; j++)
        {
            if (map[i][j] == 1)
                cnt++;
        }
    }
    cout << cnt << '\n';
}