#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		string line;
		while (true)
		{
			if (cin.eof())
				return 0;
			getline(cin, line, '\n');
			cout << line << endl;
		}
		return 0;
	}

	if (argc == 2 && strcmp(argv[1], "-h") == 0)
	{
		cout << "Usage: mycat [IN FILE PATH]" << endl;
		cout << "Usage: mycat > [OUT FILE PATH]" << endl;
		cout << "Usage: mycat > [OUT FILE PATH]" << endl;
		cout << "Usage: mycat [IN FILE PATH] [OUT FILE PATH]" << endl;
		return 0;
	}

	ifstream inStream(argv[1], ios::in);
	if (!inStream)
	{
		string inFilePath = argv[1];
		cout << inFilePath + ": No such file" << endl;
	}
	ofstream outStream(argv[2], ios::out | ios::trunc);

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
	return 0;
}