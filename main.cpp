#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <streambuf>
#include "color.h"
#include "parser.h"

using namespace std;
string getExtension(string filename);

/**************************\
 * Version: 1.1.0 Beta    *
 * Author: Evan Shimoniak *
\**************************/

int main(int argc, char* argv[]) {
	//If no file name entered
	if (argc <= 1) {
		return 1;
	}

	//Set up file reader
	ifstream fin(argv[1]);

	if (fin.is_open() && fin.good()) {
		stringstream buff;
		buff << fin.rdbuf();

		exec(buff.str());
	} else {
		setColor(RED, BLACK);
		cout << "Failed to open file\n";
		setColor(RED, DEFAULT);
		return 1;
	}

	system("pause");


	return 0;
}
