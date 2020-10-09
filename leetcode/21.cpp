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
    vector<int> data;
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        readdata(l1);
        readdata(l2);

        sort(data.begin(), data.end());

        ListNode *head = nullptr;
        return build(head);
    }

    void readdata(ListNode *list) {
        while (list != nullptr) {
            data.emplace_back(list->val);
            list = list->next;
        }
    }

    ListNode *build(ListNode *head) {
        ListNode *tmp;
        for (int i = data.size() - 1; i >= 0; i--) {
            tmp = new (ListNode);
            tmp->next = head;
            tmp->val = data[i];
            head = tmp;
        }

        return head;
    }
};
