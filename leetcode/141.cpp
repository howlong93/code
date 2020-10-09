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
    bool hasCycle(ListNode *head) {
        set<ListNode *> data;
        ListNode *cur = head;

        while (cur != nullptr) {
            if (data.find(cur) != data.end()) return true;
            data.emplace(cur);
            cur = cur->next;
        }

        return false;
    }
};
