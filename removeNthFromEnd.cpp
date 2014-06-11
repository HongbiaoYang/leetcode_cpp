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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len;
        ListNode* tmp;
        
        len = 0;
        tmp = head;
        while (tmp != NULL) {
            len++;
            tmp = tmp->next;
        }
        
        len = len  - n;
        tmp = head;
        
        if (len == 0) {
            head = head->next;    
            return head;
        }
        
        while (--len > 0) {
            tmp = tmp->next;
        }
        
        if (tmp->next != NULL) {
            tmp->next = tmp->next->next;
        }
        
        return head;
    }
};

int main(int argc, char** argv)
{
	cout<<"remove from end of list"<<"\n";
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
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=NULL;
	n7->next=NULL;
	
	Solution sln;
	
	ListNode* res = sln.removeNthFromEnd(test, 3);
	
	while (res != NULL) {
		cout<<"->"<<res->val<<"";
		res = res->next;
	}
	cout<<"\n";


	return 0;
	
}

