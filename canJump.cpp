#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

using std::cout;

class Solution {
public:
    bool canJump(int A[], int n) {

        if (n < 2) {
                // n = 0 or n = 1, trivial true
                return true;
        } else {
                int i, a, max, maxI;
                a = A[0];
                
                // can jump from the 1st step to the end
                if (a + 1 >= n) {
                    return true;
                }
                
                max = -1;
                maxI = 0;
            
                // greedy: find the best jump so far
                for (i = 1; i <= a; i++) {
                        if (i+A[i] >= max) {
                                max = i+A[i];
                                maxI = i;
                        }
                }
            
                // the best jump is stuck
                if (A[maxI] == 0) {
                        return false;
                }
                
                // move on to other best jumps
                return canJump(A+maxI, n-maxI);
        }


    }
};


int main(int argc, char** argv)
{
	cout<<"can jump"<<"\n";
	Solution sln;

	int n = 2;
	int A[] = {0,1};
	//int A[] = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
	//int n = 104;

	bool rs = sln.canJump(A, n);
	
	cout<<"rs="<<rs<<"\n";

	
	return 0;
	
}


