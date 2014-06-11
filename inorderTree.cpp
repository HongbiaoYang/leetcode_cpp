#include <iostream>
#include <cstring>
#include <vector>

using std::cout;
using std::vector;

// Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

int main(int argc, char** argv)
{
	cout<<"inorder traverse"<<"\n";


	return 0;
	
}

class Solution {
public:
      vector<int> inorderTraversal(TreeNode *root) {
	vector<int> result, left, right;

	if (root == NULL) {
		return result;
	}

	left = inorderTraversal(root->left);	
	right= inorderTraversal(root->right);
	
	if ( !left.empty()) {	
		result.insert(result.end(), left.begin(), left.end());
	}

	result.insert(result.end(), root->val);
	
	if ( !right.empty()) {
		result.insert(result.end(), right.begin(), right.end());
	}


	return result;
		
    }
};
