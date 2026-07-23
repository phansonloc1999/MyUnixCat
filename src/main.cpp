#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/stat.h>

using namespace std;

struct stat info;

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		string line;
		while (true)
		{
			getline(cin, line);
			cout << line;
			if (cin.eof())
				return 0;
			else
				cout << endl;
		}
	}

	if (argc == 2 && strcmp(argv[1], "-h") == 0)
	{
		cout << "Usage: mycat [IN FILE PATH]" << endl;
		cout << "Usage: mycat > [OUT FILE PATH]" << endl;
		cout << "Usage: mycat [IN FILE PATH] [OUT FILE PATH]" << endl;
		return 0;
	}

	string inFilePath = argv[1];

	stat(argv[1], &info);
	if (info.st_mode & S_IFDIR)
	{
		cout << "mycat: " + inFilePath + ": is a Directory" << endl;
		return 0;
	}

	ifstream inStream(argv[1], ios::in);
	if (!inStream)
	{
		cout << "mycat: " + inFilePath + ": No such file" << endl;
		return 0;
	}

	char line[256];
	ofstream outStream(argv[2], ios::out | ios::trunc);
	while (!inStream.eof())
	{
		inStream.getline(line, 256, '\n');
		cout << line;
		outStream << line;
		if (!inStream.eof())
		{
			cout << endl;
			outStream << endl;
		}
	}
	return 0;
}
