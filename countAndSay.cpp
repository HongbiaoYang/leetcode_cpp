#include <iostream>
#include <cstring>
#include <cstdlib>

using  std::cout;
using  std::string;

class Solution {
public:
    string countAndSay(int n) {

	string s = "1";
	int i;

	for (i = 1; i < n; i++) {
		s = countAndSayString(s);
	}

	return s;

  }

    string countAndSayString(string s) {
	char c = s.front();
	int i = 0;

	while(c == s[i]) {
		if (i >= s.length()) {
			break;
		}
		i++;
	}
	
	if (i == s.length()) {
		return std::to_string(i) + c;
	}else {
		return std::to_string(i) + c + countAndSayString(s.substr(i));
	}
	

  }

};

int main(int argc, char** argv)
{
	cout<<"count and say"<<"\n";
	int input;
	if (argc < 2) {
		input = 1213;
	}
	else {
		input = atoi(argv[1]);
	}


	Solution sln;
	string rs = sln.countAndSay(input);

	cout<<"res="<<rs<<"\n";
	return 0;
	
}


