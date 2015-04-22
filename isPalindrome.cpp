#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <math.h>

using std::cout;



class Solution {
public:
    bool isPalindrome (int x) {
		
	    if (x < 0)
		        return false;
			else if (x < 10)
				return true;
			
			int n, i;
			n = log10(x);
			
			for (i = 0; i < n / 2 + 1; i++) {
				if (getDigit(x, i) != getDigit(x, n-i))
					return false;
			}
			
			return true;			  
    }
    
    int getDigit(int x, int i) {
    	
    	int x1 = x / pow(10, i);
    	return x1 % 10;
    }
    
};

int main(int argc, char** argv)
{
	cout<<"isPalindrome"<<"\n";
	Solution sln;
 	int n;
 
  if (argc < 2) {
  	n = 191;
  } else {
  	n = atoi(argv[1]);
  }
  
  
 
  
	bool rs = sln.isPalindrome (n);
	
	cout<<"\nrs="<<rs<<"\n";

	
	return 0;
	
}


