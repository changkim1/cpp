#include <iostream>
using namespace std;

int main(void)
{
	char str[257];
	int count = 0;

	while (1)
	{
		fgets(str, 257, stdin);
		if (str[0] == '#')
			exit(0);
		count = 0;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == 'i' || str[i] == 'I')
				count++;
			else if (str[i] == 'a' || str[i] == 'A')
				count++;
			else if (str[i] == 'e' || str[i] == 'E')
				count++;
			else if (str[i] == 'o' || str[i] == 'O')
				count++;
			else if (str[i] == 'u' || str[i] == 'U')
				count++;
		}
		cout << count << '\n';
	}
}