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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = nullptr, *right = nullptr;
        ListNode *temp = head, *lcur = nullptr, *rcur = nullptr;
        
        while (temp != nullptr) {
            if (temp -> val < x) {
                if (left == nullptr) {
                    lcur = new ListNode (temp -> val);
                    left = lcur;
                }
                else lcur -> next = new ListNode(temp -> val), lcur = lcur -> next;
            }
            else {
                if (right == nullptr) {
                    rcur = new ListNode (temp -> val);
                    right = rcur;
                }
                else rcur -> next = new ListNode(temp -> val), rcur = rcur -> next;
            }
            
            temp = temp -> next;
        }
      
        if (left != nullptr){
            lcur -> next = right;
            return left;
        }
        
        return right;
    }
};
