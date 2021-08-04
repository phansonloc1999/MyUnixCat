#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		ifstream inStream(argv[1], ios::in);
		
		if (inStream.is_open())
		{
			string line;
			while (!inStream.eof())
			{
				getline(inStream, line, '\n');
				cout << line << endl;
			}
		}
		else cout << "File not found!" << endl;
	}
	else {
		cout << "Usage: mycat [PATH TO TARGET FILE]" << endl;
	}
	return 0;
}