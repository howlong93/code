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
    ListNode* sortList(ListNode* head) {
        ListNode *root = nullptr, *tmp = nullptr;
        vector<int> save;
        while (head != nullptr) {
            save.emplace_back (head -> val);
            head = head -> next;
        }
        
        sort (save.begin(), save.end(), [] (int a, int b) { return a > b; });
        for (size_t i = 0; i < save.size(); i++) {
            tmp = new (ListNode);
            tmp -> val = save[i];
            tmp -> next = root;
            root = tmp;
        }
        
        return root;
    }
};
