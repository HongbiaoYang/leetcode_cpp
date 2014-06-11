#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using std::cout;
using std::vector;


//Definition for singly-linked list.
  struct myListNode {
      int key;
      int value;
      int weight;
      myListNode *next;
      myListNode(int k, int v) : key(k), value(v), weight(0), next(NULL) {}
 };

class LRUCache{
public:

    int Cap;
    int Taken;
    int gWeight;
    myListNode* head;	

    LRUCache(int capacity) {
        Cap = capacity;
	head = NULL;
	Taken = 0;
	gWeight = 0;
    }
    
    int get(int key) {

	int t = Taken;
	myListNode* tmp;
	
	tmp = head;	

	while (t > 0) {
		if (tmp->key == key) {
			tmp->weight = gWeight++;
			return tmp->value;
		} else {
			tmp = tmp->next;
			t--;
		}
	}

	return -1;
    }
    
    void set(int key, int value) {
	
	myListNode *tmp, *last; 
	int t;

	if (Taken == 0) {
		head = new myListNode(key, value);
		head->weight = gWeight++;
		head->next = head;
		Taken = 1;
	} else {

		t = Taken;
		tmp = head;

		while (t > 0) {
			if (tmp->key == key) {
				tmp->value = value;
				tmp->weight = gWeight++;
				return;
			} else {
				last = tmp;
				tmp = tmp->next;
				t--;
				
			}
		}
		
		// insert
		if (Taken < Cap) {
			last->next = new myListNode(key, value);
			last->next->weight = gWeight++;
			last->next->next = head;				

			Taken ++;
		} else {	// update
			tmp = head;
			int min, i;
			min = gWeight + 1;


			for (i = 0; i < Cap; i++) {
				if (tmp->weight < min) {
					min = tmp->weight;
				}	
				tmp = tmp->next;
			}
	
			for (i = 0; i < Cap; i++) {
				if (tmp->weight  == min) {
					tmp->value = value;
					tmp->key = key;
					tmp->weight = gWeight++;
					return;
				} else {	
					tmp = tmp->next;
				}
			}
	

		}


	}

   
    }
};


int main(int argc, char** argv)
{
	cout<<"LRU cache"<<"\n";

	int rs;
	LRUCache c (2);
	
	c.set(2,1);
	c.set(1,1);
	cout<<"get2:"<< c.get(2)<<"\n";
	c.set(4,1);
	cout<<"get1:"<< c.get(1)<<"\n";
	cout<<"get2:"<< c.get(2)<<"\n";

	cout<<rs<<"\n";


	return 0;
	
}

