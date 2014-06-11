#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

using std::cout;
using std::vector;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
 	
	vector<vector<int> > pas;

        if (numRows <= 0) {
            return pas;
        } else if (numRows == 1) {
            vector<int> first(1,1);
            pas.push_back(first);
            return pas;
        } else {

            vector<int> first(1,1);
            pas.push_back(first);
            int i, j;

            for (i = 2; i <= numRows; i++) {
                vector<int> row (i, 1);
                for (j = 1; j < i - 1; j++) {
                    row[j] = pas[i-2][j] + pas[i-2][j-1];
                }
                pas.push_back(row);
            }

            return pas;
        }      
        
        
        
    }


    
};

int main(int argc, char** argv)
{
	cout<<"pascal"<<"\n";
	Solution sln;

	int num;

	if (argc < 2) {
		num = 3;
	} else {
		num = atoi(argv[1]);
	}

	vector<vector<int> > res = sln.generate(num);	

	

	
	return 0;
	
}


