#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{

		cout << "mycat: missing operands/operators" << endl;
		cout << "Try 'mycat -h' for more information." << endl;
		return 0;
	}

	if (strcmp(argv[1], "-h") == 0)
	{
		cout << "Usage: mycat [TARGET FILE PATH]" << endl;
		cout << "Usage: mycat > [OUT FILE PATH]" << endl;
		cout << "Usage: mycat [IN FILE PATH] > [OUT FILE PATH]" << endl;
		return 0;
	}

	ifstream inStream(argv[1], ios::in);
	ofstream outStream(argv[3], ios::out | ios::trunc);
	if (inStream)
	{
		string line;
		while (!inStream.eof())
		{
			getline(inStream, line, '\n');
			cout << line << endl;

			if (outStream)
			{
				outStream << line << endl;
			}
		}
	}
	else
		cout << "ERROR File doesn't exist" << endl;

	return 0;
}