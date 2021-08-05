#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		if (strcmp(argv[1], "-h"))
		{
			cout << "Usage: mycat [TARGET FILE PATH]" << endl;
		}
		else
		{
			ifstream inStream(argv[1], ios::in);

			if (inStream)
			{
				string line;
				while (!inStream.eof())
				{
					getline(inStream, line, '\n');
					cout << line << endl;
				}
			}
			else
				cout << "File doesn't exist" << endl;
		}
	}
	else
	{
		cout << "Mycat: No arguments passed! Nothing to do" << endl;
	}
	return 0;
}