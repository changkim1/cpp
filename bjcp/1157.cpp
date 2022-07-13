#include <iostream>
#include <string.h>
using namespace std;

char alp[27];
char res[1000002];

int main(void)
{
	int	ans = -1;
	int idx = 0;

	fgets(res, sizeof(res), stdin);
	for (int i = 0; i < strlen(res); i++)
	{
		if (isupper(res[i]))
		{
			alp[res[i] - 'A']++;
		}
		else if (islower(res[i]))
		{
			alp[res[i] - 'a']++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (ans < alp[i])
		{
			ans = alp[i];
			idx = i;
		}
		else if (ans == alp[i])
		{
			cout << "?";`
			return (0);
		}
	}
	cout << (char)(idx + 'A');
}`````