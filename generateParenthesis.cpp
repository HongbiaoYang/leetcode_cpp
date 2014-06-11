#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
 	vector<string> p;
	int i;

  	if (n <= 0) {
		return p;
	} else if (n == 1) {
		p.push_back("()");
		return p;
	} else {
		p = generateParenthesis(n-1);
		for (vector<string>::iterator it = p.begin() ; it != p.end(); ++it ) {
			string ss = *it;
			cout<<"ss="<<ss<<endl;


		}
		cout<<endl;
		
		return p;
		
		

	}

	return p;       
    }
};

int main(int argc, char** argv)
{
	cout<<"generate paranthesis"<<"\n";
	Solution sln;
	
	int n = 3;
	if (argc == 2) {			
		n = atoi(argv[1]);
	} 


	vector<string> rs = sln.generateParenthesis(n);
	

	for (string s : rs) {
		cout<<s<<endl;
	}
	
	return 0;
	
}


