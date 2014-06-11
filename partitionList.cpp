#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using std::cout;
using std::vector;


//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        
	// empty list or one-node list
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *left, *right, *tmp, *leftHead, *rightHead, *leftTail;
        left = NULL;
        right = NULL;
	rightHead = NULL;
	leftHead = NULL;
	leftTail = NULL;
        
        tmp = head;
        
        while (tmp != NULL) {
            if (tmp->val < x) {
                if (left == NULL) {
                    left = new ListNode(tmp->val);
		    leftHead = left;
		    leftTail = left;
                } else {
			left->next = new ListNode(tmp->val);
			left = left->next;
			leftTail = left;
		}

            } else {
		if (right == NULL) {
			right = new ListNode(tmp->val);
			rightHead = right;
		} else {
			right->next = new ListNode(tmp->val);
			right = right->next;
		}
	    }
	tmp = tmp->next;
        }
	
	// empty in the left
	if (leftTail == NULL) {	
		return rightHead;
	}
	else {

		leftTail->next = rightHead;
        	return leftHead;		
	}
	
    }
       
};

int main(int argc, char** argv)
{
	cout<<"partition list"<<"\n";
	ListNode* test = new ListNode(1);
	ListNode *n1, *n2, *n3, *n4, *n5, *n6, *n7;
	n1 = new ListNode(1);
	n2 = new ListNode(1);
	n3 = new ListNode(3);
	n4 = new ListNode(2);
	n5 = new ListNode(5);
	n6 = new ListNode(2);
	n7 = new ListNode(5);

	test->next=n1;
	n1->next=NULL;
	//n2->next=n3;
	n2->next = NULL;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=NULL;
	n7->next=NULL;
	
	Solution sln;
	
	ListNode* res = sln.partition(test, 3);
	
	while (res != NULL) {
		cout<<"->"<<res->val<<"";
		res = res->next;
	}
	cout<<"\n";


	return 0;
	
}

