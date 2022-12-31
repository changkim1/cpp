#include <iostream>
#include <cstring>

using namespace std;

int num[1000];

int n, max_;

int    solve(int second)
{
    int tmp, i = 2;
    num[1] = second;
    tmp = n - second;
    while (tmp >= 0)
    {
        num[i] = tmp;
        i++;
        tmp = num[i-2] - num[i -1];
    }
    return (i);
}

int main(void)
{
    int tmp = 0, len = 0, idx = 0;
    cin >> n;
    for (int a = n/2; a <= n; a++)
    {
        memset(num, 0, sizeof(num));
        num[0] = n; 
        len = solve(a);
        if (len > max_)
        {
            max_ = len;
            idx = a;
        }
    }
    max_ = solve(idx);
    printf("%d\n", max_);
    for (int i = 0; i < max_; i++)
        printf("%d ", num[i]);
    printf("\n");
}
