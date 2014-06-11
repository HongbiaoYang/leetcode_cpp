#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	
	int len = s.length();
	if (len == 0) {
		return 0;
	}

	int count = 0;
	int i, j, max;	

	int* lmap;
	lmap = (int*)malloc(len*len*sizeof(int));
	memset(lmap, 0, len*len*sizeof(int));
	
	for (i = 0; i < len; i++) {
		lmap[i*len+i] = 1;
	}
	
	for (i = 0; i < len - 1; i ++) {
		for (j = i+1; j < len; j++) {

			if (s.substr(i, j - i).find(s[j],0) == string::npos) {
				lmap[i*len+j] = lmap[i*len+j-1]+1;
			} else	{
				lmap[i*len+j] = -1;
				break;
			}

		}
	}
	
	max = -1;
	for (i = 0; i < len*len; i++) {
		if (max < lmap[i]) {
			max = lmap[i];
		}
		
	}
	
	/*
	for (i = 0; i < len*len; i++) {
		if (i%len == 0) {		
			cout<<"\n";
		}
		cout<<lmap[i]<<"\t";
	}	
*/
	free(lmap);	

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


