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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int i, temp;
        i = 1;
        ListNode *start, *end;

        start = head;
        
        while (i++ <= m) {
            start = start->next;
        }
        
        end = start;
        
        while (i++ <= n) {
          end = end->next;
        }
        
        return head;
    }
};

int main(int argc, char** argv)
{
	cout<<"partition list"<<"\n";
	ListNode* test = new ListNode(1);
	ListNode *n1, *n2, *n3, *n4, *n5;
	n1 = new ListNode(1);
	n2 = new ListNode(2);
	n3 = new ListNode(3);
	n4 = new ListNode(4);
	n5 = new ListNode(5);
	

	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next = NULL;
	
	Solution sln;
	
	ListNode* res = sln.reverseBetween(n1, 2, 4);
	
	while (res != NULL) {
		cout<<"->"<<res->val<<"";
		res = res->next;
	}
	cout<<"\n";

	return 0;
	
}

