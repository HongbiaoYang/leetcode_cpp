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
    ListNode *deleteDuplicates(ListNode *head) {
 
   std::map<int, int> dmap;

        ListNode* tmp = head;
        if (head == NULL)  {
            return NULL;
        }
        
        while (tmp != NULL) {
                dmap[tmp->val]++;
                tmp = tmp->next;
        }

        // if head is duplicate
        while (head != NULL && dmap[head->val] > 1) {
                head = head->next;
        }

        if (head == NULL) {
                return NULL;
        }

        
        ListNode* prev = head;
        tmp = head->next;
        
        if (tmp == NULL) {
            return head;
        }
        
        while (tmp != NULL) {
            if (dmap[tmp->val] > 1) {
                prev->next = tmp->next;
                tmp = prev->next;
            }
            else {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        
   
   

        return head;
    }
       
};

int main(int argc, char** argv)
{
	cout<<"remove duplicate"<<"\n";
	ListNode* test = new ListNode(1);
	ListNode *n1, *n2, *n3, *n4, *n5, *n6, *n7;
	n1 = new ListNode(1);
	n2 = new ListNode(2);
	n3 = new ListNode(3);
	n4 = new ListNode(3);
	n5 = new ListNode(4);
	n6 = new ListNode(4);
	n7 = new ListNode(5);
	test->next=n1;
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	n6->next=n7;
	n7->next=NULL;
	
	Solution sln;
	
	ListNode* res = sln.deleteDuplicates(test);
	
	while (res != NULL) {
		cout<<"->"<<res->val<<"";
		res = res->next;
	}


	return 0;
	
}

