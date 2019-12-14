#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

vector<string> addresses;
int s, n, m;

void help()
{
	cout << "Wrong argument" << endl;
	cout << "cache_simulator -s <S> -n <N> -m <M> <input_file_name>" << endl;
	cout << "	-s <S> : the number of sets in a cache" << endl;
	cout << "	-n <N> : the number of blocks in a set" << endl;
	cout << "	-m <M> : the number of words in a block" << endl;
}

bool readFile(string file_name)
{
	ifstream input_file(file_name.data());
	if(input_file.is_open()) {
		string address;
		while(getline(input_file, address)) {
			addresses.push_back(address);
		}
		input_file.close();
		return true;
	}
	else return false;
}

int main(int argc, char *argv[])
{
	if (argc != 8) {
		help();
		return 1;
	}

	string input_file_name;
	for (int i = 1; i < argc; i += 2) {
		if (i == 7) {
			input_file_name = string(argv[i]);
			break;
		}
		string opt(argv[i]);
		if (opt == "-s") {
			s = atoi(argv[i + 1]);
		}
		else if (opt == "-n") {
			n = atoi(argv[i + 1]);
		}
		else if (opt == "-m") {
			m = atoi(argv[i + 1]);
		}
		else {
			help();
			return 2;
		}
	}
	
	if(!readFile(input_file_name)) {
		cout << "Input File Error" << endl;
		return 3;
	}
	
	
	return 0;
}
