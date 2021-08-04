#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		ifstream inStream(argv[1], ios::in);
		
		if (inStream.is_open())
		{
			char* line = new char;
			while (!inStream.eof())
			{
				inStream.getline(line, 1024);
				cout << line << endl;
			}
		}
	}
	return 0;
}