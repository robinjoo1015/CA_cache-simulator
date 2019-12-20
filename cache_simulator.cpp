#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <bitset>
using namespace std;

vector<string> addresses;
int s, n, m;

void help()
{
	cout << "Wrong argument" << endl;
	cout << "cache_simulator -s <S> -n <N> -m <M> <input_file_name>" << endl;
	cout << "	-s <S> : the number of sets in a cache (power of 2)" << endl;
	cout << "	-n <N> : the number of blocks in a set (power of 2)" << endl;
	cout << "	-m <M> : the number of words in a block (power of 2)" << endl;
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
	
	if(!s%2||!n%2||!m%2) {
		help();
		return 3;
	}
	
	if(!readFile(input_file_name)) {
		cout << "Input File Error" << endl;
		return 4;
	}
	
	for(int i = 0; i < addresses.size(); i++) {
		unsigned int ca = strtoul(addresses[i].c_str(), NULL, 0);
		bitset<32> x(ca);
		cout << addresses[i] << " : " << ca << " : " << x << endl;
	}
	
	return 0;
}
