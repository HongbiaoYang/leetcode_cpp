#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	
	if (s.length() <= 1) {
		return s.length();
	}


	int start, end, max;
	start = 0;
	end = start + 1;
	max = 0;
	std::size_t  pos;


	while (end != s.length()) {
		pos = s.substr(start, end - start).find(s[end]);
		if (pos == string::npos) {
			end ++;
			if (end - start > max) {	
				max = end - start;
			}
		} else {
			start = start + pos + 1;
		}	

	}	

	return max;
	
  }	
	
};

int main(int argc, char** argv)
{
	cout<<"length of longest substring"<<"\n";
	char input[128] = {0};	
	if (argc < 2) {
		strcpy(input, "a ");
	}
	else {
		strcpy(input, argv[1]);
	}


	Solution sln;
	int rs = sln.lengthOfLongestSubstring(input);

	cout<<"\nres="<<rs<<"\n";
	return 0;
	
}


