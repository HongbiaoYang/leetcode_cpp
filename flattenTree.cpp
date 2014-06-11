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
 
class Solution {
public:
    void flatten(TreeNode *root) {

        returnFlatten(root);
    }
    
    TreeNode* returnFlatten(TreeNode* root) {
        
        if (root->left == NULL && root->right == NULL) {
            return root;
        } else if (root->left == NULL && root->right != NULL) {
            TreeNode* right = returnFlatten(root->right);
            root->right = right;
            return root;
        } else if (root->left != NULL && root->right == NULL) {
            TreeNode* left = returnFlatten(root->left);
	   root->left = NULL; 
           root->right = left;
            return root;
        }
        else {
            TreeNode* left = returnFlatten(root->left);
            TreeNode* right = returnFlatten(root->right);
            root->right = left;
            appendTree(root, right);
	    root->left = NULL;
            return root;
        }
        
    }
    
    void appendTree(TreeNode* tree1, TreeNode* tree2) {
        if (tree1->right == NULL) {
            tree1->right = tree2;
        } else {
            appendTree(tree1->right, tree2);
        }
        
    }

};


int main(int argc, char** argv)
{
	cout<<"flatten tree"<<"\n";

	TreeNode* root;
	root = new TreeNode(1);
	TreeNode *n2, *n3, *n4, *n5, *n6;
	n2 = new TreeNode(2);

	/*
	n3 = new TreeNode(3);
	n4 = new TreeNode(4);
	n5 = new TreeNode(5);
	n6 = new TreeNode(6);

	root->left = n2;
	root->right = n5;
	n2->left = n3;
	n2->right = n4;
	n5->right = n6;
	*/

	root->right = n2;

	Solution sln;

	sln.flatten(root);	

	
	return 0;
	
}


