#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#include <algorithm>
#include <vector>

using std::cout;
using std::vector;
using std::find;
using std::string;



class Solution {
public:
    bool isHappy(int n) {

        vector<int> nums;
            
        int temp = n;
        while (temp != 1) {
            temp = convert(temp);
            
             if (find(nums.begin(), nums.end(), temp) != nums.end())
                return false;
            
            nums.push_back(temp);
        }
        
        return true;
        
    }

    int convert(int n) {
        int temp = n;
        int sum = 0;
        
        while (temp!= 0) {
            sum += pow(temp % 10, 2);
            temp /= 10;
        }
        
        return sum;
    }
    
};

int main(int argc, char** argv)
{
	cout<<"happy number?"<<"\n";
	
	int n;
	if (argc < 2) {
		cout<<"Use default number 19\n";
		n = 19;
	} else {
		n = atoi(argv[1]);
	}
	
	Solution sln;
	
	string result;
	result = (sln.isHappy(n) == true)?" happy":" sad";
	
	cout<<n<<" is"<<result<<"\n";

	return 0;
	
}