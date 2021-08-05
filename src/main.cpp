#include <iostream>
#include <fstream>
#include <cstring>
#include <readline/readline.h>

using namespace std;

char **completion(const char *, int, int);
char *generator(const char *, int);
char *options[] = {
	"Arthur Dent",
	"Ford Prefect",
	"Tricia McMillan",
	"Zaphod Beeblebrox",
	NULL};

int main(int argc, char const *argv[])
{
	rl_attempted_completion_function = completion;

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
	ofstream outStream(argv[2], ios::out | ios::trunc);
	string line;
	while (inStream.is_open() && !inStream.eof())
	{
		getline(inStream, line, '\n');
		cout << line << endl;

		if (outStream)
		{
			outStream << line << endl;
		}
	}

	if (!inStream)
	{
		string inFilePath = argv[1];
		cout << inFilePath + ": No such file" << endl;
	}

	return 0;
}

char **completion(const char *text, int start, int end)
{
	rl_attempted_completion_over = 1;
	return rl_completion_matches(text, generator);
}

char *generator(const char *text, int state)
{
	static int list_index, len;
	char *name;

	if (!state)
	{
		list_index = 0;
		len = strlen(text);
	}

	while ((name = options[list_index++]))
	{
		if (strncmp(name, text, len) == 0)
		{
			return strdup(name);
		}
	}

	return NULL;
}