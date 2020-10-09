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
    ListNode* reverseList(ListNode* head) {
        ListNode *tmp, *cur = head, *newhead = nullptr;
        while (cur != nullptr) {
            tmp = new (ListNode);
            tmp->val = cur->val;
            tmp->next = newhead;
            newhead = tmp;
            cur = cur->next;
        }

        return newhead;
    }
};
