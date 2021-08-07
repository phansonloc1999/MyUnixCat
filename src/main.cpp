#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

struct stat info;

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

	string inFilePath = argv[1];

	stat(argv[1], &info);
	if (info.st_mode & S_IFDIR)
	{
		
		cout << "Mycat: " + inFilePath + ": is a Directory" << endl;
		return 0;
	}
	

	ifstream inStream(argv[1], ios::in);
	if (!inStream)
	{
		cout << "Mycat: " + inFilePath + ": No such file" << endl;
		return 0;
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