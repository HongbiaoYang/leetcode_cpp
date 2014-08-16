#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::vector;
using std::string;


//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int cnt = tokens.size();
       
        if (cnt <= 1) {
            return atoi(tokens[0].c_str());
        }
            
        
        int i;
        vector<int> stack;
        
        for (i = 0; i < cnt; i++) {
            
            if (IsOp(tokens[i]))
            {
                int a2 = stack.back();
                stack.pop_back();
                
                int a1 = stack.back();
                stack.pop_back();
                
                stack.push_back(ValueCalc(a1, a2, tokens[i]));
            }
            else
            {
                stack.push_back(atoi(tokens[i].c_str()));
            }
        }
        
        return stack.back();
            
    }
    
private:
    bool IsOp(string str)
    {
        if (str == "+" || str == "-" ||
            str == "/" || str == "*") {
            return true;
            }
        return false;
    }
    
    int ValueCalc(int a1, int a2, string op)
    {
        if (op == "+") {
            return a1+a2;
        } else if (op == "-") {
            return a1 - a2;
        } else if (op == "*") {
            return a1*a2;
        } else if (op == "/") {
            return a1 / a2;
        } else 
        {
            cout<<"Error:"<<op<<std::endl;
            return -0;
        }        
            
        
    }
    
};

int main(int argc, char** argv)
{
	cout<<"Evaluate Reverse Polish Notation"<<"\n";
  vector<string>  token;
  token.push_back("4");  
  token.push_back("13");
  token.push_back("5");
  token.push_back("/");
  token.push_back("+");
  
  Solution sln;
  
  int res = sln.evalRPN(token);
  cout<<"res="<<res<<std::endl;
  


	return 0;
	
}

