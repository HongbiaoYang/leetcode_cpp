#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <math.h>

using std::cout;
using std::vector;
using std::max;



class Solution {
public:
      int rob(vector<int>& nums) {
        
        
       int n = nums.size();
       if (n == 0)
        return 0;
       
       return max_with_edge(nums, n);
        
    }
    
    int max_with_edge(vector<int>& nums, int n) {
    	
    	
    	if (n == 1)
    		return nums.at(0);
    	else if (n == 2)
    		return nums.at(1);    	
    	
    	return max(max_with_edge(nums, n-1), max_with_edge(nums, n - 2) + nums.at(n - 1));
    	
    }

    

    
};

int main(int argc, char** argv)
{
	cout<<"rob"<<"\n";
	Solution sln;
 	
	
 	int value[] = {104,209,137,52,158,67,213,86,141,110,151,127,238,147,169,138,240,185,246,225,147,203,83,83,131,227,54,78,165,180,214,151,111,161,233,147,124,143};
 	std::vector<int> house (value, value + sizeof(value) / sizeof(int) ); 
 	 
  
	int rs = sln.rob (house);
	
	cout<<"\nrs="<<rs<<"\n";

	
	return 0;
	
}


