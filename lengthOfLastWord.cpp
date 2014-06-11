#include <iostream>
#include <cstring>

using  std::cout;
using  std::string;

class Solution {
public:
    int lengthOfLastWord(const char *s) {

	  if (strlen(s) == 0) {
            return 0;
        }
        
        
        
        const char* begin;
        int endSpace = 0;
        
	begin = s + strlen(s) - 1;

        while (*begin == ' ') {
            endSpace ++;
            begin--;
        }
        
        begin = s + strlen(s) - 1 - endSpace;
        
        while (((*begin >= 'a' && *begin <= 'z') || (*begin >= 'A' && *begin <= 'Z')) && begin >= s) {
                    begin --;
                }
        
	int len = strlen(begin+1) - endSpace;
        
        return len > 0 ? len : 0;




  }
};

int main(int argc, char** argv)
{
	cout<<"length of last word"<<"\n";
	char input[128] = {0};	
	if (argc < 2) {
		strcpy(input, "a ");
	}
	else {
		strcpy(input, argv[1]);
	}


	Solution sln;
	int rs = sln.lengthOfLastWord(input);

	cout<<"res="<<rs<<"";
	return 0;
	
}


