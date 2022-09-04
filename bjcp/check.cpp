#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int main(void)
{
	ifstream input;
	ofstream enter;
	char tmp[256];

	input.open("input.txt");
	enter.open("enter.txt");
	if (input.is_open())
	{
		while (!input.eof())
		{
			input.getline(tmp, 256);
			while (strcmp(tmp, ""))
			{
				enter << tmp << endl;
				input.getline(tmp, 256);
			}
			system("echo -en '\033[32myour   : '");
			system("< enter.txt ./a.out");
			system("echo -en '\033[32manswer : '");
			system("cat answer.txt");
			system("diff -w <(< enter.txt ./a.out | awk '$1=$1') answer.txt");
		}
	}
	// input.close();
	enter.close();
}
