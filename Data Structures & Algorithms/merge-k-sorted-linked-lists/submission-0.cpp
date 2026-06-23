/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwo(ListNode* first, ListNode* second){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(first && second){
            if(first->val < second->val){
                curr->next = first;
                first = first->next;
            }
            else{
                curr->next = second;
                second = second->next;
            }
            curr = curr->next;
        }
        if(first) curr->next = first;
        else curr->next = second;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* merged = lists[0];
        for(int i = 1; i < lists.size(); i++){
            merged = mergeTwo(merged, lists[i]);
        }
        return merged;
    }
};
