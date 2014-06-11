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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	
	  ListNode *main, *sub, *head, *tmp, *tmp2;
        
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        
        if (l1->val <= l2->val) {
                main = l1;
                sub = l2;
        } else {
                main = l2;
                sub = l1;
        }

        head = main;

        while (sub != NULL) {
                if (sub->val >= main->val) {
                        if (main->next == NULL) {
                                main->next = sub;
                                break;
                        } else if (sub->val >= main->next->val) {
                                main = main->next;
                                continue;
                        } else {
                                // insert sub into main
                                tmp = main->next;
                                main->next = sub;
                                tmp2 = sub->next;
                                sub->next = tmp;
                                main = main->next;
                                sub = tmp2;
                        }


                }

        }

        return head;


    }
       
};

int main(int argc, char** argv)
{
	cout<<"Merge two lists"<<"\n";
	ListNode* test1 = new ListNode(-10);
	ListNode* test2 = new ListNode(-5);

	ListNode *n2, *n3, *n4, *n5, *n6, *n7;
	ListNode *m2, *m3, *m4, *m5, *m6;


	n2 = new ListNode(-9);
	n3 = new ListNode(-6);
	n4 = new ListNode(-4);
	n5 = new ListNode(1);
	n6 = new ListNode(9);
	n7 = new ListNode(9);

	m2 = new ListNode(-3);
	m3 = new ListNode(0);
	m4 = new ListNode(7);
	m5 = new ListNode(8);
	m6 = new ListNode(8);

	test1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=n7;
	n7->next=NULL;
	
	test2->next = m2;
	m2->next=m3;
	m3->next=m4;
	m4->next=m5;
	m5->next=m6;
	m6->next=NULL;

	Solution sln;
	
	ListNode* res = sln.mergeTwoLists(test1, test2);
	
	while (res != NULL) {
		cout<<"->"<<res->val<<"";
		res = res->next;
	}
	cout<<"\n";


	return 0;
	
}

