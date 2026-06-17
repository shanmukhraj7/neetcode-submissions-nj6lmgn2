/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        // Step 1 : Duplicate the values
        Node* cur = head;
        while(cur){
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = cur->next->next;
        }
        // Step 2 : Assign Random to duplicated values
        cur = head;
        while(cur){
            if(cur->random){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // Step 3 : Seperate the original and duplicated
        Node* dummy = new Node(0);
        Node* tail = dummy;
        cur = head;
        while(cur){
            Node* copy = cur->next;
            cur->next = copy->next;
            tail->next = copy;
            tail = copy;
            cur = cur->next;
        }
        return dummy->next;
    }
};
