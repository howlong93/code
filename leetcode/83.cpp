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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head, *new_head = nullptr, *tmp = nullptr,
                 *new_end = nullptr;
        while (cur != nullptr) {
            tmp = new (ListNode);
            if (new_head == nullptr) {
                new_head = tmp;
                new_end = tmp;
            }
            tmp->val = cur->val;
            if (new_end != nullptr && tmp->val != new_end->val) {
                new_end->next = tmp;
                new_end = tmp;
            }
            cur = cur->next;
        }

        return new_head;
    }
};
